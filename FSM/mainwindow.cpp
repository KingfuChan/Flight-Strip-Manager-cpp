#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QMessageBox>
#include <QCloseEvent>
#include <QBrush>
#include <QDebug> //debug only

extern QBrush brush_b_def,brush_b_clr,brush_b_tit;
extern QBrush brush_f_def,brush_f_clr,brush_f_tit;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect signal slots with parameters
    QObject::connect(ui->list_push, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(setStatusClr(QListWidgetItem*)));
    QObject::connect(ui->list_dept, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(setStatusDep(QListWidgetItem*)));
    QObject::connect(ui->list_pend, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(setStatusClr(QListWidgetItem*)));
    QObject::connect(ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(clickMenu(QAction*)));
    QObject::connect(ui->list_pend, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));
    QObject::connect(ui->list_push, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));
    QObject::connect(ui->list_dept, SIGNAL(resetItem(QListWidgetItem*)), this, SLOT(addFlight(QListWidgetItem*)));

    setFixedWidth(371);
    setMinimumHeight(167);
    opac = &(opac_list[9]);

    setupLists();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//override events
void MainWindow::resizeEvent(QResizeEvent *event){
    int h;
    h = height()-ui->menuBar->height()-ui->list_dept->y()-10;
    ui->list_pend->setFixedHeight(h);
    ui->list_push->setFixedHeight(h);
    ui->list_dept->setFixedHeight(h);
}

void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButtons confirm;
    confirm = QMessageBox::question(this,windowTitle(),
                                    "Are you sure to exit?",
                                    QMessageBox::Ok|QMessageBox::Cancel);
    if (confirm!=QMessageBox::Ok)
        event->ignore();
}

//custom methods
void MainWindow::setupLists(){
    QListWidgetItem *title_pend = new QListWidgetItem;
    QListWidgetItem *title_push = new QListWidgetItem;
    QListWidgetItem *title_dept = new QListWidgetItem;

    title_pend->setBackground(brush_b_tit);
    title_pend->setForeground(brush_f_tit);
    title_pend->setText("Clearance");
    title_pend->setFlags(Qt::NoItemFlags);

    title_push->setBackground(brush_b_tit);
    title_push->setForeground(brush_f_tit);
    title_push->setText("Push&Start");
    title_pend->setFlags(Qt::NoItemFlags);

    title_dept->setBackground(brush_b_tit);
    title_dept->setForeground(brush_f_tit);
    title_dept->setText("Departure");
    title_dept->setFlags(Qt::NoItemFlags);

    ui->list_pend->addItem(title_pend);
    ui->list_push->addItem(title_push);
    ui->list_dept->addItem(title_dept);
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
        //reserved
    }
    else if (action==ui->actionStatistics){
        //reserved
    }
}

void MainWindow::addFlight(){
    QString callsign;
    callsign = ui->lineEdit->text();
    if (callsign.length()>0){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(callsign);
        item->setBackground(brush_b_def);
        item->setForeground(brush_f_def);
        addFlight(item);
    }
    ui->lineEdit->clear();
}

void MainWindow::addFlight(QListWidgetItem *item){
    ui->list_pend->addItem(item);
}

void MainWindow::resetLists(){
    QMessageBox::StandardButtons confirm;
    confirm = QMessageBox::question(this,windowTitle(),
                                    "Are you sure to reset all lists?",
                                    QMessageBox::Ok|QMessageBox::Cancel);
    if (confirm!=QMessageBox::Ok) return;

    ui->list_pend->clear();
    ui->list_push->clear();
    ui->list_dept->clear();
    setupLists();
}

void MainWindow::setStatusClr(QListWidgetItem* item){
    if (item->background()==brush_b_def){
        item->setBackground(brush_b_clr);
        item->setForeground(brush_f_clr);
    }else if (item->background()==brush_b_clr){
        item->setBackground(brush_b_def);
        item->setForeground(brush_f_def);
    }
}

void MainWindow::setStatusDep(QListWidgetItem* item){
    if (item->background()==brush_b_def){
        item->setBackground(brush_b_clr);
        item->setForeground(brush_f_clr);
    }else if (item->background()==brush_b_clr){
        delete item;
    }
}
