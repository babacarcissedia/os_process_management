#ifndef PROCESSUS_H
#define PROCESSUS_H

#include <QWidget>

namespace Ui {
class Processus;
}

class Processus : public QWidget
{
    Q_OBJECT

public:
    explicit Processus(QWidget *parent = 0);
    Processus(QString nom,int duree,int prio,int t[],int n,QWidget *parent=0);
    void setNom(QString nom);
    void setDuree(int d);
    void setPriorite(int p);
    void setSeqAt(int n,int value);
    void setSeqTaille(int n);
    void setOrdonnee(qreal ord);


    QString getNom()const;
    int getDuree()const;
    int getPriorite()const;
    int getSeqAt(int n)const;
    int getSeqTaille()const;

    qreal getOrdonnee()const;
    Processus& operator =(const Processus& pro);

    ~Processus();



private slots:
    void on_pushButton_clicked();

private:
    Ui::Processus *ui;
    QString nomProcessus;
    int dureeExe;
    int dureeExeRest;
    int priorite;
    int sequence[10];
    int tailleSeq;
    qreal ordonnee;
};

#endif // PROCESSUS_H
