#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

bool requestMessageBox(QWidget *parent, QString text, int mode){
    QString r = "Roger", a = "Affirm", n = "Negative";
    QPushButton *btnRgr, *btnAfm, *btnNeg;
    QMessageBox *msgbox = new QMessageBox(parent);
    msgbox->setWindowTitle(parent->windowTitle());
    msgbox->setText(text);

    int ret;
    switch (mode) {
    case 1: //roger only
        btnRgr = msgbox->addButton(r, QMessageBox::AcceptRole);
        msgbox->exec();
        ret = 1;
        break;
    case 2: //Y or N
        msgbox->setIcon(QMessageBox::Question);
        btnAfm = msgbox->addButton(a, QMessageBox::AcceptRole);
        btnNeg = msgbox->addButton(n, QMessageBox::RejectRole);
        msgbox->setDefaultButton(btnNeg);
        msgbox->setEscapeButton(btnNeg);
        msgbox->exec();
        ret = msgbox->clickedButton()==btnAfm;
        break;
    default: //wrong usage
        ret = 0;
    }
    delete msgbox;
    return ret;
}
