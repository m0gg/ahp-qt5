#ifndef ALTERNATIVELISTMODEL_H
#define	ALTERNATIVELISTMODEL_H

#include <QAbstractTableModel>
#include "libahp.h"

class AlternativeListModel : public QAbstractTableModel {
  Q_OBJECT

private:
  AHPSet& ahpSet;
  
public:
  AlternativeListModel(AHPSet& ahpSet, QObject* parent = 0);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex & index) const ;
  
};

#endif	/* ALTERNATIVELISTMODEL_H */

