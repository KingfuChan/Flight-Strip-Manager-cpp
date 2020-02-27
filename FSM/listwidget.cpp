#include "listwidget.h"

#include <QListWidget>
#include <QListWidgetItem>
#include <QPoint>
#include <QDropEvent>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QDebug>


QBrush brush_b_def = QBrush(QColor(255,255,255),Qt::NoBrush);
QBrush brush_b_clr = QBrush(QColor(0,170,0));
QBrush brush_b_tit = QBrush(QColor(0,0,0));
QBrush brush_f_def = QBrush(QColor(0,0,0),Qt::NoBrush);
QBrush brush_f_clr = QBrush(QColor(255,255,255),Qt::NoBrush);
QBrush brush_f_tit = QBrush(QColor(255,255,255),Qt::NoBrush);


CustomListWidget::CustomListWidget(QWidget *parent)
    :QListWidget(parent)
{
    QObject::connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(showContext(QPoint)));
}

CustomListWidget::~CustomListWidget(){

}

void CustomListWidget::dropEvent(QDropEvent *event){
    int row = currentRow(), i, bc, ac;

    //scan list before event
    bc = count();
    QString *before = new QString [bc];
    for (i=0;i<bc;i++)
        before[i] = item(i)->text();

    //event accept
    QListWidget::dropEvent(event);

    //scan list after event
    ac = count();
    QString *after = new QString [ac];
    for (i=0;i<ac;i++)
        after[i] = item(i)->text();

    QListWidgetItem *temp;
    if (bc==ac)
    {   //drag&drop in same list
        if (before[0]!=after[0])
        {
            temp = takeItem(0);
            insertItem(row,temp);
        }
    }
    else{   //drag&drop between different list
        for (i=0; i<bc && before[i]==after[i]; i++); //locate insert row
        temp = takeItem(i);
        temp->setBackground(brush_b_def);
        temp->setForeground(brush_f_def);
        addItem(temp);
    }

    clearSelection();
    delete [] before;
    delete [] after;
}

void CustomListWidget::enterEvent(QEvent *event){
    QListWidget::enterEvent(event);
    clearSelection();
}

void CustomListWidget::showContext(QPoint pos){
    int r,i,seq;
    r = row(itemAt(pos));
    if (r<=0) return; //clicked on title

    //calculate sequence
    if(item(r)->background()==brush_b_clr)
        seq = 0;
    else
        for (i=seq=1;i<r;i++)
            if (item(i)->background()==brush_b_def)
                seq++;

    //add menu actions
    QMenu *popMenu = new QMenu(this);
    QAction *actionSeq = new QAction;
    QAction *actionRes = new QAction;
    QAction *actionDel = new QAction;
    actionSeq->setText(QString("Seq: %1").arg(seq));
    actionSeq->setEnabled(0);
    popMenu->addAction(actionSeq);
    popMenu->addSeparator();
    actionRes->setText("Reset");
    popMenu->addAction(actionRes);
    actionDel->setText("Delete");
    popMenu->addAction(actionDel);
    QCursor curPos;
    QAction *choice = popMenu->exec(curPos.pos());
    if (choice==actionRes){
        QListWidgetItem *temp;
        temp = takeItem(r);
        temp->setBackground(brush_b_def);
        temp->setForeground(brush_f_def);
        emit resetItem(temp);
    }
    else if (choice==actionDel)
        delete item(r);

    delete popMenu;
    delete actionSeq;
    delete actionRes;
    delete actionDel;

}
