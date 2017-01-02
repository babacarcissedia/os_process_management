#ifndef FENETREACCEUIL_H
#define FENETREACCEUIL_H

#include <QMainWindow>
#include "ordonnanceur.h"
namespace Ui {
class FenetreAcceuil;
}

class FenetreAcceuil : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreAcceuil(QWidget *parent = 0);
    ~FenetreAcceuil();

private slots:
    void on_actionAjouter_triggered();

    void on_actionOrdonnanceur_triggered();


    void on_actionGantt_triggered();

private:
    Ui::FenetreAcceuil *ui;
    Ordonnanceur *ord;
    Gantt* gantt;
};

#endif // FENETREACCEUIL_H
