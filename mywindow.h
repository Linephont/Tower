#ifndef MYWINDOW_H
#define MYWINDOW_H
#include "monster.h"
#include "way.h"
#include "tower.h"
#include "bullet.h"
#include <QWidget>
#include <QMediaPlayer>
class Monster;
class Bullet;
class MyWindow : public QWidget
{
    Q_OBJECT
public:

    MyWindow(int _num);
    ~MyWindow();
    int levelnumber;
    QPixmap backgroundpix;
    void DrawBackground(QPainter&);
    void DrawMonster(QPainter&);
    void paintEvent(QPaintEvent*);
    int mon_waves;
    bool gamewin;
    bool gameend;
    QMediaPlayer* mus;
    void makeway();
    void makeway2();
    void makeway3();
    void makebullet(Bullet *bullet);
    int						HP;
    int						MONEY;
    QList<Tower *>			my_towerList;
    QList<Way *>		    my_wayList;
    QList<Monster *>		my_monsterList;
    QList<Bullet *>			my_bulletList;
    bool canBuyTower(int money);
    void drawWave(QPainter *painter);
    void drawHP(QPainter *painter);
    void drawMONEY(QPainter *painter);
    void gameover();
    void HPreduce(int damage = 1);
    void addmoney(int gold);
    void removemonster(Monster *monster);
    void removebullet(Bullet *bullet);
    void puttowersound();
    QList<Monster *> monsterList() const;
public slots:
    void updateMap();
    bool loadWave();
    bool loadWave2();
    bool loadWave3();
signals:
    void sceneback();

};

#endif // MYWINDOW_H
