#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extern.h"
#include "client-server.h"
#include "pminin.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <WinSock2.h>
#include "place.h"
#include <QLabel>
#include <QSound>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPixmap pixmap("E:/qtfile/five-chess/ground/1.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    int i,j;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QString s=QString::number(step,10);
    ui->step->setText(s);
    if(step==2)
    {
    if(way==1)
    {
        ui->label_me->setPixmap(QPixmap("E:/qtfile/five-chess/ground/white.jpg").scaled(QSize(71,71),Qt::KeepAspectRatio));
        ui->label_you->setPixmap(QPixmap("E:/qtfile/five-chess/ground/black.jpg").scaled(QSize(71,71),Qt::KeepAspectRatio));
        ui->player_1->setPixmap(QPixmap("E:/qtfile/five-chess/ground/player1.jpg").scaled(QSize(111,151),Qt::KeepAspectRatio));
        ui->player_2->setPixmap(QPixmap("E:/qtfile/five-chess/ground/player2.jpg").scaled(QSize(111,151),Qt::KeepAspectRatio));
    }
    else if(way==2)
    {
        ui->label_me->setPixmap(QPixmap("E:/qtfile/five-chess/ground/black.jpg").scaled(QSize(71,71),Qt::KeepAspectRatio));
        ui->label_you->setPixmap(QPixmap("E:/qtfile/five-chess/ground/white.jpg").scaled(QSize(71,71),Qt::KeepAspectRatio));
        ui->player_1->setPixmap(QPixmap("E:/qtfile/five-chess/ground/player2.jpg").scaled(QSize(111,151),Qt::KeepAspectRatio));
        ui->player_2->setPixmap(QPixmap("E:/qtfile/five-chess/ground/player1.jpg").scaled(QSize(111,151),Qt::KeepAspectRatio));
    }
    }
    for (i = 0; i < 20; i++)
    {
        painter.drawLine(20, 20 + i * 30, 590, 20 + i * 30);
        painter.drawLine(20 + i * 30, 20, 20 + i * 30, 590);
    }
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(way==1)
    {

        this->setWindowTitle("Player 2");
        send(sock1,sendc,20,0);
        memset(sendc,0,20);
        memset(resc,0,20);
        recv(sock1,resc,20,0);
        lay();
        step++;
        Sleep(1000);
        pminin();
        step++;
        QSound::play("E:/qtfile/five-chess/ground/play.wav");
        for (i = 0; i < 19; i++)
        {
            for (j = 0; j < 19; j++)
            {
                if (a[i][j] == 1 && way==1)
                {
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30, 20+j*30), 10, 10);

                }
                else if (a[i][j] == 2 && way==1)
                {
                    brush.setColor(Qt::white);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30,20+j*30), 10, 10);

                }
                else if (a[i][j] == 2 && way==2)
                {
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30, 20+j*30), 10, 10);

                }
                else if (a[i][j] == 1 && way==2)
                {
                    brush.setColor(Qt::white);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30,20+j*30), 10, 10);

                }
            }
        }
        update();
    }
    else if(way==2)
    {
        this->setWindowTitle("Player 1");
        memset(resc,0,20);
        recv(sock2,resc,20,0);
        if(k!=1)
        {
            lay();
            step++;
            Sleep(1000);
        }
        pminin();
        step++;
        QSound::play("E:/qtfile/five-chess/ground/play.wav");
        for (i = 0; i < 19; i++)
        {
            for (j = 0; j < 19; j++)
            {
                if (a[i][j] == 1 && way==1)
                {
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30, 20+j*30), 10, 10);

                }
                else if (a[i][j] == 2 && way==1)
                {
                    brush.setColor(Qt::white);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30,20+j*30), 10, 10);

                }
                else if (a[i][j] == 2 && way==2)
                {
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30, 20+j*30), 10, 10);

                }
                else if (a[i][j] == 1 && way==2)
                {
                    brush.setColor(Qt::white);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(20+i*30,20+j*30), 10, 10);

                }
            }
        }
        send(sock2,sendc,20,0);
        memset(sendc,0,20);
        update();
    }
    else if(way==3)
    {
        closesocket(sock);
        closesocket(sock1);
        closesocket(sock2);
        WSACleanup();

    }
}

