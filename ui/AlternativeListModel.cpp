#include "AlternativeListModel.h"
#include <QDebug>

AlternativeListModel::AlternativeListModel(AHPSet& ahpSet, QObject* parent)
  : QAbstractTableModel(parent), ahpSet(ahpSet) {
}

int AlternativeListModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getAlternatives().size();
}

int AlternativeListModel::columnCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getCriteria().size();
}

QVariant AlternativeListModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if(role == Qt::DisplayRole) {
    switch(orientation) {
      case Qt::Vertical:
        return QString::fromStdString(this->ahpSet.getAlternatives()[section]->getName());
        break;
      case Qt::Horizontal:
        return QString::fromStdString(this->ahpSet.getCriteria()[section]->getName());
        break;
    }
  }
  return QVariant();
}

QVariant AlternativeListModel::data(const QModelIndex& index, int role) const {
  double rating = this->ahpSet.getAlternatives()[index.row()]->getCriteriaRating()[index.column()];
  switch(role) {
    case Qt::DisplayRole:
      return QString("%1").arg(rating);
      break;
    case Qt::EditRole:
      return rating;
  }
  return QVariant();
}

bool AlternativeListModel::setData(const QModelIndex& index, const QVariant& value, int role) {
  if(role == Qt::EditRole) {
    this->ahpSet.getAlternatives()[index.row()]->getCriteriaRating()[index.column()] = value.toDouble();
    
    QModelIndex t = createIndex(index.column(), index.row());
    emit dataChanged(t, t);
  }
  return true;
}

Qt::ItemFlags AlternativeListModel::flags(const QModelIndex& /*index*/) const {
  return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
}


