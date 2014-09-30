#include "CriterionRatingModel.h"

CriterionRatingModel::CriterionRatingModel(AHPSet& ahpSet, QObject *parent) 
: QAbstractTableModel(parent), ahpSet(ahpSet) {
}

int CriterionRatingModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->ahpSet.getCriteria().size();
}

int CriterionRatingModel::columnCount(const QModelIndex& /*parent*/) const {
  return 1;
}

Qt::ItemFlags CriterionRatingModel::flags(const QModelIndex& /*index*/) const {
  return Qt::ItemIsSelectable;
}

QVariant CriterionRatingModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if(role == Qt::DisplayRole) {
    switch(orientation) {
      case Qt::Vertical:
        return QString::fromStdString(this->ahpSet.getCriteria()[section]->getName());
        break;
      case Qt::Horizontal:
        return QString("Rating");
        break;
    }
    
  }
  return QVariant();
}

QVariant CriterionRatingModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->ahpSet.getCriteriaRatings()[index.row()]);
  }
  return QVariant();
}
