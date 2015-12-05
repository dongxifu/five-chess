#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QFrame>
#include "login.h"
#include "extern.h"

char resc[20];
char sendc[20];
int xz=0;
int yz=0;
int m;
int n;
int k=1;
int a[19][19];
int way=0;
int player=1;
int step=2;
QString IP2;
SOCKET sock1;
SOCKET sock2;
SOCKET sock;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    login lw;
    int i,j;
    sendc[0]='0';
    sendc[1]='\0';
    for(i=0;i<19;i++)
        for(j=0;j<19;j++)
            a[i][j]=0;
    lw.setWindowTitle("登录");
    lw.exec();
    mw.show();
    return app.exec();

}

