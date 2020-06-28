#include "widget.h"
#include "ui_widget.h"
#include "mypushbutton.h"
#include "mywindow.h"
#include <QPainter>
#include <QPixmap>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("少女大战僵尸");
    setFixedSize(658,351);

    const int Levelnumber=3;
    QPushButton* btn[3]={ui->pushButton,ui->pushButton_2,ui->pushButton_3};
    for(int i=0;i<Levelnumber;i++)
       {
        connect(btn[i],&QPushButton::clicked,[=](){
          MyWindow* mywindow01=new MyWindow(i);
          mywindow01->show();
          connect(mywindow01,&MyWindow::sceneback,this,[=](){
              mywindow01->hide();
              this->show();

          });
        });
      }


}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPixmap bbb(":/background.png");
    QPainter paintback(this);
    paintback.drawPixmap(0,0,this->width(),this->height(),bbb);

}
