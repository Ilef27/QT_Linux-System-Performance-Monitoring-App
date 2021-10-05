#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<iostream>
#include"qstring.h"
#include<fstream>
#include<thread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file("/proc/stat");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        QString str="cpu    user    nice    system    idle     iowait  irq  softirq steal guest guest_nice";
        ui->textBrowser->setText(str);
        ui->textBrowser->append(in.readLine());
        ui->textBrowser->append(in.readLine());
        ui->textBrowser->append(in.readLine());
        ui->textBrowser->append(in.readLine());
        ui->textBrowser->append(in.readLine());
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("/proc/meminfo");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());
        QTextStream in(&file);
        ui->textBrowser_2->setText(in.readLine());
        ui->textBrowser_2->append(in.readLine());

        ui->textBrowser_2->append(in.readLine());
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("/proc/net/arp");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        ui->textBrowser_3->setText(in.readAll());
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("/proc/cpuinfo");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        for(int i=0; i<5; i++){
        ui->textBrowser_4->setText(in.readLine());}
}

void MainWindow::on_pushButton_6_clicked()
{
    QFile file("/etc/hostname");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        ui->textBrowser_5->setText(in.readAll());
}

void MainWindow::on_pushButton_7_clicked()
{
    QFile file("/etc/os-release");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        QString str;
        for(int i=0;i<3;i++ ){
        str=in.readLine();}
        str.remove(0,3);
        ui->textBrowser_6->setText(str);

}

void MainWindow::on_pushButton_9_clicked()
{
    QFile file("/proc/version");

        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());

        QTextStream in(&file);
        ui->textBrowser_7->setText(in.read(32));
}

void MainWindow::on_pushButton_10_clicked()
{
    QFile file("/proc/meminfo");
        if (!file.open(QIODevice::ReadOnly))
            QMessageBox::information(0,"error", file.errorString());
        QTextStream in(&file);
        for(int i=0; i<14; i++){
        ui->textBrowser_8->setText(in.readLine());}
        ui->textBrowser_8->setText(in.readLine());
        ui->textBrowser_8->append(in.readLine());

}
