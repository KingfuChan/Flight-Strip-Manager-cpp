#include "timer.h"

#include <QApplication>
#include <QTimer>
#include <QMouseEvent>


LCDTimer::LCDTimer(QWidget *parent)
    :QLCDNumber(parent)
{
    timer = new QTimer(this);
    status = 0;
    second = timeList[0];
    display(second);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

LCDTimer::~LCDTimer(){
    delete timer;
}

void LCDTimer::onTimeout(){
    static int beeptime;
    switch (status) {
    case 3: //flickering LCD number
        if (intValue())
            display(nullptr);
        else
            display(second);
        break;
    case 2: //play beeping sound flickering LCD
        if (intValue())
            display(nullptr);
        else
            display(second);
        QApplication::beep();
        beeptime++;
        if (beeptime>=5){
            status = 3;
            timer->setInterval(500);
        }
        break;
    case 1: //normal count down
        int t = intValue()-1;
        if (t)
            display(t);
        else{
            display(0);
            status = 2;
            timer->setInterval(200);
            QApplication::beep();
            beeptime = 0;
        }
        break;
    }
}

void LCDTimer::mouseReleaseEvent(QMouseEvent *event){
    if (event->button()==Qt::RightButton){
        int i;
        for (i=0; i<4 && intValue()>=timeList[i]; i++); //locate next preset time
        i = i<4 ? i : 0;
        second = timeList[i];
        display(second);
    }else if (event->button()==Qt::LeftButton){
        if (!status){
            status = 1;
            timer->setInterval(1000);
            timer->start(1000);
        }else if (status==1){ //timer on
            timer->stop();
            status = 0;
        }else{
            timer->stop();
            status = 0;
            display(second);
        }
    }
}

void LCDTimer::wheelEvent(QWheelEvent *event){
    if (status) return; //lock wheel when timer acive
    int d = event->angleDelta().y()/120;
    second = intValue()+d;
    second = second<1 || second>999 ? 1: second;
    display(second);
}
