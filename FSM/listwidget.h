#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>


class CustomListWidget : public QListWidget{
    Q_OBJECT

public:
    CustomListWidget(QWidget *parent = nullptr);
    ~CustomListWidget();
    void dropEvent(QDropEvent *event) override;

signals:
    void resetItem(QListWidgetItem*);
    void deleteItem(QListWidgetItem*);
    void deleteAfterDrop(QString);

public slots:
    void showContext(QPoint);
    void calcSequence();
    void deletebyText(QString);

protected:
    void enterEvent(QEvent*) override;

};

#endif // LISTWIDGET_H
