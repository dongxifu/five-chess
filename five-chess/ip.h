#ifndef IP_H
#define IP_H
#include <QDialog>
#include <WinSock2.h>
namespace Ui {
class ip;
}

class ip : public QDialog
{
    Q_OBJECT

public:
    explicit ip(QWidget *parent = 0);
    ~ip();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::ip *ui;
};

#endif // IP_H
