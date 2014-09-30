#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include <QDebug>

AHPMainWindow::AHPMainWindow(QWidget *parent) 
: QMainWindow(parent), ui(new Ui::AHPMainWindow), 
    criteriaModel(this->set, this),
    criteriaRatingModel(this->set, this),
    alternativesModel(this->set, this), 
    alternativesRatingModel(this->set, this) {
  
  ui->setupUi(this);
  RateItem *delegate = new RateItem(parent);
  ui->cTableView->setItemDelegate(delegate);
  ui->aTableView->setItemDelegate(delegate);
  
  ui->cTableView->setModel(&this->criteriaModel);
  ui->cValueTable->setModel(&this->criteriaRatingModel);
  ui->aTableView->setModel(&this->alternativesModel);
  ui->aValueTable->setModel(&this->alternativesRatingModel);
  
  QObject::connect(this, &AHPMainWindow::cListChanged, this, &AHPMainWindow::cListChangedReact);
  QObject::connect(this, &AHPMainWindow::aListChanged, this, &AHPMainWindow::aListChangedReact);
  QObject::connect(&this->criteriaModel, &CriterionListModel::dataChanged, this, &AHPMainWindow::cListChangedReact);
  QObject::connect(&this->alternativesModel, &AlternativeListModel::dataChanged, this, &AHPMainWindow::aListChangedReact);
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  this->set.addCriterion(ui->cAddName->text().toStdString());
  emit cListChanged();
}

void AHPMainWindow::aAddSubmitTriggered() {
  this->set.addAlternative(ui->aAddName->text().toStdString());
  emit aListChanged();
}


void AHPMainWindow::cListChangedReact() {
  this->set.recalcCriteriaRatings();
  ui->cTableView->setModel(NULL);
  ui->cValueTable->setModel(NULL);
  ui->cTableView->setModel(&this->criteriaModel);
  ui->cValueTable->setModel(&this->criteriaRatingModel);
  
  emit aListChanged();
}

void AHPMainWindow::aListChangedReact() {
  this->set.recalcAlternativesRatings();
  ui->aTableView->setModel(NULL);
  ui->aValueTable->setModel(NULL);
  ui->aTableView->setModel(&this->alternativesModel);
  ui->aValueTable->setModel(&this->alternativesRatingModel);
}

void AHPMainWindow::cSaveFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Speichern unter ..."), NULL, QString("data-file (*.dat)"));
  cSaveFileTo(path);
}

void AHPMainWindow::cLoadFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Datei laden ..."), NULL, NULL);
  cLoadFileFrom(path);
  
  emit cListChanged();
}

void AHPMainWindow::cSaveFileTo(QString path) {
  AHPSet tmp(this->set.getCriteria(), this->set.getAlternatives(), this->set.getCriteriaRating());
  tmp.exportSet(path.toStdString());
}

void AHPMainWindow::cLoadFileFrom(QString path) {
  this->set = AHPSet(path.toStdString());
  emit cListChanged();
}
