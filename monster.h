#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include "mywindow.h"
class Way;
class QPainter;
class MyWindow;
class Tower;

class Monster : public QObject
{
    Q_OBJECT
public:
    Monster(Way* startWayPoint, MyWindow *game,QString _str,int HP,double speed);
    ~Monster();
    friend bool cantouch(QPoint point1, int r1, QPoint point2, int r2);
    void draw(QPainter *painter)const;
    void move();
    void towerattack(Tower *attacker);
    void lost(Tower *attacker);
    void getattack(int damage);
    void remove();

    QPoint poi() const;
    QPoint truepoi;
public slots:
    void canmove();

private:
    bool			mon_active;
    int				mon_maxHp;
    int				mon_nowHp;
    double			mon_speed;
    QPixmap	mon_pix;
    QPoint			mon_poi;
    Way *		    mon_way;
    MyWindow *	    mon_game;
    QList<Tower *>	mon_TowerList;
};

#endif // ENEMY_H
