#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class CustomLineEdit : public QLineEdit{
    Q_OBJECT

public:
    CustomLineEdit(QWidget *parent = nullptr);
    ~CustomLineEdit();

public slots:
    void capitalize(QString);

protected:
    void keyPressEvent(QKeyEvent *) override;

};

#endif // LINEEDIT_H
