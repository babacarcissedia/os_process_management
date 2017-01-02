#include "gantt.h"
#include "ui_gantt.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QTableWidget>
#include <QHeaderView>
#include <QDesktopWidget>
Gantt::Gantt(QWidget *parent) :
    QWidget(parent)/*,
    ui(new Ui::Gantt)*/
{
    //ui->setupUi(this);
    nbrProcess=0;
}

Gantt::~Gantt()
{
   // delete ui;
}

int Gantt::getNbrProcess(){
    return nbrProcess;
}
TabProcess Gantt::getProcessAt(int i){
    TabProcess tab;
    if(i<nbrProcess){ 
        //tab.setTime=donnee[i].setTime;
        tab.process=donnee[i].process;
    }
    return tab;
}

void Gantt::on_Ajouter_clicked()
{
    QFile fichier("C:/Users/sarr/Documents/Qt/ProjetSE/process.txt");
   QString text;
    if(fichier.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream flux(&fichier);
        while(!flux.atEnd()){
            text=flux.readLine();
            QString nom,sequence;
            int duree,priorite;
            nom=text.section(' ',0,0);
            duree=text.section(' ',1,1).toInt();
            priorite=text.section(' ',2,2).toInt();
            sequence=text.section(' ',3);
            int c=sequence.count(' ');
            int t[10],j;
            for(j=0;j<c;j++) t[j]=sequence.section(' ',3+j,3+j).toInt();
            Processus *process=new Processus(nom,duree,priorite,t,j);
            addProcess(process);
        }
        fichier.close();
    }


}

void Gantt::addProcess(Processus *process){
      donnee[nbrProcess].process=process;
      nbrProcess+=1;
}

void Gantt::initialiser(QWidget*p){
    m_pTableWidget = new QTableWidget(p);
    m_pTableWidget->setRowCount(0);
    m_pTableWidget->setColumnCount(5);
    m_TableHeader<<"#"<<"date"<<"Nom Processus"<<"Duree"<<"priorite";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection/*|QAbstractItemView::MultiSelection*/);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setFixedSize(500,200);

    //insert data
    m_pTableWidget->setRowCount(nbrProcess);
    int i;
    for(i=0;i<nbrProcess;i++){

        QTableWidgetItem *numero = new QTableWidgetItem(tr("%1").arg(i+1));
        m_pTableWidget->setItem(i, 0, numero);

       QTableWidgetItem *date = new QTableWidgetItem(tr("%1").arg(donnee[i].process->getSeqAt(0)));
       m_pTableWidget->setItem(i, 1, date);

       QTableWidgetItem *nom = new QTableWidgetItem(donnee[i].process->getNom());
       m_pTableWidget->setItem(i, 2, nom);

       QTableWidgetItem *duree = new QTableWidgetItem(tr("%1").arg(donnee[i].process->getDuree()));
       m_pTableWidget->setItem(i, 3, duree);

       QTableWidgetItem *priorite = new QTableWidgetItem(tr("%1").arg(donnee[i].process->getPriorite()));
       m_pTableWidget->setItem(i, 4, priorite);
    }


   connect( m_pTableWidget, SIGNAL( cellDoubleClicked (int, int) ),this, SLOT( cellSelected( int, int ) ) );


}

void Gantt::cellSelected(int nRow, int nCol)
{
 QMessageBox::information(this, " ","Cell at row "+QString::number(nRow)+" column "+QString::number(nCol)+ " was double clicked.");
}

QTableWidget* Gantt::getTable(){

    return m_pTableWidget;
}
