#include "mainwindow.h"
#include "controler.h"
#include "model.h"
#include "view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model * model = new Model();
    View * view = new View();
    Controler * controler = new Controler(model, view);

    return a.exec();
}
