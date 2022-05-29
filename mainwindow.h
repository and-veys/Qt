#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myliststandarditemmodel.h"
#include "mytablestandarditemmodel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MyListStandardItemModel model_list;
    MyTableStandardItemModel model_table;

private slots:
    void onStringUp();
    void onStringDown();
    void onChangeMode();
    void onStringDel();
    void onStringAdd();
    void onPaintBackground();
    void onClearBackground();

};

#endif // MAINWINDOW_H
