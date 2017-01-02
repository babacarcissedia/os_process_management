#ifndef ORDONNANCEUR_H
#define ORDONNANCEUR_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsView>
#include "gantt.h"
#include <QTableView>
namespace Ui {
class Ordonnanceur;
}

class Ordonnanceur : public QWidget
{
    Q_OBJECT

public:
    explicit Ordonnanceur(QWidget *parent = 0);
    Ordonnanceur(QWidget *parent(),Gantt *gant);
    void setGant();
    void doPCTE();
    // void doPCTER();
    void init();
    void showProcessStat();
    void doFIFO();
    ~Ordonnanceur();
    static int METHOD_FIFO = 1;
    static int METHOD_PCTE = 2;
    static int METHOD_PCTER = 3;
    static int METHOD_TOURNIQUET = 4;

private:
    Ui::Ordonnanceur *ui;
    Gantt *gantt;
    QTableWidget *tabGantt;
    QStringList m_TableHeader;
    QGraphicsScene scene;
};

#endif // ORDONNANCEUR_H
