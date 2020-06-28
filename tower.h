#ifndef TOWER_H
#define TOWER_H
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
class QPainter;
class Monster;
class MyWindow;
class QTimer;
class Tower : QObject
{
    Q_OBJECT
public:
    Tower(MyWindow *game,QPoint poi,  QString _path,int rate,int damage,int range,int kind);
    ~Tower();
    friend bool cantouch01(QPoint point1, int r1, QPoint point2, int r2);
    void draw(QPainter *painter) const;
    void checkinrange();
    void targetkilled();
    void startattackmonster();
    void choosemonster(Monster *monster);
    void lostmonster();
    QPoint revisepoi;
private slots:
    void shoot();
private:
    bool			tow_canattack;
    int				tow_range;
    int				tow_power;
    int				tow_rate;
    int             tow_kind;
    QPoint	tow_poi;
    Monster *		tow_monster;
    MyWindow *	    tow_game;
    QTimer *		tow_ratetimer;
    QPixmap	tow_pix;
};

#endif // TOWER_H
