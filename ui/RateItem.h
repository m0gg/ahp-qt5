#ifndef CRITERIONRATEITEM_H
#define	CRITERIONRATEITEM_H

#include <QAbstractTableModel>
#include <QDoubleSpinBox>
#include <QStyleOptionViewItem>
#include <QItemDelegate>
#include "libahp.h"

#include "CriterionListModel.h"

class RateItem : public QItemDelegate {
  Q_OBJECT
public:
  RateItem(QWidget *parent = 0);
  
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  void setEditorData(QWidget *editor, const QModelIndex &index) const;
  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
  
private:
  
};

#endif	/* CRITERIONRATEITEM_H */

