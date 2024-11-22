#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "arduino.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=a.connect_arduino();
    switch(ret){
    case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
    break;
    case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
    break;
    case(-1):qDebug()<<"arduino is not available";
    }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    a.write_to_arduino("1");
}
void MainWindow::update_label()
{
    data = a.read_from_arduino();
    if(data=="1"){
    ui->label->setText("MOUVEMENT DETECTEE");
    ui->label_2->setText("ON");



    QMessageBox::critical(nullptr, QObject::tr("capteur de mouvement"),

                QObject::tr("MOUVEMENT DETECTEE.\n"

                            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if(data=="0"){
        ui->label->setText("PAS DE MOUVEMENT");
        ui->label_2->setText("OFF");



    }
    qDebug()<<"data"<<data;
}
