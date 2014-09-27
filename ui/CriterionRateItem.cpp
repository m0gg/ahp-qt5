#include "CriterionRateItem.h"

CriterionRateItem::CriterionRateItem(QWidget* parent) : QItemDelegate(parent) {
}

QWidget* CriterionRateItem::createEditor(QWidget* parent, const QStyleOptionViewItem& /*option*/, const QModelIndex& /*index*/) const {
  QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
  editor->setMinimum(0.01);
  editor->setMaximum(100);
  editor->setSingleStep(1);
  
  return editor;
}

void CriterionRateItem::setEditorData(QWidget* editor, const QModelIndex& index) const {
  QDoubleSpinBox *box = static_cast<QDoubleSpinBox*>(editor);
  CriterionListModel *model = (CriterionListModel*)(index.model());
  box->setValue(model->getCriteriaMat()->get(index.row(), index.column()));
}

void CriterionRateItem::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const {
  QDoubleSpinBox *box = static_cast<QDoubleSpinBox*>(editor);
  CriterionListModel *listModel = (CriterionListModel*)model;
  listModel->setData(index, box->value(), Qt::EditRole);
}
