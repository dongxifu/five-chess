#include "client-server.h"
#include "ip.h"
#include "extern.h"
#include "pminin.h"
#include "mainwindow.h"
#include "place.h"
#include <WinSock2.h>
#include <QMessageBox>
#include <Windows.h>
#include <process.h>
void client()
{

  WSADATA WSAData;
  SOCKADDR_IN ClientAddr;
  char *IP;
  QByteArray temp=IP2.toLatin1();
  IP=temp.data();
  ip *ipw=new ip;
    if(WSAStartup(MAKEWORD(2,2),&WSAData)==SOCKET_ERROR)
    {
        QMessageBox::warning(ipw,"warning","start error",QMessageBox::Yes);
        ipw->close();
    }
    if((sock1=socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR)
    {
      WSACleanup();
       QMessageBox::warning(ipw,"warning","socket error",QMessageBox::Yes);
      ipw->close();
    }
    ClientAddr.sin_family=AF_INET;
    ClientAddr.sin_port=htons(999);
    ClientAddr.sin_addr.s_addr=inet_addr(IP);
    if(WSAConnect(sock1,(LPSOCKADDR)&ClientAddr,sizeof(ClientAddr),NULL,NULL,NULL,NULL)==SOCKET_ERROR)
    {
       QMessageBox::warning(ipw,"warning","connect error",QMessageBox::Yes);
       closesocket(sock1);
       WSACleanup();
       ipw->close();
    }
}
void server()
{
     WSADATA WSAData;
     SOCKADDR_IN ServerAddr;
     MainWindow *ww=new MainWindow;
     if(WSAStartup(MAKEWORD(2,2),&WSAData)==SOCKET_ERROR)
     {
         QMessageBox::warning(ww,"warning","start error",QMessageBox::Yes);
         ww->close();
     }

     if((sock=socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR)
     {
        QMessageBox::warning(ww,"warning","socket error",QMessageBox::Yes);
        WSACleanup();
        ww->close();
     }

     ServerAddr.sin_family=AF_INET;
     ServerAddr.sin_port=htons(999);
     ServerAddr.sin_addr.s_addr=INADDR_ANY;
     if(bind(sock,(LPSOCKADDR)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR)
     {
        QMessageBox::warning(ww,"warning","bind error",QMessageBox::Yes);
        closesocket(sock);
        WSACleanup();
        ww->close();
     }

     if(listen(sock,10)==SOCKET_ERROR)
     {
         QMessageBox::warning(ww,"warning","listen error",QMessageBox::Yes);
         closesocket(sock);
         WSACleanup();
         ww->close();
     }
     if((sock2=WSAAccept(sock,NULL,NULL,NULL,NULL))==INVALID_SOCKET)
     {
         QMessageBox::warning(ww,"warning","accept error",QMessageBox::Yes);
         closesocket(sock);
         WSACleanup();
         ww->close();
     }

}
