#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adddiv = new AddDiv;
    Quad = new quad;
    connect(adddiv, &AddDiv::firstWindow, this, &MainWindow::show);
    connect(Quad, &quad::firstWindow, this, &MainWindow::show);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    adddiv->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    Quad->show();
}

