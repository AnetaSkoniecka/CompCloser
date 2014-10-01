#include "view.h"

View::View()
{
    main_window = new MainWindow();
}

void View::start()
{
    main_window->show();
}

void View::set_controler(Controler * controler)
{
    this->controler = controler;
    main_window->set_controler(controler);
}
