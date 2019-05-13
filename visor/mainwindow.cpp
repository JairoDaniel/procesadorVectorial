#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap bkgnd("/home/jairo/Desktop/gui/Resources/procesadorVectorial");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(QSize(1130, 675));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString lA=  "regA: "+QString::fromStdString(regA)+"\n";
    lA+="regB: "+QString::fromStdString(regB)+"\n";
    lA+="regWR: "+QString::fromStdString(regWR)+"\n";
    QString lB= "Mem: " + QString::fromStdString(flagM)+"\n";
    lB+= "RD: " + QString::fromStdString(RD)+"\n";
    lB+= "WR: " + QString::fromStdString(WR)+"\n";
    QString lC=  "OP: "+QString::fromStdString(op)+"\n";
    QString lD=  "regA: "+QString::fromStdString(regAE)+"\n";
    lD+="regWR: "+QString::fromStdString(regWRE)+"\n";
    lD+="RD: " + QString::fromStdString(rdFE)+"\n";
    lD+="WR: " + QString::fromStdString(wrFE)+"\n";
    ui->labelA->setText(lA);
    ui->labelB->setText(lB);
    ui->labelC->setText(lC);
    ui->labelD->setText(lD);

    this->close();
}

void MainWindow::test(){
    this->show();
}


