#include "tracker.h"
#include "listwidget.h"

#include <QListWidgetItem>
#include <QBrush>
#include <QString>

/*
Documentation about int status
0   standby for clearance
1   clearance received
2   standby for push
3   push, taxi
4   standby for departure
5   cleared for take-off
6   handed off
*/

FLIGHT *createList(){
    FLIGHT *head = new FLIGHT;
    head->next = nullptr;
    return head;
}

void destroyList(FLIGHT *head){
    FLIGHT *p, *q;
    p = head;
    while (p!=nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
}

void addNew(FLIGHT *head, QString callsign){
    FLIGHT *p = head;
    for (;p->next!=nullptr;p=p->next); //locate to tail
    FLIGHT *add = new FLIGHT;
    add->callsign = callsign;
    add->status = 0;
    add->next = nullptr;
    p->next = add;
}

FLIGHT *findFlight(FLIGHT *head, QString callsign){
    FLIGHT *p = head->next;
    for (;p!=nullptr&&p->callsign!=callsign;p=p->next);
    return p;
}

void setStatus(FLIGHT *head, QString callsign, int status){
    FLIGHT *loc = findFlight(head, callsign);
    if (loc!=nullptr && status>=0 && status<=6)
        loc->status = status;
}

int nextStatus(FLIGHT *head, QString callsign){
    FLIGHT *loc = findFlight(head, callsign);
    if (loc==nullptr)
        return -1; //not found
    else
        return ++loc->status;
}

int prevStatus(FLIGHT *head, QString callsign){
    FLIGHT *loc = findFlight(head, callsign);
    if (loc==nullptr)
        return -1; //not found
    else
        return --loc->status;
}

void removeFlight(FLIGHT *head, QString callsign){
    FLIGHT *p, *q;
    p = head; //previous node
    q = head->next; //node to remove
    while (q!=nullptr) {
        if (q->callsign==callsign){
            p->next = q->next;
            delete q;
            return;
        }
        p = q;
        q = p->next;
    }
}

QString generateReport(FLIGHT *head){
    FLIGHT *p = head->next;
    int sts[7]={};
    for (;p!=nullptr;p=p->next)
        sts[p->status]++;

    int i, gnd, tot;
    for (i=gnd=tot=0;i<5;i++){
        gnd += sts[i];
        tot += sts[i];
    } //status 5 are not on the ground
    tot += sts[5]+sts[6];

    QString lines;
    lines = QString("  %1\tflights are waiting for clearance.\n").arg(sts[0]);
    lines += QString("  %1\tflights have received clearance.\n").arg(sts[1]);
    lines += QString("  %1\tflights are waiting for push back.\n").arg(sts[2]);
    lines += QString("  %1\tflights are taxiing.\n").arg(sts[3]);
    lines += QString("  %1\tflights are waiting for departure.\n").arg(sts[4]);
    lines += QString("  %1\tflights are departing.\n").arg(sts[5]);
    lines += QString().fill('-',54) + '\n';
    lines += QString("  %1\tflights are on the ground.\n").arg(gnd);
    lines += QString("  %1\tflights have departed.\n").arg(sts[6]);
    lines += QString("  %1\tflights in total.\n").arg(tot);
    return lines;
}
