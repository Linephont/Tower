#include "tower.h"
#include "mywindow.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QVector2D>
#include <QtMath>
#include <QMediaPlayer>
#include "bullet.h"

static QPoint revise(50,60);
Tower::Tower(MyWindow *game,QPoint poi, QString _path,int rate,int damage,int range,int kind)
    : tow_canattack(false)
    , tow_range(range)
    , tow_power(damage)
    , tow_rate(rate)     
    , tow_kind(kind)
    , tow_poi(poi)
    , tow_monster(NULL)
    , tow_game(game)
{
    tow_pix.load(_path);
    tow_ratetimer = new QTimer(this);
    connect(tow_ratetimer, SIGNAL(timeout()), this, SLOT(shoot()));

}

Tower::~Tower()
{
    delete tow_ratetimer;
    tow_ratetimer = NULL;
}
bool cantouch01(QPoint point1, int r1, QPoint point2, int r2)
{
    int x = point1.x() - point2.x();
    int y = point1.y() - point2.y();
    int distance = qSqrt(x * x + y * y);

    if (distance <= r1 + r2)
        return true;

    return false;
}

void Tower::checkinrange()
{
    if (tow_monster)
    {
        QVector2D normalized(tow_monster->poi() - tow_poi);
        normalized.normalize();    
        if (!cantouch01(tow_poi, tow_range, revise+tow_monster->poi(), 1))
            lostmonster();
    }
    else
    {     
        QList<Monster *> enemyList = tow_game->monsterList();
        foreach (Monster *enemy, enemyList)
        {
            if (cantouch01(tow_poi, tow_range, revise+enemy->poi(), 1))
            {
                choosemonster(enemy);
                break;
            }
        }
    }
}
void Tower::draw(QPainter *painter)const
{
    painter->save();
    painter->setPen(Qt::white);   
    painter->drawEllipse(tow_poi, tow_range, tow_range);
    painter->restore();
    QPoint newpoi(tow_poi.x()-25,tow_poi.y()-35);
    painter->drawPixmap(newpoi,tow_pix);
    painter->restore();
}
void Tower::startattackmonster()
{
    tow_ratetimer->start(tow_rate);
}

void Tower::choosemonster(Monster *monster)
{
    tow_monster = monster;
    startattackmonster();
   tow_monster->towerattack(this);
}

void Tower::shoot()
{
    Bullet *bullet = new Bullet(tow_game,tow_poi, tow_monster->poi(), tow_monster,tow_power,tow_kind);
    QMediaPlayer* mus=new QMediaPlayer(this);
    mus->setMedia(QUrl::fromLocalFile("E:/code/tower666002/shoot.mp3"));
    mus->play();
    bullet->move();
    tow_game->makebullet(bullet);
}
void Tower::targetkilled()
{
    if (tow_monster)
        tow_monster = NULL;

    tow_ratetimer->stop();
}
void Tower::lostmonster()
{
    tow_monster->lost(this);
    if (tow_monster)
        tow_monster = NULL;

    tow_ratetimer->stop();
}
