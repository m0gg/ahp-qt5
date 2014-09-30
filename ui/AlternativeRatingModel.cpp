#include "AlternativeRatingModel.h"

AlternativeRatingModel::AlternativeRatingModel(AHPSet& ahpSet, QObject *parent) 
  : QAbstractTableModel(parent), ahpSet(ahpSet) {
}

int AlternativeRatingModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getAlternatives().size();
}

int AlternativeRatingModel::columnCount(const QModelIndex& /*parent*/) const {
  return 1;
}

Qt::ItemFlags AlternativeRatingModel::flags(const QModelIndex& /*index*/) const {
  return Qt::ItemIsSelectable;
}

QVariant AlternativeRatingModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if(role == Qt::DisplayRole) {
    switch(orientation) {
      case Qt::Vertical:
        return QString::fromStdString(this->ahpSet.getAlternatives()[section]->getName());
        break;
      case Qt::Horizontal:
        return QString("Rating");
        break;
    }
    
  }
  return QVariant();
}

QVariant AlternativeRatingModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->ahpSet.getAlternativesRatings()[index.row()]);
  }
  return QVariant();
}
