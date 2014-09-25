#include "ahpMainWindow.h"
#include "ui_ahpMainWindow.h"
#include <iostream>

AHPMainWindow::AHPMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AHPMainWindow) {
  ui->setupUi(this);
}

AHPMainWindow::~AHPMainWindow() {
  delete ui;
}

void AHPMainWindow::cAddSubmitTriggered() {
  this->criteria.push_back(new Criterion(ui->cAddName->text().toStdString()));
  this->cListChanged();
}
