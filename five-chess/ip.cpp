#include "ip.h"
#include "ui_ip.h"
#include "extern.h"
#include "login.h"
#include "client-server.h"
#include <QMessageBox>
#include <QtGui>
#include <QApplication>
#include <QSound>
ip::ip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ip)
{

    ui->setupUi(this);
}

ip::~ip()
{
    delete ui;
}
void ip::on_pushButton_clicked()
{
    QSound::play("E:/qtfile/five-chess/ground/play.wav");
    IP2=ui->ip_test->text();
    way=1;
    player=1;
    client();
    this->close();
}


void ip::on_pushButton_2_clicked()
{
    QSound::play("E:/qtfile/five-chess/ground/play.wav");
    this->close();
    login lw;
    lw.setWindowTitle("登录");
    lw.exec();
}
