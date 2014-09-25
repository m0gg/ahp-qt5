#include "ui/ahpMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AHPMainWindow w;
    w.show();

    return a.exec();
}
