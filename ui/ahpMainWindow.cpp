#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include <QDebug>

AHPMainWindow::AHPMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AHPMainWindow) {
  ui->setupUi(this);
  CriterionRateItem *delegate = new CriterionRateItem(parent);
  ui->cTableView->setItemDelegate(delegate);
  this->criteriaModel = new CriterionListModel(NULL);
  this->criteriaModel->setCriteria(&this->criteria);
  this->criteriaModel->setCriteriaMat(&this->criteriaMat);
  QObject::connect(this, SIGNAL(cListChanged()), this, SLOT(cListChangedReact()));
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  Criterion *newC = new Criterion(ui->cAddName->text().toStdString());
  this->criteria.push_back(newC);
  this->criteriaMat.push_back();
  this->cListChanged();
}

void AHPMainWindow::cListChangedReact() {
  ui->cTableView->setModel(NULL);
  ui->cTableView->setModel(this->criteriaModel);
  ui->cTableView->show();
}

void AHPMainWindow::cSaveFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Speichern unter ..."), NULL, QString("data-file (*.dat)"));
  cSaveFileTo(path);
}

void AHPMainWindow::cLoadFile() {
  QString path = QFileDialog::getOpenFileName(this, QString("Datei laden ..."), NULL, NULL);
  
}

void AHPMainWindow::cSaveFileTo(QString path) {
  CriterionSet tmp(&this->criteria, &this->criteriaMat);
  tmp.exportSet(path.toStdString());
}

void AHPMainWindow::cLoadFileFrom(QString path) {
  CriterionSet tmp(path.toStdString());
  this->criteria = *(tmp.getCriteria());
  this->criteriaMat = *(tmp.getCriteriaMat());
  emit cListChanged();
}
