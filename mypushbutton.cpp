#include "mypushbutton.h"
#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>
Mypushbutton::Mypushbutton(QWidget *parent) : QPushButton(parent)
{

}
Mypushbutton::Mypushbutton(QString normshape,QString pressshape)
{
   this->normpath=normshape;
   this->presspath=normshape;
    QPixmap pix;
    pix.load(normpath);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
void Mypushbutton::jumpdown()
{
    QPropertyAnimation* anima=new QPropertyAnimation(this,"geometry");
    anima->setDuration(50);
    anima->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    anima->setEndValue(QRect(this->x(),this->y()+8,this->width(),this->height()));
    anima->setEasingCurve(QEasingCurve::OutInCirc);
    anima->start();
}
void Mypushbutton::jumpup()
{
    QPropertyAnimation* anima=new QPropertyAnimation(this,"geometry");
    anima->setDuration(50);
    anima->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    anima->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    anima->setEasingCurve(QEasingCurve::OutInCirc);
    anima->start();
}
