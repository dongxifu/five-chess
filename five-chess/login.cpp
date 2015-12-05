#include "login.h"
#include "ui_login.h"
#include "ip.h"
#include "mainwindow.h"
#include "extern.h"
#include "client-server.h"
#include <QSound>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}

void login::on_But_1_clicked()
{
    QSound::play("E:/qtfile/five-chess/ground/play.wav");
    ip ipwindow;
    ipwindow.setWindowTitle("输入IP");
    ipwindow.exec();
    this->close();
}


void login::on_But_2_clicked()
{
    QSound::play("E:/qtfile/five-chess/ground/play.wav");
    way=2;
    player=2;
    server();
    this->close();

}
void login::on_pushButton_clicked()
{
    QSound::play("E:/qtfile/five-chess/ground/play.wav");
    this->close();
    exit(1);
}
