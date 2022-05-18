#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculate_1, &QPushButton::clicked, this, &MainWindow::calculate_1);
    connect(ui->param_A, &QLineEdit::textChanged, this, &MainWindow::changeParams);
    connect(ui->param_B, &QLineEdit::textChanged, this, &MainWindow::changeParams);
    connect(ui->param_C, &QLineEdit::textChanged, this, &MainWindow::changeParams);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calculate_1()      //Вычисление корней квадратного уравнения
{
    double a;
    double b;
    double c;
    bool ok = getDoubleFromText(ui->param_A->text(), a);
    ok &= getDoubleFromText(ui->param_B->text(), b);
    ok &= getDoubleFromText(ui->param_C->text(), c);
    if(ok)
    {
        if(a == 0)
        {
            ui->label_RES1->setText(QString::number(-c/b));
            ui->label_RES2->setText("нет корня");
        }
        else
        {
           double d = b*b-4*a*c;
           if(d >= 0)
           {
               d = qSqrt(d);
               ui->label_RES1->setText(QString::number((-b+d)/(2*a)));
               ui->label_RES2->setText(QString::number((-b-d)/(2*a)));
           }
           else
                errorParam("нет вещественного корня");
        }
    }
    else
        errorParam("ошибка ввода");
}
bool MainWindow::getDoubleFromText(QString str, double & ret)
{
    bool ok;
    ret = str.toDouble(&ok);
    return ok;
}

void MainWindow::errorParam(QString mes)
{
    ui->label_RES1->setText(mes);
    ui->label_RES2->setText(mes);
}

void MainWindow::changeParams()
{
    errorParam("пересчитайте");
}



