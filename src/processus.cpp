#include "processus.h"
#include "ui_processus.h"
#include "gantt.h"
#include <QMessageBox>
#include <QFile>
#include<QString>
#include<QTextStream>
Processus::Processus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Processus)
{
    ui->setupUi(this);
}
Processus::Processus(QString nom,int duree,int prio,int t[],int n,QWidget *parent):
           QWidget(parent), ui(new Ui::Processus)
{
      ui->setupUi(this);
      setNom(nom);
      setDuree(duree);
      setPriorite( prio);
      //setOneSeq( t,n);
      for(int i=0;i<n;i++){
          sequence[i]=t[i];
      }
      tailleSeq=n;

}
void Processus::setNom(QString nom){
   nomProcessus=nom;
}

void Processus::setDuree(int d){
     dureeExe=d;
}

void Processus::setPriorite(int p){
       priorite=p;
}

void Processus::setOrdonnee(qreal ord){
    if(ord<50||ord>450)ordonnee=-1;
    ordonnee=ord;

}
qreal Processus::getOrdonnee() const{
    return ordonnee;
}

QString Processus::getNom()const{
  return nomProcessus;
}

int Processus::getDuree()const{
     return dureeExe;
}

int Processus::getPriorite()const{
       return priorite;
}

Processus::~Processus()
{
    delete ui;
}

int Processus::getSeqAt(int n)const{
    return sequence[n];
}

void Processus::setSeqAt(int n,int value){
   sequence[n]=value;
}

int Processus::getSeqTaille()const{
    return tailleSeq;
}

void Processus::setSeqTaille(int n){
    tailleSeq=n;
}

void Processus::on_pushButton_clicked()
{
    QString text;
    QString nom=ui->lineNom->text();
    QString duree=ui->lineDuree ->text();
    QString priorite=ui->linePriorite->text();
    QString sequence=ui->lineSeq->text();
    text=nom+" "+duree+" "+priorite+" "+sequence+"\n";

    QFile fichier("C:/Users/sarr/Documents/Qt/ProjetSE/process.txt");


    if(fichier.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
        QTextStream flux(&fichier);
        flux<<text;
        fichier.close();
        QMessageBox::information(this,"succes","Processus ajouter");
    }
    else text="impossible d ouvrir le fichier";

    
}

Processus& Processus::operator =(const Processus& other){
    if(this!=&other){
        setNom(other.getNom());
        setDuree(other.getDuree());
        setPriorite(other.getPriorite());
        setSeqTaille(other.getSeqTaille());
        for(int i=0;i<getSeqTaille();i++){
            int n=other.getSeqAt(i);
             this->setSeqAt(i,n);
        }
    }
    return (*this);
}
