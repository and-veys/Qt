#include "mainwindow.h"
#include "ui_mainwindow.h"

//----------------------------------------
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Домашняя работа №2");

//Ex_2
    connect(ui->pushButton_up, &QPushButton::clicked, this, &MainWindow::onStringUp);
    connect(ui->pushButton_down, &QPushButton::clicked, this, &MainWindow::onStringDown);
    connect(ui->checkBox_mode, &QCheckBox::stateChanged, this, &MainWindow::onChangeMode);
    connect(ui->pushButton_del, &QPushButton::clicked, this, &MainWindow::onStringDel);
    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::onStringAdd);

    ui->listView->setModel(&model_list);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked);

    model_list.initItems();                 //постоянные значения, заданные задачей
    model_list.initViewModes();             //постоянные для изменения вида
    onChangeMode();

//Ex_3
    connect(ui->pushButton_paint, &QPushButton::clicked, this, &MainWindow::onPaintBackground);
     connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::onClearBackground);

    ui->tableView->setModel(&model_table);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    model_table.initHeader();
    model_table.initItems();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStringDel()
{
    model_list.removeRow(ui->listView);
}

void MainWindow::onStringAdd()
{
    model_list.appendRow(ui->lineEdit_add->text().trimmed());
    ui->lineEdit_add->clear();
}

void MainWindow::onStringUp()
{
    model_list.moveRow(-1, ui->listView);
}

void MainWindow::onStringDown()
{
    model_list.moveRow(1, ui->listView);
}

void MainWindow::onChangeMode()
{
    MyMode temp = model_list.getItemMode(ui->checkBox_mode->isChecked());
    ui->listView->setViewMode(temp.view_mode);
    ui->pushButton_up->setText(temp.text_button_1);
    ui->pushButton_down->setText(temp.text_button_2);
}

void MainWindow::onPaintBackground()
{
    model_table.paintBackground(ui->tableView);
}

void MainWindow::onClearBackground()
{
    model_table.clearBackground();

}
