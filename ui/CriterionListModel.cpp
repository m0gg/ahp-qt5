#include "CriterionListModel.h"

CriterionListModel::CriterionListModel(vector<Criterion>& criteria, Mat& criteriaMat, QObject* parent) 
  : QAbstractTableModel(parent), criteria(criteria), criteriaMat(criteriaMat) {
}

int CriterionListModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->criteria.size();
}

int CriterionListModel::columnCount(const QModelIndex& /*parent*/) const {
  return this->criteria.size();
}

QVariant CriterionListModel::headerData(int section, Qt::Orientation /*orientation*/, int role) const {
  if(role == Qt::DisplayRole) {
    return QString::fromStdString(this->criteria.at(section).getName());
  }
  return QVariant();
}

QVariant CriterionListModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->criteriaMat.get(index.row(), index.column()));
  }
  return QVariant();
}

vector<Criterion>& CriterionListModel::getCriteria() {
  return this->criteria;
}

void CriterionListModel::setCriteria(vector<Criterion>& criteria) {
  this->criteria = criteria;
}

void CriterionListModel::setCriteriaMat(Mat& criteriaMat) {
  this->criteriaMat = criteriaMat;
}

Mat& CriterionListModel::getCriteriaMat() {
  return this->criteriaMat;
}

bool CriterionListModel::setData(const QModelIndex& index, const QVariant& value, int role) {
  if(role == Qt::EditRole) {
    //save value from editor to member m_gridData
    this->criteriaMat.set(index.row(), index.column(), value.toDouble());
    if(index.row() != index.column()) {
      this->criteriaMat.set(index.column(), index.row(), 1.0/value.toDouble());
    }
  }
  emit dataChanged();
  return true;
}

Qt::ItemFlags CriterionListModel::flags(const QModelIndex& index) const {
  if(index.row() != index.column()) {
    return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
  } else return Qt::ItemIsSelectable;
}
