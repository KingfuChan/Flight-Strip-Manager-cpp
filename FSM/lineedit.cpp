#include "lineedit.h"
#include <QRegExpValidator>
#include <QRegExp>
#include <QKeyEvent>
#include <QString>

CustomLineEdit::CustomLineEdit(QWidget *parent)
    :QLineEdit(parent)
{
    QRegExpValidator *val = new QRegExpValidator;
    val->setRegExp(QRegExp("[A-Za-z0-9]*"));
    setValidator(val);
    QObject::connect(this,SIGNAL(textEdited(QString)),this,SLOT(capitalize(QString)));
}

CustomLineEdit::~CustomLineEdit(){

}

void CustomLineEdit::keyPressEvent(QKeyEvent *event){
    if (event->key()==16777216)
        clear();
    else
        QLineEdit::keyPressEvent(event);
}

void CustomLineEdit::capitalize(QString string){
    QString str=string.toUpper();
    setText(str);
}
