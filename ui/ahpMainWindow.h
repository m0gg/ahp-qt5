#ifndef AHPMAINWINDOW_H
#define AHPMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "libahp.h"

#include <QAbstractTableModel>

using namespace std;

namespace Ui {
  class AHPMainWindow;
}
class CriterionListModel;

class AHPMainWindow : public QMainWindow {
  Q_OBJECT
  
public:
  explicit AHPMainWindow(QWidget *parent = 0);
  ~AHPMainWindow();
  
  void setCriteria(vector<Criterion*> criteria);
  vector<Criterion*> getCriteria() const;
  
signals:
  void cListChanged();
  
private slots:
  void cAddSubmitTriggered();
  void cListChangedReact();
  
  
private:
  Ui::AHPMainWindow *ui;
  vector<Criterion*> criteria;
  CriterionListModel *criteriaModel;
};

class CriterionListModel : public QAbstractTableModel {
  Q_OBJECT
  
private:
  vector<Criterion*> *criteria;
  
public:
  CriterionListModel(QObject *parent);
  int rowCount(const QModelIndex &parent = QModelIndex()) const ;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  
  void setCriteria(vector<Criterion*> *criteria);
  vector<Criterion*> *getCriteria() const;
};

#endif // AHPMAINWINDOW_H
