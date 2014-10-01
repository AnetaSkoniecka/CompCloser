#include "controler.h"
#include <iostream>
#include <string.h>

Controler::Controler(Model * model, View * view)
{
    this->model = model;
    this->view = view;
    this->view->set_controler(this);
    this->view->start();
}

void Controler::shutdown_command(int time)
{
    std::string str;
    str = "shutdown -s -t " ;
    str += std::to_string(time) ;
    system(str.c_str());
}

QTime Controler::from_int_to_qtime(int time_int)
{
    int hours, minutes, seconds;
    hours = time_int / 3600;
    time_int -= hours * 3600;
    minutes = time_int / 60;
    time_int -= minutes * 60;
    seconds = time_int;
    return QTime(hours, minutes, seconds);
}
