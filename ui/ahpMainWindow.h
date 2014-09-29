#ifndef AHPMAINWINDOW_H
#define AHPMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "libahp.h"

#include "RateItem.h"
#include "CriterionListModel.h"
#include "CriterionRatingModel.h"
#include "AlternativeListModel.h"

using namespace std;

namespace Ui {
  class AHPMainWindow;
}

class AHPMainWindow : public QMainWindow {
  Q_OBJECT
  
public:
  explicit AHPMainWindow(QWidget *parent = 0);
  ~AHPMainWindow();
  
  void setCriteria(vector<Criterion*> criteria);
  vector<Criterion*> getCriteria() const;
  
signals:
  void cListChanged();
  void aListChanged();
  void cListValueChanged();
  
private slots:
  void cAddSubmitTriggered();
  void aAddSubmitTriggered();
  void cListChangedReact();
  void aListChangedReact();
  void cListValueReact();
  void cSaveFile();
  void cLoadFile();
  void cSaveFileTo(QString);
  void cLoadFileFrom(QString);
  
  
private:
  Ui::AHPMainWindow *ui;
  AHPSet set;
  CriterionListModel criteriaModel;
  AlternativeListModel alternativesModel;
  CriterionRatingModel criteriaRatingModel;
};

#endif // AHPMAINWINDOW_H
