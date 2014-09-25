#ifndef AHP_H
#define AHP_H

#include <QtWidgets/QMainWindow>

namespace Ui {
class AHP;
}

class AHP : public QMainWindow
{
    Q_OBJECT

public:
    explicit AHP(QWidget *parent = 0);
    ~AHP();

private:
    Ui::AHP *ui;
};

#endif // AHP_H
