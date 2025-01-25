#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
     QApplication app(argc, argv);
     MainWindow mainWindow;
     mainWindow.resize(800, 600);
     mainWindow.setWindowTitle("Hello, World!");
     mainWindow.show();

     return app.exec();
}
