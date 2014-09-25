#include "ahp.h"
#include "ui_ahp.h"

AHP::AHP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AHP)
{
    ui->setupUi(this);
}

AHP::~AHP()
{
    delete ui;
}
