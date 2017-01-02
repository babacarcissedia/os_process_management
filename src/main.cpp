#include "fenetreacceuil.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenetreAcceuil w;
    w.show();

    return a.exec();
}
