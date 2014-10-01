#ifndef VIEW_H
#define VIEW_H

#include "controler.h"
#include "mainwindow.h"
class Controler;
class MainWindow;

class View
{
public:
    View();
    void start();
    void set_controler(Controler *controler);
private:
    MainWindow * main_window;
    Controler * controler;
//    WindowOrganizer * window_organizer;

};

#endif // VIEW_H
