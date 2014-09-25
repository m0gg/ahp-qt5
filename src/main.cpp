#include "ui/ahp.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AHP w;
    w.show();

    return a.exec();
}
