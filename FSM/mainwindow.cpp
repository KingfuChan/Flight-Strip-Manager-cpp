#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tracker.h"
#include "msgbox.h"

#include <QtCore>
#include <QCloseEvent>
#include <QBrush>

extern QString about_lines;

extern QBrush brush_b_def,brush_b_clr;
extern QBrush brush_f_def,brush_f_clr;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clickMenu(ui->actionSec);
    clickMenu(ui->actionDrag_Drop);

    //connect signal slots with parameters
    QObject::connect(ui->listPend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleclickItem(QListWidgetItem*)));
    QObject::connect(ui->listTaxi, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleclickItem(QListWidgetItem*)));
    QObject::connect(ui->listDepa, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleclickItem(QListWidgetItem*)));

    QObject::connect(ui->listPend, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));
    QObject::connect(ui->listTaxi, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));
    QObject::connect(ui->listDepa, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));

    QObject::connect(ui->listPend, SIGNAL(deleteItem(QListWidgetItem*)), this, SLOT(deleteFlight(QListWidgetItem*)));
    QObject::connect(ui->listTaxi, SIGNAL(deleteItem(QListWidgetItem*)), this, SLOT(deleteFlight(QListWidgetItem*)));
    QObject::connect(ui->listDepa, SIGNAL(deleteItem(QListWidgetItem*)), this, SLOT(deleteFlight(QListWidgetItem*)));

    QObject::connect(ui->listPend, SIGNAL(deleteAfterDrop(QString)), ui->listTaxi, SLOT(deletebyText(QString)));
    QObject::connect(ui->listPend, SIGNAL(deleteAfterDrop(QString)), ui->listDepa, SLOT(deletebyText(QString)));
    QObject::connect(ui->listTaxi, SIGNAL(deleteAfterDrop(QString)), ui->listPend, SLOT(deletebyText(QString)));
    QObject::connect(ui->listTaxi, SIGNAL(deleteAfterDrop(QString)), ui->listDepa, SLOT(deletebyText(QString)));
    QObject::connect(ui->listDepa, SIGNAL(deleteAfterDrop(QString)), ui->listPend, SLOT(deletebyText(QString)));
    QObject::connect(ui->listDepa, SIGNAL(deleteAfterDrop(QString)), ui->listTaxi, SLOT(deletebyText(QString)));

    QObject::connect(ui->listPend, SIGNAL(changeStatus(QString, int)), this, SLOT(setFlightStatus(QString, int)));
    QObject::connect(ui->listTaxi, SIGNAL(changeStatus(QString, int)), this, SLOT(setFlightStatus(QString, int)));
    QObject::connect(ui->listDepa, SIGNAL(changeStatus(QString, int)), this, SLOT(setFlightStatus(QString, int)));

    QObject::connect(ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(clickMenu(QAction*)));

    setFixedWidth(371);
    setMinimumHeight(167);
    opac = &(opac_list[9]);

    mode = 1; // drag&drop mode, 1 enables
    ui->listPend->resetList("Clearance");
    ui->listTaxi->resetList("Push&Taxi");
    ui->listDepa->resetList("Departure");
    ui->listPend->initStatus = 0;
    ui->listTaxi->initStatus = 2;
    ui->listDepa->initStatus = 4;

    ListFlight = createList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//override events
void MainWindow::resizeEvent(QResizeEvent *event){
    int h;
    h = height()-ui->menuBar->height()-ui->listDepa->y()-10;
    ui->listPend->setFixedHeight(h);
    ui->listTaxi->setFixedHeight(h);
    ui->listDepa->setFixedHeight(h);
}

void MainWindow::closeEvent(QCloseEvent *event){
    bool confirm = requestMessageBox(this, "Confirm exit program?", 2);
    if (!confirm) event->ignore();
}

//slots
void MainWindow::clickMenu(QAction *action){
    if (action==ui->actionExit)
        close();
    else if (action==ui->actionStay_on_top){
        if (ui->actionStay_on_top->isChecked())
            setWindowFlags(windowFlags()|Qt::WindowStaysOnTopHint);
        else
            setWindowFlags(windowFlags()&~Qt::WindowStaysOnTopHint);
        show();
    }
    else if (action==ui->actionOpac_Rest){
        opac = &opac_list[9];
        setWindowOpacity(1.00);
        ui->actionOpac_Curr->setText("Current: 100%");
    }
    else if (action==ui->actionOpac_Incr){
        opac = opac+1<=&opac_list[9]?opac+1:&opac_list[9];
        setWindowOpacity(*opac/10.0);
        ui->actionOpac_Curr->setText(QString("Current: %1%").arg(*opac*10));
    }
    else if (action==ui->actionOpac_Decr){
        opac = opac-1>=&opac_list[0]?opac-1:&opac_list[0];
        setWindowOpacity(*opac/10.0);
        ui->actionOpac_Curr->setText(QString("Current: %1%").arg(*opac*10));
    }
    else if (action==ui->actionReset)
        resetLists();
    else if (action==ui->actionAbout){
        requestMessageBox(this, about_lines, 1);
    }
    else if (action==ui->actionStatistics){
        requestMessageBox(this, generateReport(ListFlight), 1);
    }
    else if (action==ui->actionSec){
        ui->lcdNumber->setDisplayMode(0);
        ui->actionSec->setChecked(1);
        ui->actionMinSec->setChecked(0);
    }
    else if (action==ui->actionMinSec){
        ui->lcdNumber->setDisplayMode(1);
        ui->actionSec->setChecked(0);
        ui->actionMinSec->setChecked(1);
    }
    else if (action==ui->actionDrag_Drop){
        mode = 1;
        ui->actionDouble_click->setChecked(0);
        ui->actionDrag_Drop->setChecked(1);
        ui->listPend->setDragDropMode(QAbstractItemView::DragDrop);
        ui->listTaxi->setDragDropMode(QAbstractItemView::DragDrop);
        ui->listDepa->setDragDropMode(QAbstractItemView::DragDrop);
    }
    else if (action==ui->actionDouble_click){
        mode = 0;
        ui->actionDouble_click->setChecked(1);
        ui->actionDrag_Drop->setChecked(0);
        ui->listPend->setDragDropMode(QAbstractItemView::NoDragDrop);
        ui->listTaxi->setDragDropMode(QAbstractItemView::NoDragDrop);
        ui->listDepa->setDragDropMode(QAbstractItemView::NoDragDrop);
    }
}

void MainWindow::addFlight(){
    QString callsign;
    callsign = ui->lineEdit->text();
    ui->lineEdit->clear();
    if (callsign.length()<=0) return;
    FLIGHT *rec = findFlight(ListFlight,callsign);
    if (rec!=nullptr){
        if (rec->status==6){ //callsign in use but departed
            bool confirm = requestMessageBox(this,
                                             QString("Callsign %1 already exists but has departed.\n"
                                                     "Confirm still add to list?").arg(callsign), 2);
            if (!confirm) return;
            rec->callsign = QString("_%1").arg(rec->callsign); //distinguish
        }else return; //callsign in use not departed
    }
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(callsign);
    item->setBackground(brush_b_def);
    item->setForeground(brush_f_def);
    ui->listPend->addItem(item);
    addNew(ListFlight,callsign);
}

void MainWindow::addFlight(QListWidgetItem *item){ //reset existing flight
    FLIGHT *temp = findFlight(ListFlight,item->text());
    if (temp==nullptr)
        addNew(ListFlight,item->text());
    else
        temp->status = 0;
    ui->listPend->addItem(item);
}

void MainWindow::deleteFlight(QListWidgetItem *item){
    removeFlight(ListFlight,item->text());
    delete item;
}

void MainWindow::resetLists(){
    bool confirm = requestMessageBox(this, "Confirm reset all lists?", 2);
    if (!confirm) return;

    destroyList(ListFlight);
    ListFlight = createList();

    ui->listPend->resetList("Clearance");
    ui->listTaxi->resetList("Push&Taxi");
    ui->listDepa->resetList("Departure");
}

void MainWindow::doubleclickItem(QListWidgetItem *item){
    if (mode){ //drag drop
        FLIGHT *flt = findFlight(ListFlight,item->text());
        switch (flt->status) {
        case 0:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            flt->status = 1;
            break;
        case 1:
            item->setBackground(brush_b_def);
            item->setForeground(brush_f_def);
            flt->status = 0;
            break;
        case 2:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            flt->status = 3;
            break;
        case 3:
            item->setBackground(brush_b_def);
            item->setForeground(brush_f_def);
            flt->status = 2;
            break;
        case 4:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            flt->status = 5;
            break;
        case 5:
            delete item;
            flt->status = 6;
        default:
            break;
        }
    }else{ //double click
        int sts = nextStatus(ListFlight,item->text());
        switch (sts) {
        case 1:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            break;
        case 2:
            ui->listTaxi->addItem(item->text());
            delete item;
            break;
        case 3:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            break;
        case 4:
            ui->listDepa->addItem(item->text());
            delete item;
            break;
        case 5:
            item->setBackground(brush_b_clr);
            item->setForeground(brush_f_clr);
            break;
        case 6:
            delete item;
            break;
        default:
            break;
        }
    }
}

void MainWindow::setFlightStatus(QString callsign, int status){ //only used to receive signal
    setStatus(ListFlight, callsign, status);
}
