#include "fenetre_acceuil.h"
#include "ui_fenetreacceuil.h"
#include "ordonnanceur.h"
#include "gantt.h"
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>
#include <QTextStream>
#include <QMessageBox>
#include<QTableWidget>
#include<QScrollArea>
FenetreAcceuil::FenetreAcceuil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreAcceuil)
{
    ui->setupUi(this);
}

FenetreAcceuil::~FenetreAcceuil()
{
    delete ui;
}

void FenetreAcceuil::on_actionAjouter_triggered()
{
    Processus *process=new Processus();
    process->setVisible(true);
    //setCentralWidget(process);

}

void FenetreAcceuil::on_actionOrdonnanceur_triggered()
{

  Ordonnanceur *ord=new Ordonnanceur(ui->centralWidget);
  ord->showProcessStat();
  ord->setVisible(true);
  ui->centralWidget->resize(ord->size());


}

void FenetreAcceuil::on_actionGantt_triggered()
{
    gantt=new Gantt();
    gantt->on_Ajouter_clicked();
    gantt->initialiser(/*ui->centralWidget*/);
    QTableWidget* tab;
    tab=gantt->getTable();

    tab->setVisible(true);
}
