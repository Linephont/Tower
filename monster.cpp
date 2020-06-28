#include "monster.h"
#include "way.h"
#include "unity.h"
#include "mywindow.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>
const static QPoint revisepoi(60,200);
Monster::Monster(Way *startWayPoint, MyWindow *game,QString _str,int HP,double speed)
    : QObject(0)
    , mon_active(false)
    , mon_maxHp(HP)
    , mon_nowHp(HP)
    , mon_speed(speed)
    , mon_poi(startWayPoint->getnowpoi())
    , mon_way(startWayPoint->nextpoint())
    , mon_game(game)

{
    truepoi=mon_poi+revisepoi;
    mon_pix.load(_str);
}
Monster::~Monster()
{
    mon_TowerList.clear();
    mon_way = NULL;
    mon_game = NULL;
}
bool cantouch(QPoint point1, int r1, QPoint point2, int r2)
{
    const int x = point1.x() - point2.x();
    const int y = point1.y() - point2.y();
    const int distance = qSqrt(x * x + y * y);

    if (distance <= r1 + r2)
        return true;

    return false;
}
void Monster::canmove()
{
    mon_active = true;
}
void Monster::move()
{
    if (!mon_active)
        return;

    if (cantouch(mon_poi, 1, mon_way->getnowpoi(), 1))
    {
        if (mon_way->nextpoint())
        {
            mon_poi = mon_way->getnowpoi();
            mon_way = mon_way->nextpoint();
        }
        else
        {
            mon_game->HPreduce();
            mon_game->removemonster(this);
        return;
    }
    }
    QPoint targetPoint = mon_way->getnowpoi();
    QVector2D normal(targetPoint - mon_poi);
    normal.normalize();
    mon_poi = mon_poi + normal.toPoint() * mon_speed;
    truepoi=mon_poi+revisepoi;
}
void Monster::draw(QPainter *painter)const
{
    if (!mon_active)
        return;
    static const int Health_Bar_Width=30;
    painter->save();
    QPoint a(20,-10);
    QPoint healthBarPoint = mon_poi+a;
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 4));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)mon_nowHp / mon_maxHp * Health_Bar_Width, 4));
    painter->drawRect(healthBarRect);
    painter->drawPixmap(mon_poi, mon_pix);
    painter->restore();
}
void Monster::remove()
{
    if (mon_TowerList.empty())
        return;
    foreach (Tower *attacker, mon_TowerList)
        attacker->targetkilled();
    mon_game->removemonster(this);
}
void Monster::getattack(int damage)
{
    mon_nowHp -= damage;
    if (mon_nowHp <= 0)
    {      
        mon_game->addmoney(200);
        remove();
    }
}
void Monster::towerattack(Tower *attacker)
{
    mon_TowerList.push_back(attacker);
}
void Monster::lost(Tower *attacker)
{
    mon_TowerList.removeOne(attacker);
}

QPoint Monster::poi() const
{
    return mon_poi;
}
