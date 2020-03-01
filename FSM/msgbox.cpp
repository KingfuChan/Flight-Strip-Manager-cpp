#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QString>

bool requestMessageBox(QString title, QString text, int mode){
    QString r = "Roger", a = "Affirm", n = "Negative";
    QPushButton *btnRgr, *btnAfm, *btnNeg;
    QMessageBox msgbox;
    msgbox.setWindowTitle(title);
    msgbox.setText(text);

    switch (mode) {
    case 1: //roger only
        btnRgr = msgbox.addButton(r, QMessageBox::AcceptRole);
        msgbox.exec();
        return 1;
        break;
    case 2: //Y or N
        msgbox.setIcon(QMessageBox::Question);
        btnAfm = msgbox.addButton(a, QMessageBox::AcceptRole);
        btnNeg = msgbox.addButton(n, QMessageBox::RejectRole);
        msgbox.setDefaultButton(btnNeg);
        msgbox.setEscapeButton(btnNeg);
        msgbox.exec();
        return (msgbox.clickedButton()==btnAfm);
        break;
    default: //wrong usage
        return 0;
    }
}
