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
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->ahpSet.getAlternativesRating().get(index.row(), index.column()));
  }
  return QVariant();
}

bool AlternativeListModel::setData(const QModelIndex& index, const QVariant& value, int role) {
  if(role == Qt::EditRole) {
    this->ahpSet.getAlternativesRating().set(index.row(), index.column(), value.toDouble());
    if(index.row() != index.column()) {
      this->ahpSet.getAlternativesRating().set(index.column(), index.row(), 1.0/value.toDouble());
    }
  }
  //emit dataChanged();
  return true;
}

Qt::ItemFlags AlternativeListModel::flags(const QModelIndex& /*index*/) const {
  return Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled;
}


