#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::cout<<"hello\n";
    ui->setupUi(this);
    timer = new QTimer(this);
    control_layout = (QVBoxLayout *)ui->control_panel->layout();
    action_layout = (QVBoxLayout *)ui->action_panel->layout();
    lay1 = (QVBoxLayout *)ui->lay1->layout();
    lay2 = (QVBoxLayout *)ui->lay2->layout();
    prepare_widgets();
    add_widgets();
    hide_all();
    set_mockup2();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prepare_widgets()
{
    std::cout << "prepare widgets\n";
     to_mockup1a.setText("Close computer at time.");
     to_mockup1b.setText("Close computer after time.");
     to_mockup1c.setText("Go to scheduler.");
     to_mockup1c.setFlat(true);
     to_mockup1b.setFlat(true);
     to_mockup1a.setFlat(true);
     to_mockup2.setText("Close computer at");
     to_mockup3.setText("Close computer after");
     to_mockup4.setText("The closing will be executed in");
     text_time1.setText("hours");
     text_time2.setText("minutes");
     text_time3.setText("seconds");
     hours.setText("0");
     minutes.setText("0");
     seconds.setText("0");
     action_button.setText("Add to scheduler");
     back_button.setText("Back");

     QFont font;
     font.setBold(true);
     font.setPointSize(12);
     hours.setFont(font);
     minutes.setFont(font);
     seconds.setFont(font);

     to_mockup4.setAlignment(Qt::AlignCenter);

     connect(&to_mockup1a, SIGNAL(released()), this, SLOT(to_mockup1a_clicked()));
     connect(&to_mockup1b, SIGNAL(released()), this, SLOT(to_mockup1b_clicked()));
     connect(&to_mockup1c, SIGNAL(released()), this, SLOT(to_mockup1c_clicked()));
     connect(&action_button, SIGNAL(released()), this, SLOT(action_button_clicked()));
     connect(&back_button, SIGNAL(released()), this, SLOT(back_button_clicked()));
     connect(timer, SIGNAL(timeout()), this, SLOT(update_time_labels()));

}

void MainWindow::add_widgets()
{
    control_layout->addWidget(&to_mockup1a);
    control_layout->addWidget(&to_mockup1b);
    control_layout->addWidget(&to_mockup1c);

    lay1->addWidget(&to_mockup2);
    lay2->addWidget(&time_edit);
    lay2->addWidget(&text_time1);

    control_layout->addWidget(&to_mockup3);


    //tu trzeba ustawic kolejnosc
    lay1->addWidget(&to_mockup4);
    lay2->addWidget(&hours);
    lay2->addWidget(&text_time1);
    lay2->addWidget(&minutes);
    lay2->addWidget(&text_time2);
    lay2->addWidget(&seconds);
    lay2->addWidget(&text_time3);

    action_layout->addWidget(&action_button);
    action_layout->addWidget(&back_button);
}

void MainWindow::hide_all()
{
    to_mockup1a.hide();
    to_mockup1b.hide();
    to_mockup1c.hide();
    to_mockup2.hide();
    to_mockup3.hide();
    to_mockup4.hide();
    text_time3.hide();
    text_time2.hide();
    text_time1.hide();
    hours.hide();
    minutes.hide();
    seconds.hide();
    time_edit.hide();
    text_time1.hide();
    action_button.hide();
    back_button.hide();
}



void MainWindow::set_mockup1()
{
    std::cout << "setmockup1\n";
    current_panel = mockup1;
    to_mockup1a.show();
    to_mockup1b.show();
    to_mockup1c.show();

}

void MainWindow::set_mockup2()
{
    std::cout << "setmockup2\n";
    current_panel = mockup2;
    to_mockup2.show();
    time_edit.show();
    action_button.show();
}

void MainWindow::set_mockup3()
{
    std::cout << "setmockup3\n";
    current_panel = mockup3;
    to_mockup3.show();

    action_button.show();
    back_button.show();
}

void MainWindow::set_mockup4()
{
    std::cout << "setmockup4\n";
    current_panel = mockup4;
    to_mockup4.show();
    text_time3.show();
    text_time2.show();
    text_time1.show();
    hours.show();
    minutes.show();
    seconds.show();
    back_button.show();

}

void MainWindow::clear_mockup1()
{
    std::cout << "clearmockup1\n";
    to_mockup1a.hide();
    to_mockup1b.hide();
    to_mockup1c.hide();
}

void MainWindow::clear_mockup2()
{
    std::cout << "clearmockup2\n";
    action_button.hide();
    to_mockup2.hide();
    time_edit.hide();
}

void MainWindow::clear_mockup3()
{
    std::cout << "clearmockup3\n";
    to_mockup3.hide();
    text_time1.hide();
    time1.hide();
    text_time2.hide();
    time2.hide();
    text_time3.hide();
    time3.hide();
    action_button.hide();
    back_button.hide();
}

void MainWindow::clear_mockup4()
{
    std::cout << "clearmockup4\n";
    to_mockup4.hide();
    text_time3.hide();
    text_time2.hide();
    text_time1.hide();
    hours.hide();
    minutes.hide();
    seconds.hide();
    back_button.hide();
}

void MainWindow::to_mockup1a_clicked()
{
    std::cout << "1aclicked\n";
    set_mockup2();
    clear_mockup1();
}

void MainWindow::to_mockup1b_clicked()
{
    std::cout << "1bclicked\n";
    clear_mockup1();
    set_mockup3();
}

void MainWindow::to_mockup1c_clicked()
{
    std::cout << "1cclicked\n";
    clear_mockup1();
    set_mockup4();
}

void MainWindow::action_button_clicked()
{
    try
    {
        procces_action();
        if(current_panel == mockup2)
            clear_mockup2();
        if(current_panel == mockup3)
            clear_mockup3();
        set_mockup4();
    }
    catch(...)
    {
        /* do nothing */
    }
}

void MainWindow::back_button_clicked()
{
    if(current_panel == mockup2)
        clear_mockup2();
    if(current_panel == mockup3)
        clear_mockup3();
    if(current_panel == mockup4)
    {
        clear_mockup4();
        timer->stop();
    }
    set_mockup2();
}

void MainWindow::procces_action()
{
    if(controler!= NULL)
    {
        time_left = 0 ;
        if(current_panel == mockup2)
        {
            QTime current_time = QTime::currentTime();
            int time_aim_sec = time_edit.time().second() + time_edit.time().minute()*60
                    + time_edit.time().hour()*3600;
            int time_curr_sec = current_time.second() + current_time.minute()*60
                    + current_time.hour()*3600;
            if(time_aim_sec >= time_curr_sec)
                time_left = time_aim_sec - time_curr_sec;
            else
                time_left = time_aim_sec - time_curr_sec + 24*3600;
            set_time_labels(time_left);
        }
        else if(current_panel == mockup3)
        {
//            time_left =
        }
        if(time_left <= 0)
            throw "ponizej zakresu";
        timer->start(1000);
    }
}

void MainWindow::set_time_labels(int time_left)
{
    time_close = controler->from_int_to_qtime(time_left);
    hours.setText(QString::number(time_close.hour()));
    minutes.setText(QString::number(time_close.minute()));
    seconds.setText(QString::number(time_close.second()));
}

void MainWindow::update_time_labels()
{
    time_left -= 1;
    set_time_labels(time_left);
    if(time_left == 0)
    {
        timer->stop();
        controler->shutdown_command(10);
    }
}

void MainWindow::set_controler(Controler * controler)
{
    this->controler = controler;
}
