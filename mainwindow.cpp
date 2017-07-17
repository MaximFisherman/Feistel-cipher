#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cipherfeistel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->ButtonEncode, SIGNAL (released()), this, SLOT (ButtonEncode()));
}

void MainWindow::ButtonEncode()
{
    CipherFeistel cipherFeistel;
    QString CipherWord = ui->EditBox->toPlainText();

    cipherFeistel.CipherAlgoritm(CipherWord.toStdString());

    //ui->ButtonEncode->setText();
}

MainWindow::~MainWindow()
{
    delete ui;
}
