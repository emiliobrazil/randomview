#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSimple w;
    w.show();
    return a.exec();
}
