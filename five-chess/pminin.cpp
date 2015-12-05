#include "extern.h"
#include "place.h"
#include "mainwindow.h"
#include <QPainter>
#include <QMessageBox>
void chujie()
{
    if(xz>18) xz=0;
    if(xz<0) xz=18;
    if(yz>18) yz=0;
    if(yz<0) yz=18;
    while(a[xz][yz]!=0)
        xz++;
    if(xz>18) xz=0;
    if(xz<0) xz=18;
    if(yz>18) yz=0;
    if(yz<0) yz=18;
}
void pminin()
{

        int i,j,zf;
        zf=k;
        if(way==2 && k==1)
        {
            m=xz=9;
            n=yz=9;
            chujie();
            k++;

        }

        for(i=0;i<19;i++)
        {
            if(zf!=k) break;
            for(j=0;j<19;j++)
            {
                if(zf!=k) break;
                else if(a[i][j]==1&&k==1&&way==1)//第一步
                {
                    m=xz=i+2;
                    n=yz=j+1;
                    chujie();
                    k++;
                }
                //第一优先级---进攻
                else if(a[i][j]==0 && a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 && a[i+4][j-4]==2 && a[i+5][j-5]==0)//右斜022220
                {
                   xz=i+6;
                   yz=j+6;
                   chujie();
                   if(a[m-1][n]!=0)//判断上次储存的位置是否有效
                   {
                      m=xz;
                      n=yz;
                    }
                    k++;
                }
                else if(a[i][j]==1 && a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 && a[i+4][j-4]==2 && a[i+5][j-5]==0)//右斜122220
                {
                      xz=i+6;
                      yz=j-6;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }
                      k++;
                 }
                 else if(a[i][j]==0 && a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 && a[i+4][j-4]==2 && a[i+5][j-5]==1)//右斜022221
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }
                       k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 && a[i+4][j+4]==2 && a[i+5][j+5]==1)//左斜022221
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 && a[i+4][j+4]==2 && a[i+5][j+5]==0)//左斜022220
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i-1][j]==1 && a[i][j]==2 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==0)//横122220
                  {
                      xz=i+4;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==2 && a[i+5][j]==1)//横022221
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 && a[i][j+4]==2 && a[i][j+5]==1)//竖022221
                  {
                      xz=i;
                      yz=j;

                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==1 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 && a[i][j+4]==2 && a[i][j+5]==0)//竖122220
                  {
                      xz=i;
                      yz=j+5;

                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                   else if(a[i][j]==1 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 && a[i+4][j+4]==2 && a[i+5][j+5]==0)//左斜122220
                  {
                      xz=i+5;
                      yz=j+5;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  //第二优先级---防守
                  else if( a[i-1][j]==0 && a[i][j]==1&& a[i+1][j]==1&&a[i+2][j]==1 && a[i+3][j]==0)//横01110
                  {
                     xz=i-1;
                     yz=j;
                     chujie();
                     while(a[xz][yz]!=0)
                        xz=xz+1;
                     chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                     k++;

                  }
                  else if(a[i][j]==0 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 && a[i][j+4]==0)//竖01110
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 && a[i+4][j+4]==0)//左斜01110
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==1 && a[i+2][j+2]==0 && a[i+3][j+3]==1 && a[i+4][j+4]==1 && a[i+5][j+5]==0)//左斜010110
                  {
                      xz=i+2;
                      yz=j+2;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==0 && a[i+4][j+4]==1 && a[i+5][j+5]==0)//左斜011010
                  {
                      xz=i+3;
                      yz=j+3;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 && a[i+4][j+4]==1 && a[i+5][j+5]==2)//左斜011112
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==2 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==1 && a[i+4][j+4]==1 && a[i+5][j+5]==0)//左斜211110
                  {
                      xz=i+5;
                      yz=j+5;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==1 && a[i+4][j-4]==0)//右斜01110
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j-1]==1 && a[i+2][j-2]==0 && a[i+3][j-3]==1 && a[i+4][j-4]==1 && a[i+5][j-5]==0)//右斜010110
                  {
                      xz=i+2;
                      yz=j-2;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                   else if(a[i][j]==0 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==0 && a[i+4][j-4]==1 && a[i+5][j-5]==0)//右斜011010
                  {
                      xz=i+3;
                      yz=j-3;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                   else if(a[i][j]==2 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==1 && a[i+4][j-4]==1 && a[i+5][j-5]==0)//右斜211110
                  {
                      xz=i+5;
                      yz=j-5;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                   else if(a[i][j]==0 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==1 && a[i+4][j-4]==1 && a[i+5][j-5]==2)//右斜011112
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                   else if(a[i][j]==2 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 && a[i][j+4]==1 && a[i][j+5]==0)//竖211110
                  {
                      xz=i;
                      yz=j+5;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1 && a[i][j+4]==1 && a[i][j+5]==2)//竖011112
                  {
                      xz=i;
                      yz=j;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==2 && a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1 && a[i+4][j]==1 && a[i+5][j]==0)//横211110
                  {
                      xz=i+5;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1 && a[i+4][j]==1 && a[i+5][j]==2)//横011112
                  {
                      xz=i;
                      yz=j;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }

                  else if(a[i][j]==0 && a[i][j+1]==1 && a[i][j+2]==0 && a[i][j+3]==1 && a[i][j+4]==1 && a[i][j+5]==0)//竖010110
                  {
                      xz=i;
                      yz=j+2;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==0 && a[i][j+4]==1 && a[i][j+5]==0)//竖011010
                  {
                      xz=i;
                      yz=j+3;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==1 && a[i+1][j]==1 && a[i+2][j]==0 && a[i+3][j]==1 && a[i+4][j]==1)//横11011
                  {
                      xz=i+2;
                      yz=j;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==1 && a[i][j+1]==1 && a[i][j+2]==0 && a[i][j+3]==1 && a[i][j+4]==1)//竖11011
                  {
                      xz=i;
                      yz=j+2;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i+1][j+1]==1 && a[i+1][j+1]==1 && a[i+2][j+2]==0 && a[i+3][j+3]==1 && a[i+4][j+4]==1)//右斜11011
                  {
                      xz=i+2;
                      yz=j+2;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==1 && a[i+1][j-1]==1 && a[i+2][j-2]==0 && a[i+3][j-3]==1 && a[i+4][j-4]==1)//左斜11011
                  {
                      xz=i+2;
                      yz=j-2;
                      chujie();
                      if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==0 && a[i+4][j]==1 && a[i+5][j]==0)//横011010
                  {
                      xz=i+3;
                      yz=j;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }
                  else if(a[i][j]==0 && a[i+1][j]==1 && a[i+2][j]==0 && a[i+3][j]==1 && a[i+4][j]==1 && a[i+5][j]==0)//横010110
                  {
                      xz=i+2;
                      yz=j;
                      chujie();
                     if(a[m-1][n]!=0)
                      {
                           m=xz;
                           n=yz;
                      }

                      k++;
                  }

                  if(zf!=k) break;
                  }
                  if(zf!=k) break;
                  if(i==19-1 && j==19)//第三优先级---没有威胁,进攻
                  {
                      for(i=0;i<19;i++)
                      {
                          for(j=0;j<19;j++)
                          {

                              if(a[i][j]==0 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==0)//横02220
                              {
                                  xz=i;
                                  yz=j;
                                  chujie();
                                  m=xz;
                                  n=yz;

                                  k++;
                              }
                              if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==2 && a[i][j+4]==0)//竖02220
                              {
                                  xz=i;
                                  yz=j;
                                  chujie();
                                  m=xz;
                                  n=yz;

                                  k++;
                              }
                               else if(a[i][j]==0 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==2 && a[i+4][j+4]==0)//左斜02220
                               {
                                   xz=i;
                                   yz=j;
                                   chujie();
                                   m=xz;
                                   n=yz;

                                   k++;
                               }
                               else if(a[i][j]==0 && a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==2 && a[i+4][j-4]==0)//右斜02220
                               {
                                   xz=i+4;
                                   yz=j-4;
                                   chujie();
                                   m=xz;
                                   n=yz;

                                   k++;
                               }
                               else if(a[i][j]==0 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==0)//横0220
                               {
                                    xz=i+3;
                                    yz=j;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                else if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==0)//竖0220
                               {
                                    xz=i;
                                    yz=j;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                else if(a[i][j]==0 && a[i+1][j+1]==2 && a[i+2][j+2]==2 && a[i+3][j+3]==0)//右斜0220
                               {
                                    xz=i+3;
                                    yz=j+3;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                else if(a[i][j]==0 && a[i+1][j-1]==2 && a[i+2][j-2]==2 && a[i+3][j-3]==0)//左斜0220
                               {
                                    xz=i+3;
                                    yz=j-3;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                 else if(a[i][j]==0 && a[i+1][j]==2 && a[i+2][j]==0 && a[i+3][j]==2 && a[i+4][j]==0)//横02020
                               {
                                    xz=i+2;
                                    yz=j;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                else if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==0 && a[i][j+3]==2 && a[i][j+4]==0)//竖02020
                               {
                                    xz=i;
                                    yz=j+2;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                else if(a[i][j]==0 && a[i+1][j+1]==2 && a[i+2][j+2]==0 && a[i+3][j+3]==2 && a[i+4][j+4]==0)//右斜02020
                               {
                                    xz=i+2;
                                    yz=j+2;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                                 else if(a[i][j]==0 && a[i+1][j-1]==2 && a[i+2][j-2]==0 && a[i+3][j-3]==2 && a[i+4][j-4]==0)//左斜02020
                               {
                                    xz=i+2;
                                    yz=j-2;
                                    chujie();
                                    if(a[m-1][n]!=0)
                                    {
                                       m=xz;
                                       n=yz;
                                    }

                                    k++;
                                }
                               else if((a[i-1][j]!=1 && a[i][j]==1&&a[i+1][j]==1 && a[i+2][j]!=1) || (a[i][j-1]!=1 && a[i][j]==1&&a[i][j+1]==1 && a[i][j+2]!=1) || (a[i-1][j-1]!=1 && a[i][j]==1&&a[i+1][j+1]==1 && a[i+2][j+2]!=1 )|| (a[i-1][j+1]!=1 && a[i][j]==1&&a[i+1][j-1]==1 && a[i+2][j-2]!=1))//横竖斜*11*
                               {
                                   xz=m-1;
                                   yz=n;
                                   chujie();
                                   while(a[xz][yz]!=0)
                                       yz=yz+1;
                                       chujie();
                                       m=xz;
                                       n=yz;

                                       k++;
                               }
                               else if((a[i-1][j-1]!=1 && a[i][j]==1 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]==2)||(a[i-1][j-1]!=2 && a[i][j]==1 && a[i+1][j+1]==1 && a[i+2][j+2]==1 && a[i+3][j+3]!=0))//右斜*1112 2111*
                               {
                                   xz=m-1;
                                   yz=n;
                                   chujie();
                                   while(a[xz][yz]!=0)
                                      yz=yz+1;
                                   chujie();
                                   m=xz;
                                   n=yz;

                                   k++;
                               }
                               else if((a[i-1][j+1]!=1 && a[i][j]==1 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]==2)||(a[i-1][j+1]!=2 && a[i][j]==1 && a[i+1][j-1]==1 && a[i+2][j-2]==1 && a[i+3][j-3]!=0))//左斜*1112 2111*
                               {
                                    xz=m-1;
                                    yz=n;
                                    chujie();
                                    while(a[xz][yz]!=0)
                                        yz=yz+1;
                                    chujie();
                                    m=xz;
                                    n=yz;

                                    k++;
                               }
                               else if(a[xz][yz]==1 && a[xz-1][yz]==0 && a[xz+1][yz]==0 && a[xz][yz-1]==0 && a[xz][yz+1]==0 && a[xz-1][yz-1]==0 && a[xz+1][yz+1]==0 && a[xz-1][yz+1]==0 && a[xz+1][yz-1]==0)//1a
                               {
                                    xz=m-1;
                                    yz=n;
                                    chujie();
                                    while(a[xz][yz]!=0)
                                        yz=yz+1;
                                    m=xz;
                                    n=yz;

                                    k++;
                               }
                               else if(a[i][j-1]==0 && a[i][j]==1 && a[i][j+1]==1 && a[i][j+2]==0 )//竖0110
                               {
                                    xz=m-1;
                                    yz=n;
                                    chujie();
                                    while(a[xz][yz]!=0)
                                       xz=xz-1;
                                   chujie();
                                   m=xz;
                                   n=yz;

                                   k++;

                               }
                               else if(a[i][j]==1 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==0)//横12220
                               {
                                   xz=i+4;
                                   yz=j;
                                   chujie();
                                   m=xz;
                                   n=yz;

                                   k++;
                               }
                               else if(a[i][j]==0 && a[i+1][j]==2 && a[i+2][j]==2 && a[i+3][j]==2 && a[i+4][j]==1)//横02221
                               {
                                     xz=i;
                                     yz=j;
                                     chujie();
                                     m=xz;
                                     n=yz;

                                     k++;
                               }
                               else if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==2 && a[i][j+3]==0 && a[i][j+4]==0)//竖02200
                               {
                                       xz=i;
                                       yz=j+3;
                                       chujie();
                                       m=xz;
                                       n=yz;

                                       k++;
                               }
                               else if(a[i][j]==0 && a[i][j+1]==2 && a[i][j+2]==0 && a[i][j+3]==2 && a[i][j+4]==0)//竖02020
                               {
                                     xz=i;
                                     yz=j+2;
                                     chujie();
                                     m=xz;
                                     n=yz;

                                     k++;
                               }
                               else
                               {
                                    if(way==1)
                                    {
                                        xz=m-1;
                                        yz=n;
                                        chujie();
                                        while(a[xz][yz]!=0)
                                            xz=xz-1;
                                        chujie();
                                        m=xz;
                                        n=yz;
                                        k++;
                                    }
                                    else if(way==2)
                                    {
                                        xz=m+1;
                                        yz=n+1;
                                        chujie();
                                        while(a[xz][yz]!=0)
                                            xz=xz-1;
                                        chujie();
                                        m=xz;
                                        n=yz;
                                        k++;
                                    }
                               }
                               if(zf!=k) break;
                          }
                          if(zf!=k) break;
                      }
                  }
                  if(zf!=k) break;
        }


    a[xz][yz] = player;

    MainWindow *mw=new MainWindow;

    if(win()!=0)
    {
        way=3;
        if(win()==1)
             QMessageBox::information(mw, "Win", "Enemy Win", QMessageBox::Ok);
        if(win()==2)
             QMessageBox::information(mw, "Win", "You Win", QMessageBox::Ok);
        mw->close();
    }
    player=3-player;
    memset(sendc,0,20);
    if(yz>=10)
    {
        sendc[0]=(char)(19-yz+48);
        sendc[1]=',';
        if(xz<10)
        {
            sendc[2]=(char)(xz+1+48);
            sendc[3]='\0';
        }
        else
        {
            sendc[2]=(char)(xz/10+48);
            sendc[3]=(char)(xz-10+1+48);
            sendc[4]='\0';
        }
    }
    else
    {
        sendc[0]=(char)((19-yz)/10+48);
        sendc[1]=(char)((19-yz-10)+48);
        sendc[2]=',';
        if(xz<10)
        {
            sendc[3]=(char)(xz+1+48);
            sendc[4]='\0';
        }
        else
        {
            sendc[3]=(char)(xz/10+48);
            sendc[4]=(char)(xz-10+1+48);
            sendc[5]='\0';
        }
    }
}
