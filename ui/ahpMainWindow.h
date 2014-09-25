#ifndef AHPMAINWINDOW_H
#define AHPMAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "libahp.h"

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
  
private slots:
  void cAddSubmitTriggered();
  
  
private:
  Ui::AHPMainWindow *ui;
  vector<Criterion*> criteria;
};

#endif // AHPMAINWINDOW_H
