#include <iostream>
#include <QApplication>
#include "./ui_mainwindow.h"
#include "calcu.h"

void Calcu::plus() {

}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Calcu win(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&win);
    win.lineEdit = caller.lineEdit;
    win.show();
    return a.exec();
}
