#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->ButtonEncode, SIGNAL (released()), this, SLOT (ButtonEncode()));
}

void MainWindow::ButtonEncode()
{
    ui->ButtonEncode->setText("I'm work");
}

MainWindow::~MainWindow()
{
    delete ui;
}
