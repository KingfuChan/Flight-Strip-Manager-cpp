#ifndef TRACKER_H
#define TRACKER_H

#include <QString>


typedef struct LinkedList{
    QString callsign;
    int status; //reserved
    LinkedList *next;
}FLIGHT;

FLIGHT *createList();

void destroyList(FLIGHT *head);

void addNew(FLIGHT *head, QString callsign);

FLIGHT *findFlight(FLIGHT *head, QString callsign);

int nextStatus(FLIGHT *head, QString callsign); //reserved

void removeFlight(FLIGHT *head, QString callsign);

QString generateReport(FLIGHT *head);

#endif // TRACKER_H
