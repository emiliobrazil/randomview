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

    connect( ui.alphaSpinBox         , SIGNAL( valueChanged( double ) ) , this , SLOT( setAlpha( double ) ) );
    connect( ui.tSpinBox             , SIGNAL( valueChanged( double ) ) , this , SLOT( setT( double ) ) );
    connect( ui.numberOfSitesSpinBox , SIGNAL( valueChanged( int  ) ) , this , SLOT( setNunberOfSites( int )) );
    connect( ui.maxIterationSpinBox  , SIGNAL( valueChanged( int  ) ) , this , SLOT( setMaxIteration( int )) );

    connect( this , SIGNAL( sendIteration( int ) ) , ui.lcdNumber , SLOT( display ( int ) ) ) ;

    this->isPaused = false;
    this->isRuning = false;
    this->isReseted = true;

    this->t = ui.tSpinBox->value();
    this->alpha = ui.alphaSpinBox->value();
    this->numberOfSites = ui.numberOfSitesSpinBox->value();
    this->maxIteration = ui.maxIterationSpinBox->value();

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

    if(!isRuning)
    {
        ui.numberOfSitesSpinBox->setReadOnly( true );
        ui.maxIterationSpinBox->setReadOnly( true );
        ui.tSpinBox->setReadOnly( true );
        ui.alphaSpinBox->setReadOnly( true );
        ui.status_label->setText(tr("runing"));

        if( !this->isPaused )
        {
            this->numberOfIterations = 0;
            this->counter = ParticlesCounter( this->numberOfSites );
        }

        this->isPaused = false;
        this->isRuning = true;
        this->isReseted = false;
        while( ( !this->isPaused && !this->isReseted ) && ( this->numberOfIterations < this->maxIteration ) )
        {
            HidrodinamicsSystem system(  this->numberOfSites ,  this->t ,  this->alpha ,  this->function );
            counter += system.process();
            ++this->numberOfIterations;
            emit sendIteration( this->numberOfIterations + 1 );

            qApp->processEvents();
        }
    }

}

void MainWindow::reset( void )
{
    this->isPaused = false;
    this->isRuning = false;
    this->isReseted = true;

    ui.maxIterationSpinBox->setReadOnly( false );
    ui.tSpinBox->setReadOnly( false );
    ui.numberOfSitesSpinBox->setReadOnly( false );
    ui.alphaSpinBox->setReadOnly( false );
    ui.status_label->setText(tr("waiting"));

    this->numberOfIterations = 0;
    this->counter = ParticlesCounter( this->numberOfSites );
}

void MainWindow::setMaxIteration( int mI )
{
    this->maxIteration = mI;
}

void MainWindow::setNunberOfSites( int noS )
{
    this->numberOfSites = noS;
}

void MainWindow::setAlpha( double a )
{
    this->alpha = a;
}

void MainWindow::setT( double tl )
{
    this->t = tl;
}

