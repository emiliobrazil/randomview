#include "mainwindow.h"
#include "drawarea.h"

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("&Quit"));
    quit->setFont(QFont("Times", 10, QFont::Bold));

    connect(ui.quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{

}
