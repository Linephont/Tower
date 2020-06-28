#include "bullet.h"
#include "monster.h"
#include "mywindow.h"
#include <QPainter>
#include <QPropertyAnimation>
Bullet::Bullet(MyWindow *game,QPoint startpoi,QPoint targetpoi,Monster *target,int power,int kind)
    : bul_startpoi(startpoi)
    , bul_targetpoi(targetpoi)
    , bul_nowpoi(startpoi)
    , bul_target(target)
    , bul_game(game)
    , bul_power(power)
{
    if(kind==1)
    bul_pix.load(":/bullet01.png");
    if(kind==2)
    bul_pix.load(":/bullet02.png");
}
void Bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(bul_nowpoi, bul_pix);
}
void Bullet::move()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "bul_nowpoi");
    animation->setDuration(80);
    animation->setStartValue(bul_startpoi);
    animation->setEndValue(bul_targetpoi);
    connect(animation, SIGNAL(finished()), this, SLOT(checktarget()));
    animation->start();
}
void Bullet::setnowpoi(QPoint poi)
{
   bul_nowpoi = poi;
}
QPoint Bullet::nowpoi() const
{
    return bul_nowpoi;
}
void Bullet::checktarget()
{
    if (bul_game->monsterList().indexOf(bul_target) != -1)
        bul_target->getattack(bul_power);
    bul_game->removebullet(this);
}
