#ifndef CRITERIONLISTMODEL_H
#define	CRITERIONLISTMODEL_H

#include <QAbstractTableModel>
#include "libahp.h"

class CriterionListModel : public QAbstractTableModel {
  Q_OBJECT
  
private:
  AHPSet& ahpSet;
  
public:
  CriterionListModel(AHPSet& ahpSet, QObject* parent);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
  Qt::ItemFlags flags(const QModelIndex & index) const ;
  
  vector<Criterion*>& getCriteria();
  Mat& getCriteriaRating();
};

#endif	/* CRITERIONLISTMODEL_H */

