#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"

AHPMainWindow::AHPMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AHPMainWindow) {
  ui->setupUi(this);
  CriterionRateItem *delegate = new CriterionRateItem(parent);
  ui->cTableView->setItemDelegate(delegate);
  this->criteriaModel = new CriterionListModel(0);
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
  ui->cTableView->setModel(0);
  ui->cTableView->setModel(this->criteriaModel);
  ui->cTableView->show();
}
