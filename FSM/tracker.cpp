#include "tracker.h"
#include "listwidget.h"

#include <QListWidgetItem>
#include <QBrush>
#include <QString>


extern QBrush brush_b_def,brush_b_clr,brush_b_tit;
extern QBrush brush_f_def,brush_f_clr,brush_f_tit;


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

int nextStatus(FLIGHT *head, QString callsign){ //reserved
    FLIGHT *loc = findFlight(head, callsign);
    if (loc==nullptr)
        return -1; //not found
    else{
        switch ((loc->status++)) {
        case 1: //clearance received
            break;
        case 2: //standby for pushback
            break;
        case 3: //push&start approved, taxiing
            break;
        case 4: //standby for departure
            break;
        case 5: //cleared for take-off
            break;
        case 6: //departed
            break;
        default:
            loc->status = 0; //standby for clearance
        }
        return loc->status;
    }
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
    int gnd, dep;
    gnd = dep = 0;
    for (;p!=nullptr;p=p->next){
        switch (p->status) { //may be specified in future
        case 0:
            gnd++;
            break;
        case 1:
            gnd++;
            break;
        case 2:
            gnd++;
            break;
        case 3:
            gnd++;
            break;
        case 4:
            gnd++;
            break;
        case 5:
            gnd++;
            break;
        case 6:
            dep++;
            break;
        }
    }

    QString line1, line2, line3;
    line1 = QString("%1\tflights on ground.\n").arg(gnd);
    line2 = QString("%1\tflights departed\n").arg(dep);
    line3 = QString("%3\tflights in total.\n").arg(gnd+dep);
    return line1+line2+line3;
}
