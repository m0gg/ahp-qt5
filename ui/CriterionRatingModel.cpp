#include "CriterionRatingModel.h"

CriterionRatingModel::CriterionRatingModel(QObject* parent) : QAbstractTableModel(parent) {

}

int CriterionRatingModel::rowCount(const QModelIndex& /*parent*/) const {
  return this->ratings.size();
}

int CriterionRatingModel::columnCount(const QModelIndex& /*parent*/) const {
  return 1;
}

Qt::ItemFlags CriterionRatingModel::flags(const QModelIndex& /*index*/) const {
  return Qt::ItemIsSelectable;
}

void CriterionRatingModel::setRatings(vector<double> ratings) {
  this->ratings = ratings;
}

vector<double> CriterionRatingModel::getRatings() const {
  return ratings;
}

QVariant CriterionRatingModel::headerData(int /*section*/, Qt::Orientation /*orientation*/, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("Rating");
  }
  return QVariant();
}

QVariant CriterionRatingModel::data(const QModelIndex& index, int role) const {
  if(role == Qt::DisplayRole) {
    return QString("%1").arg(this->ratings[index.row()]);
  }
  return QVariant();
}