#include "mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>

MainWindow::MainWindow( void )
{
    ui.setupUi(this);

    connect(ui.quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{

}
