#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "tracker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void clickMenu(QAction*);
    void addFlight();
    void addFlight(QListWidgetItem*);
    void deleteFlight(QListWidgetItem*);
    void resetLists();
    void setStatusClr(QListWidgetItem*);
    void setStatusDep(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    FLIGHT *ListFlight;
    const int opac_list[10]={1,2,3,4,5,6,7,8,9,10}, *opac;
    void setupLists();

protected:
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);

};
#endif // MAINWINDOW_H
