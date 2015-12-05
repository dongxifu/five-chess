#include "extern.h"
#include "mainwindow.h"
#include "pminin.h"
#include <QMessageBox>
#include <QPainter>
#include <QLabel>
int win()
{
    int i,w=1,mz=1,nz=1,z=1;
    for(i=1;i<5;i++)
    {
        if(yz+i<19&&a[xz][yz+i]==player)
            w++;
        else break;//下
    }
    for(i=1;i<5;i++)
    {
        if(yz-i>=0&&a[xz][yz-i]==player)
            w++;
        else break;//上
    }
    if(w>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(xz+i<19&&a[xz+i][yz]==player)
            mz++;
        else break;//右
    }
    for(i=1;i<5;i++)
    {
        if(xz-i>=0&&a[xz-i][yz]==player)
            mz++;
        else break;//左
    }
        if(mz>=5)
            return player;
    for(i=1;i<5;i++)
    {
        if(xz+i<19&&yz+i<19&&a[xz+i][yz+i]==player)
            nz++;
        else break;//右下
    }
    for(i=1;i<5;i++)
    {
        if(xz-i>=0&&yz-i>=0&&a[xz-i][yz-i]==player)
            nz++;
        else break;//左上
    }
    if(nz>=5)
        return player;
    for(i=1;i<5;i++)
    {
        if(xz+i<19&&yz-i>=0&&a[xz+i][yz-i]==player)
            z++;
        else break;
    }
    for(i=1;i<5;i++)
    {
        if(xz-i>=0&&yz+i<19&&a[xz-i][yz+i]==player)
            z++;
        else break;
    }
    if(z>=5)
        return player;
    return 0;
}

void lay()
{
         MainWindow *mw=new MainWindow;
            if(resc[1]==',')
            {
                yz=19-(int)(resc[0]-48);
                if(resc[3]=='\0')
                    xz=(int)(resc[2]-48)-1;
                else if(resc[4]=='\0')
                {
                    xz=(int)((resc[2]-48)*10)+(int)(resc[3]-48)-1;
                }
            }
            else if(resc[2]==',')
            {
                yz=19-(int)((resc[0]-48)*10)-(int)(resc[1]-48);
                if(resc[4]=='\0')
                    xz=(int)(resc[3]-48)-1;
                else if(resc[5]=='\0')
                {
                    xz=(int)((resc[3]-48)*10)+(int)(resc[4]-48)-1;
                }
            }

            a[xz][yz] = player;
        if(step==361)
        {
            way=3;
            QMessageBox::information(mw, "WIN", "DRAW!", QMessageBox::Ok);
            mw->close();
        }
        if(win()!=0)
        {
            way=3;
            if(win()==1)
                 QMessageBox::information(mw, "FAIL", "ENEMY WIN!", QMessageBox::Ok);
            if(win()==2)
                 QMessageBox::information(mw, "WIN", "YOU WIN!", QMessageBox::Ok);

            mw->close();
        }
        player=3-player;

}
