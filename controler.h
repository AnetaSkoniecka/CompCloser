#ifndef CONTROLER_H
#define CONTROLER_H
#include "view.h"
#include "model.h"
#include <QTime>

class Model;
class View;

class Controler
{
public:
    Controler(Model * model, View * view);
    void shutdown_command(int time);
    QTime from_int_to_qtime(int time_int);

private:
    View * view;
    Model * model;



};

#endif // CONTROLER_H
