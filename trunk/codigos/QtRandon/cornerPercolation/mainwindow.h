#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QtGui/QMainWindow>
#include "pathviewer.h"

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

    PathViewer *viewer;

    Path path;
};

#endif // MAINWINDOW_H
