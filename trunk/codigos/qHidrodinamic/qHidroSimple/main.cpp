#include <QtGui/QApplication>
#include "particleshow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParticleShow w;
    w.show();
    return a.exec();
}
