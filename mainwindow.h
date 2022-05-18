#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void setTab(QWidget ** w, int n);
private:
    Ui::MainWindow *ui;
private slots:
    void calculate_1();
    void calculate_2();
    void changeParams_1();
    void changeParams_2();
    void addText();
    void setText();
    void redBold();
};
#endif // MAINWINDOW_H

