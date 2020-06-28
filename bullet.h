#ifndef BULLET_H
#define BULLET_H


#include "mywindow.h"
#include "monster.h"
#include "tower.h"
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
class QPainter;
class Monster;
class MyWindow;
class Bullet : QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint bul_nowpoi READ nowpoi WRITE setnowpoi)

public:
    Bullet(MyWindow *game,QPoint startpoi,  QPoint targetpoi, Monster *target,int power,int kind);
    void draw(QPainter *painter) const;
    void move();
    void setnowpoi(QPoint pos);
    QPoint nowpoi() const;
private slots:
    void checktarget();
private:
    const QPoint	bul_startpoi;
    const QPoint	bul_targetpoi;
    QPixmap	        bul_pix;
    QPoint			bul_nowpoi;
    Monster *		bul_target;
    MyWindow *	    bul_game;
    int				bul_power;
};

#endif // BULLET_H
