#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimeEdit>
#include <QTextEdit>
#include "controler.h"

class ControlPanel;
class Controler;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum CurrentPanel
    {
        mockup1, mockup2, mockup3, mockup4
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_controler(Controler * controler);

private slots: 
    void to_mockup1a_clicked();
    void to_mockup1b_clicked();
    void to_mockup1c_clicked();
    void action_button_clicked();
    void back_button_clicked();

    void update_time_labels();
private:
    int time_left;
    QTime time_close;
    QTimer * timer;
    Controler * controler;
    CurrentPanel current_panel;
    Ui::MainWindow *ui;
    ControlPanel * control;
    QVBoxLayout * control_layout, * action_layout, * lay1, * lay2;
    QPushButton to_mockup1a, to_mockup1b, to_mockup1c;
    QLabel to_mockup2, to_mockup3, to_mockup4;
    QLabel text_mockup, text_time1, text_time2, text_time3;
    QLabel hours, minutes, seconds;
    QTimeEdit time_edit;
    QTextEdit time1, time2, time3;
    QPushButton action_button, back_button;

    void set_mockup1();
    void set_mockup2();
    void set_mockup3();
    void set_mockup4();

    void clear_mockup1();
    void clear_mockup2();
    void clear_mockup3();
    void clear_mockup4();
    void prepare_widgets();
    void add_widgets();
    void hide_all();
    void procces_action();
    void set_time_labels(int time_left);
};

#endif // MAINWINDOW_H
