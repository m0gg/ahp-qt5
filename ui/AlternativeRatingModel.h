#ifndef ALTERNATIVERATINGMODEL_H
#define	ALTERNATIVERATINGMODEL_H

#include <QAbstractTableModel>
#include "libahp.h"

class AlternativeRatingModel : public QAbstractTableModel {
  Q_OBJECT
  
private:
  AHPSet& ahpSet;
  vector<double> rating; 
  
public:
  AlternativeRatingModel();
  AlternativeRatingModel(AHPSet& ahpSet, QObject *parent = 0);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex & index) const;
};

#endif	/* ALTERNATIVERATINGMODEL_H */

