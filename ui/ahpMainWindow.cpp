#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include <qt5/QtCore/qdebug.h>

AHPMainWindow::AHPMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AHPMainWindow) {
  ui->setupUi(this);
  this->criteriaModel = new CriterionListModel(0);
  this->criteriaModel->setCriteria(&this->criteria);
  QObject::connect(this, SIGNAL(cListChanged()), this, SLOT(cListChangedReact()));
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  Criterion *newC = new Criterion(ui->cAddName->text().toStdString());
  this->criteria.push_back(newC);
  this->cListChanged();
}

void AHPMainWindow::cListChangedReact() {
  ui->cTableView->setModel(0);
  ui->cTableView->setModel(this->criteriaModel);
  ui->cTableView->show();
}

CriterionListModel::CriterionListModel(QObject* parent) : QAbstractTableModel(parent) {
  
}

int CriterionListModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->criteria->size();
}

int CriterionListModel::columnCount(const QModelIndex& /*parent*/) const {
  return this->criteria->size();
}

QVariant CriterionListModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const {
  if(role == Qt::DisplayRole) {
    return QString::fromStdString(this->criteria->at(section)->getName());
  }
  return QVariant();
}

QVariant CriterionListModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() +1);
  }
  return QVariant();
}

vector<Criterion*>* CriterionListModel::getCriteria() const {
  return this->criteria;
}

void CriterionListModel::setCriteria(vector<Criterion*>* criteria) {
  this->criteria = criteria;
}

