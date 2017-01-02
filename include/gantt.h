#ifndef GANTT_H
#define GANTT_H

#include <QWidget>
#include "processus.h"
#include<QAbstractItemModel>
#include<QTableWidget>

/*namespace Ui {
class Gantt;
}*/
typedef struct{
    Processus *process;
    //int setTime;
    qreal altitude;
}TabProcess;

class Gantt : public QWidget
{
    Q_OBJECT

public:
    explicit Gantt(QWidget *parent = 0);
    void addProcess(Processus *process);
    void initialiser(QWidget *p=0);
    int getNbrProcess();
    TabProcess getProcessAt(int i);
    QTableWidget* getTable();
    void on_Ajouter_clicked();
    ~Gantt();
private slots:

void cellSelected(int nRow, int nCol);

private:
    //Ui::Gantt *ui;
    int nbrProcess;
    TabProcess donnee[50];
    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader ;
};

#endif // GANTT_H
