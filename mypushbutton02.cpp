#include "mypushbutton02.h"
#include <QPushButton>
#include <QPixmap>
Mypushbutton02::Mypushbutton02(QString _str) : QPushButton(0),pix(_str)
{
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.size()));
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction* action01=new QAction(this);
    action01->setText("迅捷塔");
    this->addAction(action01);
    connect(action01,&QAction::triggered,this,[=](){
       emit choosepowertower();
    });
    QAction* action02=new QAction(this);
    action02->setText("重炮塔");
    this->addAction(action02);
    connect(action02,&QAction::triggered,this,[=](){
        emit choosepowertower02();
    });
}
