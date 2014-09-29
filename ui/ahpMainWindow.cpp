#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include <QDebug>

AHPMainWindow::AHPMainWindow(QWidget *parent) 
  : QMainWindow(parent), ui(new Ui::AHPMainWindow), 
    criteriaModel(this->set, this),
    alternativesModel(this->set, this), 
    criteriaRatingModel(this) {
  
  ui->setupUi(this);
  RateItem *delegate = new RateItem(parent);
  ui->cTableView->setItemDelegate(delegate);
  ui->aTableView->setItemDelegate(delegate);
  QObject::connect(this, SIGNAL(cListChanged()), this, SLOT(cListChangedReact()));
  QObject::connect(this, SIGNAL(aListChanged()), this, SLOT(aListChangedReact()));
  QObject::connect(&this->criteriaModel, SIGNAL(dataChanged()), this, SLOT(cListValueReact()));
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  this->set.addCriterion(ui->cAddName->text().toStdString());
  this->aListChangedReact();
  this->cListChangedReact();
  this->cListValueReact();
}

void AHPMainWindow::aAddSubmitTriggered() {
  this->set.addAlternative(ui->aAddName->text().toStdString());
  this->aListChangedReact();
  this->cListChangedReact();
  this->cListValueReact();
}


void AHPMainWindow::cListChangedReact() {
  ui->cTableView->setModel(NULL);
  ui->cTableView->setModel(&this->criteriaModel);
  ui->cTableView->show();
}

void AHPMainWindow::aListChangedReact() {
  ui->aTableView->setModel(NULL);
  ui->aTableView->setModel(&this->alternativesModel);
  ui->aTableView->show();
}

void AHPMainWindow::cListValueReact() {
  Mat& x = this->set.getCriteriaRating();
  vector<double> y = (x*x*x*x).getNormalizedEigenvalues();
  this->criteriaRatingModel.setRatings(y);
  ui->cValueTable->setModel(NULL);
  ui->cValueTable->setModel(&this->criteriaRatingModel);
  ui->cValueTable->show();
}

void AHPMainWindow::cSaveFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Speichern unter ..."), NULL, QString("data-file (*.dat)"));
  cSaveFileTo(path);
}

void AHPMainWindow::cLoadFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Datei laden ..."), NULL, NULL);
  cLoadFileFrom(path);
  cListValueReact();
}

void AHPMainWindow::cSaveFileTo(QString path) {
  AHPSet tmp(this->set.getCriteria(), this->set.getAlternatives(), this->set.getCriteriaRating());
  tmp.exportSet(path.toStdString());
}

void AHPMainWindow::cLoadFileFrom(QString path) {
  this->set = AHPSet(path.toStdString());
  emit cListChanged();
}
