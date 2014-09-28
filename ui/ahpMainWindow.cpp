#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include "AHPSet.h"

AHPMainWindow::AHPMainWindow(QWidget *parent) 
  : QMainWindow(parent), ui(new Ui::AHPMainWindow), 
    criteriaModel(this->set.getCriteria(), this->set.getCriteriaRating(), this),
    criteriaRatingModel(this) {
  
  ui->setupUi(this);
  CriterionRateItem *delegate = new CriterionRateItem(parent);
  ui->cTableView->setItemDelegate(delegate);
  this->criteriaModel.setCriteria(this->set.getCriteria());
  this->criteriaModel.setCriteriaMat(this->set.getCriteriaRating());
  QObject::connect(this, SIGNAL(cListChanged()), this, SLOT(cListChangedReact()));
  QObject::connect(&this->criteriaModel, SIGNAL(dataChanged()), this, SLOT(cListValueReact()));
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  Criterion newC(ui->cAddName->text().toStdString());
  this->set.getCriteria().push_back(newC);
  this->set.getCriteriaRating().push_back();
  this->cListChanged();
}

void AHPMainWindow::cListChangedReact() {
  ui->cTableView->setModel(NULL);
  ui->cTableView->setModel(&this->criteriaModel);
  ui->cTableView->show();
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
  AHPSet tmp(this->set.getCriteria(), this->set.getCriteriaRating());
  tmp.exportSet(path.toStdString());
}

void AHPMainWindow::cLoadFileFrom(QString path) {
  this->set = AHPSet(path.toStdString());
  emit cListChanged();
}
