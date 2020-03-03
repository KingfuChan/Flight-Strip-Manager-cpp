#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>

class LCDTimer : public QLCDNumber{
    Q_OBJECT

public:
    LCDTimer(QWidget *parent = nullptr);
    ~LCDTimer();

public slots:
    void onTimeout();

private:
    QTimer *timer;
    const int timeList[4]={30,60,120,180};
    int status, second;

protected:
    void mouseReleaseEvent(QMouseEvent*);
    void wheelEvent(QWheelEvent*);
};

#endif // TIMER_H
