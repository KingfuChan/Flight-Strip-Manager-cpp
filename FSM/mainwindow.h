#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QBrush brush_b_def, brush_f_def;
    QBrush brush_b_clr,brush_f_clr;
    QBrush brush_b_tit,brush_f_tit;

public slots:
    void clickMenu(QAction*);
    void addFlight();
    void addFlight(QString);
    void resetLists();
    void setStatusClr(QListWidgetItem*);
    void setStatusDep(QListWidgetItem*);

private:
    Ui::MainWindow *ui;
    const int opac_list[10]={1,2,3,4,5,6,7,8,9,10}, *opac;
    void setupLists();

protected:
    void resizeEvent(QResizeEvent*);
    void closeEvent(QCloseEvent*);

};
#endif // MAINWINDOW_H
