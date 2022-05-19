#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exercises.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// Ex_1
    connect(ui->calculate_1, &QPushButton::clicked, this, &MainWindow::calculate_1);
    connect(ui->param_A, &QLineEdit::textChanged, this, &MainWindow::changeParams_1);
    connect(ui->param_B, &QLineEdit::textChanged, this, &MainWindow::changeParams_1);
    connect(ui->param_C, &QLineEdit::textChanged, this, &MainWindow::changeParams_1);
    QWidget * w1[] = {ui->calculate_1, ui->param_A, ui->param_B, ui->param_C};
    setTab(w1, sizeof(w1)/sizeof(w1[0]));

// Ex_2
    connect(ui->calculate_3, &QPushButton::clicked, this, &MainWindow::calculate_2);
    connect(ui->param_S1, &QLineEdit::textChanged, this, &MainWindow::changeParams_2);
    connect(ui->param_S2, &QLineEdit::textChanged, this, &MainWindow::changeParams_2);
    connect(ui->param_ANG, &QLineEdit::textChanged, this, &MainWindow::changeParams_2);
    connect(ui->param_RAD, &QRadioButton::toggled, this, &MainWindow::changeParams_2);
    connect(ui->param_DEG, &QRadioButton::toggled, this, &MainWindow::changeParams_2);
    QWidget * w2[] = {ui->calculate_3, ui->param_S1, ui->param_S2, ui->param_ANG, ui->param_DEG, ui->param_RAD};
    setTab(w2, sizeof(w2)/sizeof(w2[0]));

// Ex_3
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addText);
    connect(ui->set, &QPushButton::clicked, this, &MainWindow::setText);
    connect(ui->redbold, &QPushButton::clicked, this, &MainWindow::redBold);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTab(QWidget ** w, int n)
{
    for(int i=0; i<n; ++i)
    {
        if(i == n-1)
            this->setTabOrder(w[i], w[0]);
        else
            this->setTabOrder(w[i], w[i+1]);
    }
}
void MainWindow::calculate_1()      //Вычисление корней квадратного уравнения
{
    Ex_1 ex(ui->param_A->text(), ui->param_B->text(), ui->param_C->text());
    QString res[2];
    ex.getStringResult(res);
    ui->label_RES1->setText(res[0]);
    ui->label_RES2->setText(res[1]);
}

void MainWindow::calculate_2()      //Вычисление третьей стороны триугольника по двум и углу между ними
{
    Ex_2 ex(ui->param_S1->text(), ui->param_S2->text(), ui->param_ANG->text(), ui->param_DEG->isChecked());
    QString res;
    ex.getStringResult(&res);
    ui->label_S3->setText(res);

}

void MainWindow::changeParams_1()
{
    ui->label_RES1->setText("пересчитайте");
    ui->label_RES2->setText("пересчитайте");
}

void MainWindow::changeParams_2()
{
    ui->label_S3->setText("пересчитайте");
}

void MainWindow::addText()  //Добавить текст
{
    QString txt1 = ui->text_1->toPlainText();
    QString txt2 = ui->text_2->toPlainText();
    ui->text_2->setPlainText(txt2 + txt1);

}

void MainWindow::setText()  //Заменить текст
{
    QString txt = ui->text_2->toPlainText();
    ui->text_1->setPlainText(txt);

}

void MainWindow::redBold()  //Отформатировать текст
{
    QString txt = ui->text_1->toPlainText();
    txt = "<b style=\"color: red\">" + txt + "</b>";
    ui->text_3->setHtml(txt);

}



