#include "tracker.h"
#include "listwidget.h"

#include <QListWidgetItem>
#include <QBrush>
#include <QString>

/*
Document about int status
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
    if (loc!=nullptr)
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
    for (;p!=nullptr;p=p->next){
        switch (p->status) { //may be specified in future
        case 0:
            sts[0]++;
            break;
        case 1:
            sts[1]++;
            break;
        case 2:
            sts[2]++;
            break;
        case 3:
            sts[3]++;
            break;
        case 4:
            sts[4]++;
            break;
        case 5:
            sts[5]++;
            break;
        case 6:
            sts[6]++;
            break;
        }
    }

    QString lines[8];
    lines[0] = QString("%1\tflights are waiting for clearance.\n").arg(sts[0]);
    lines[1] = QString("%1\tflights have received clearance.\n").arg(sts[1]);
    lines[2] = QString("%1\tflights are waiting for push back.\n").arg(sts[2]);
    lines[3] = QString("%1\tflights are taxiing.\n").arg(sts[3]);
    lines[4] = QString("%1\tflights are waiting for departure.\n").arg(sts[4]);
    lines[5] = QString("%1\tflights are departing.\n").arg(sts[5]);
    lines[6] = QString("%1\tflights have departed.\n").arg(sts[6]);
    lines[7] = QString("%1\tflights in total.\n").arg(
                sts[0]+sts[1]+sts[2]+sts[3]+sts[4]+sts[5]+sts[6]);
    return lines[0]+lines[1]+lines[2]+lines[3]+lines[4]+lines[5]+lines[6]+lines[7];
}
