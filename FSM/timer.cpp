#include "timer.h"

#include <QApplication>
#include <QTimer>
#include <QString>
#include <QMouseEvent>


LCDTimer::LCDTimer(QWidget *parent)
    :QLCDNumber(parent)
{
    timer = new QTimer(this);
    status = 0;
    second = dValue = timeList[0];
    setDisplayMode(0); //0 for sss, 1 for m:ss
    displayTime(second);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

LCDTimer::~LCDTimer(){
    delete timer;
}

void LCDTimer::setDisplayMode(int mode){
    displayMode = mode;
    displayTime(dValue);
}

void LCDTimer::displayTime(int time){
    if (time<0){ //clear display
        display(nullptr);
        return;
    }
    dValue = time;
    if (!displayMode){ //sss
        display(time);
    }else{ //m:ss
        int min,sec;
        min = time / 60;
        sec = time % 60;
        char t[5];
        t[0] = '0' + min;
        t[1] = ':';
        t[2] = '0' + sec / 10;
        t[3] = '0' + sec % 10;
        t[4] = '\0';
        display(t);
    }
}

void LCDTimer::onTimeout(){
    static int beeptime;
    static bool flicker; //on when ==ture
    switch (status) {
    case 3: //flickering LCD number
        if ((flicker=!flicker)==true)
            displayTime(second);
        else
            displayTime(-1);
        break;
    case 2: //play beeping sound flickering LCD
        if ((flicker=!flicker)==true)
            displayTime(second);
        else
            displayTime(0);
        QApplication::beep();
        beeptime++;
        if (beeptime>=5){
            status = 3;
            timer->setInterval(500);
        }
        break;
    case 1: //normal count down
        int t = dValue-1;
        if (t)
            displayTime(t);
        else{
            displayTime(0);
            status = 2;
            timer->setInterval(200);
            QApplication::beep();
            beeptime = flicker = 0;
        }
        break;
    }
}

void LCDTimer::mouseReleaseEvent(QMouseEvent *event){
    if (event->button()==Qt::RightButton){
        int i;
        for (i=0; i<4 && dValue>=timeList[i]; i++); //locate next preset time
        i = i<4 ? i : 0;
        second = timeList[i];
        displayTime(second);
    }else if (event->button()==Qt::LeftButton){
        QApplication::beep();
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
            displayTime(second);
        }
    }
}

void LCDTimer::wheelEvent(QWheelEvent *event){
    if (status) return; //lock wheel when timer acive
    int d = event->angleDelta().y()/120;
    second = dValue+d;
    second = second<1 || second>599 ? 1: second;
    displayTime(second);
}
