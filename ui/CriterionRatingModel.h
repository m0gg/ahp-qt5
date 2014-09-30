#ifndef CRITERIONRATINGMODEL_H
#define	CRITERIONRATINGMODEL_H

#include <QAbstractTableModel>
#include "libahp.h"

class CriterionRatingModel : public QAbstractTableModel {
  Q_OBJECT
  
private:
  AHPSet& ahpSet;
  vector<double> rating;
    
public:
  CriterionRatingModel(AHPSet& ahpSet, QObject *parent = 0);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex & index) const;
};

#endif	/* CRITERIONRATINGMODEL_H */

