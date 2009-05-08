#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_interface.h"
#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( void );
    ~MainWindow();

private:
    Ui::MainWindow ui;

};

#endif // MAINWINDOW_H
