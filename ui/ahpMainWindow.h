#ifndef AHPMAINWINDOW_H
#define AHPMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "libahp.h"

#include "CriterionListModel.h"
#include "CriterionRateItem.h"
#include "CriterionRatingModel.h"

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
  void cListValueChanged();
  
private slots:
  void cAddSubmitTriggered();
  void cListChangedReact();
  void cListValueReact();
  void cSaveFile();
  void cLoadFile();
  void cSaveFileTo(QString);
  void cLoadFileFrom(QString);
  
  
private:
  Ui::AHPMainWindow *ui;
  vector<Criterion*> criteria;
  CriterionMat criteriaMat;
  CriterionListModel *criteriaModel;
  CriterionRatingModel *criteriaRatingModel;
};

#endif // AHPMAINWINDOW_H
