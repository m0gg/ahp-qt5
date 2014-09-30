#include "RateItem.h"

RateItem::RateItem(QWidget* parent) : QItemDelegate(parent) {
}

QWidget* RateItem::createEditor(QWidget* parent, const QStyleOptionViewItem& /*option*/, const QModelIndex& /*index*/) const {
  QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
  editor->setMinimum(0.01);
  editor->setMaximum(100);
  editor->setSingleStep(1);
  
  return editor;
}

void RateItem::setEditorData(QWidget* editor, const QModelIndex& index) const {
  QDoubleSpinBox *box = static_cast<QDoubleSpinBox*>(editor);
  CriterionListModel *model = (CriterionListModel*)(index.model());
  box->setValue(model->data(index, Qt::EditRole).toDouble());
}

void RateItem::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {
  QDoubleSpinBox *box = static_cast<QDoubleSpinBox*>(editor);
  CriterionListModel *listModel = (CriterionListModel*)model;
  listModel->setData(index, box->value(), Qt::EditRole);
}
