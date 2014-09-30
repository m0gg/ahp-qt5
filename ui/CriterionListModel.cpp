#include "CriterionListModel.h"
#include <QDebug>

CriterionListModel::CriterionListModel(AHPSet& ahpSet, QObject* parent) 
  : QAbstractTableModel(parent), ahpSet(ahpSet) {
}

int CriterionListModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getCriteria().size();
}

int CriterionListModel::columnCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getCriteria().size();
}

QVariant CriterionListModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const {
  if(role == Qt::DisplayRole) {
    return QString::fromStdString(this->ahpSet.getCriteria()[section]->getName());
  }
  return QVariant();
}

QVariant CriterionListModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->ahpSet.getCriteriaRating().get(index.row(), index.column()));
  }
  return QVariant();
}

vector<Criterion*>& CriterionListModel::getCriteria() {
  return this->ahpSet.getCriteria();
}

Mat& CriterionListModel::getCriteriaRating() {
  return this->ahpSet.getCriteriaRating();
}

bool CriterionListModel::setData(const QModelIndex& index, const QVariant& value, int role) {
  if(role == Qt::EditRole) {
    this->ahpSet.getCriteriaRating().set(index.row(), index.column(), value.toDouble());
    if(index.row() != index.column()) {
      this->ahpSet.getCriteriaRating().set(index.column(), index.row(), 1.0/value.toDouble());
    }
  }
  QModelIndex t = createIndex(index.column(), index.row());
  emit dataChanged(t, t);
  return true;
}

Qt::ItemFlags CriterionListModel::flags(const QModelIndex& index) const {
  if(index.row() != index.column()) {
    return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
  } else return Qt::ItemIsSelectable;
}
