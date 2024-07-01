#include "myglwidget.h"
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;

    MYGLWidget * w = new MYGLWidget;
    window.setCentralWidget(w);
    window.resize(800,600);
    window.show();
    return a.exec();
}
