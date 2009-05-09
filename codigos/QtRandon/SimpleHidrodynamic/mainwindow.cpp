#include "mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>

MainWindow::MainWindow( void )
{
    ui.setupUi(this);

    connect( ui.quitButton  , SIGNAL( clicked() ) , qApp , SLOT( quit () ) );
    connect( ui.pauseButton , SIGNAL( clicked() ) , this , SLOT( pause() ) );
    connect( ui.startButton , SIGNAL( clicked() ) , this , SLOT( start() ) );
    connect( ui.resetButton , SIGNAL( clicked() ) , this , SLOT( reset() ) );

    this->isPaused = false;
    this->isRuning = false;
    this->isReseted = true;

    this->t = ui.tSpinBox->value();
    this->alpha = ui.alphaSpinBox->value();
    this->numberOfPartices = ui.numberOfParticleSpinBox->value();

    ui.status_label->setText(tr("waiting"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::pause( void )
{
    if(isRuning)
    {
        ui.status_label->setText(tr("pause"));

        this->isPaused = true;
        this->isRuning = false;
        this->isReseted = false;
    }

}

void MainWindow::start( void )
{
    this->isPaused = false;
    this->isRuning = true;
    this->isReseted = false;

    ui.tSpinBox->setReadOnly( true );
    ui.numberOfParticleSpinBox->setReadOnly( true );
    ui.alphaSpinBox->setReadOnly( true );
    ui.status_label->setText(tr("runing"));

    uint32 teste = 0;
    while(!isPaused)
    {
        ++teste;
        std::cout << teste << " - " ;
    }


}

void MainWindow::reset( void )
{
    this->isPaused = false;
    this->isRuning = false;
    this->isReseted = true;
    ui.tSpinBox->setReadOnly( false );
    ui.numberOfParticleSpinBox->setReadOnly( false );
    ui.alphaSpinBox->setReadOnly( false );
    ui.status_label->setText(tr("waiting"));

}


