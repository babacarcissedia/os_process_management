#include "ordonnanceur.h"
#include "fenetreacceuil.h"
#include "ui_ordonnanceur.h"
#include<QGraphicsItem>
//#include<QBrush>

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
Ordonnanceur::Ordonnanceur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ordonnanceur)
{

    //initialiser le tableau de processus
    ui->setupUi(this);
    gantt=new Gantt();
    gantt->on_Ajouter_clicked();

}

Ordonnanceur::~Ordonnanceur()
{
    delete ui;

}

void Ordonnanceur::init(){
    gantt=new Gantt();
    gantt->initialiser(this);

}
void Ordonnanceur::showProcessStat(){

    scene.setBackgroundBrush(Qt::white);
    scene.setSceneRect(QRect(0,0,700,500));
    QLine abs(50,50,50,450),ord(50,450,650,450);
    scene.addLine(abs);
    scene.addLine(ord);

    doFIFO();
    //doPCTE();
    switch ( method ){
        case METHOD_FIFO:
            break;
        case METHOD_PCTE:
            break;
        case METHOD_PCTER:
            break;
        case METHOD_TOURNIQUET:
            break;
        default:

    }

    ui->view->setScene(&scene);
    ui->view->setVisible(true);

}

void Ordonnanceur::setGant(){
    gantt=new Gantt();
    gantt->on_Ajouter_clicked();

}

void Ordonnanceur::doFIFO(){
   //QQueue<TabProcess> queue;
   /* gantt=new Gantt();
    gantt->on_Ajouter_clicked();*/
    qreal x1=50;

   for(int i=0;i<gantt->getNbrProcess();i++){

       TabProcess p=gantt->getProcessAt(i);
       qreal l=(qreal)p.process->getDuree();
       scene.addLine(x1,400-50*i,x1+l,400-50*i,QPen(Qt::green));
       scene.addText(p.process->getNom())->setPos(30,390-50*i);



        ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()+1);
       QTableWidgetItem *procesItem = new QTableWidgetItem(tr("%1").arg(p.process->getNom()));
       ui->tableWidget->setItem(0, i, procesItem);

       QTableWidgetItem *date = new QTableWidgetItem(tr("%1").arg((qreal)p.process->getDuree()));
       ui->tableWidget->setItem(1,i , date);




       for(int j=i+1;j<gantt->getNbrProcess();j++){
           if(j!=i){
               //TabProcess p=gantt->getProcessAt(j);

              scene.addLine(x1,400-50*j,x1+l,400-50*j,QPen(Qt::red));
           }
       }

       x1=x1+l;

   }

}

void Ordonnanceur::doPCTE(){

      TabProcess processus[100],p;

      for(int i=0;i<gantt->getNbrProcess();i++){
          processus[i]=gantt->getProcessAt(i);
          processus[i].altitude=400-50*i;
          for(int j=0;j<i;j++){
              if(processus[j].process->getDuree()>processus[i].process->getDuree() ){
                  p=processus[j];
                  processus[j]=processus[i];
                  processus[i]=p;
              }
          }

      }
      qreal x1=0;
      for(int i=0;i<gantt->getNbrProcess();i++){

          x1=x1+(qreal)processus[i].process->getDuree();
          scene.addLine(50+x1-(qreal)processus[i].process->getDuree(),processus[i].altitude,50+x1,processus[i].altitude,QPen(Qt::green));

          scene.addText(processus[i].process->getNom())->setPos(30,processus[i].altitude-10);



           ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()+1);
          QTableWidgetItem *procesItem = new QTableWidgetItem(tr("%1").arg(processus[i].process->getNom()));
          ui->tableWidget->setItem(0, i, procesItem);

          QTableWidgetItem *date = new QTableWidgetItem(tr("%1").arg(x1));
          ui->tableWidget->setItem(1,i , date);




          for(int j=i+1;j<gantt->getNbrProcess();j++){

                 scene.addLine(x1+50-(qreal)processus[i].process->getDuree(),processus[j].altitude,50+x1,processus[j].altitude,QPen(Qt::red));

          }

      }

}
/*
void Ordonnanceur::doPCTER(){

      TabProcess /*processus[100],p;
      vector<TabProcess> processus(100);
      vector<TabProcess>::iterator it;
      for(int i=0;i<gantt->getNbrProcess();i++){
          //processus.push_back(gantt->getProcessAt(i));
          p=gantt->getProcessAt(i);
          p.altitude=400-50*i;
          processus.push_back(p);

          sort(processus.begin(),processus.end(),[](TabProcess a,TabProcess b){

              return a.process->getSeqAt(0)<b.process->getSeqAt(0);

          } );
      }

      for(it=processus.begin();it!=processus.end();it++){

      }

}
*/
