#include "mywindow.h"
#include "monster.h"
#include "mypushbutton02.h"
#include "mypushbutton.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QAction>
#include <QFont>
#include <QtMath>
#include <QMediaPlayer>
MyWindow::MyWindow(int _num):
 levelnumber(_num)
,mon_waves(0)
,gamewin(false)
,gameend(false)
,HP(8)
,MONEY(300)
,mus(NULL)
{
    setWindowTitle("少女大战僵尸");
    setFixedSize(658,351);
     mus=new QMediaPlayer(this);
     if(mus!=NULL)
     {
         mus->setMedia(QUrl::fromLocalFile("E:/code/tower666002/bgm.mp3"));//请务必改为本地文件地址
         mus->play();

     }
    switch(levelnumber)
    {
      case 0:
       { 
        makeway();
        Mypushbutton* backbtn=new Mypushbutton(":/back.png");
        backbtn->setParent(this);
        backbtn->move(580,280);
        connect(backbtn,&QPushButton::clicked,this,[=](){
            backbtn->jumpdown();
            backbtn->jumpup();
            QTimer::singleShot(350,this,[=](){
                emit sceneback();
            });
        });
        Mypushbutton02* towerbtn01=new Mypushbutton02(":/keng.png");
        towerbtn01->setParent(this);
        towerbtn01->move(160,140);
        connect(towerbtn01,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(200,156),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn01->hide();
            }
        });
        connect(towerbtn01,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(200,156),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn01->hide();
            }
        });
        Mypushbutton02* towerbtn02=new Mypushbutton02(":/keng.png");
        towerbtn02->setParent(this);
        towerbtn02->move(330,230);
        connect(towerbtn02,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
                puttowersound();
                QString towpath02=":/yasina.png";
                Tower* tower02=new Tower(this,QPoint(370,246),towpath02,500,8,150,1);
                my_towerList.push_back(tower02);
                MONEY-=150;
                towerbtn02->hide();
            }

        });
        connect(towerbtn02,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
                puttowersound();
                QString towpath02=":/wei01.png";
                Tower* tower02=new Tower(this,QPoint(370,246),towpath02,1400,35,120,2);
                my_towerList.push_back(tower02);
                MONEY-=200;
                towerbtn02->hide();
            }

        });
        Mypushbutton02* towerbtn03=new Mypushbutton02(":/keng.png");
        towerbtn03->setParent(this);
        towerbtn03->move(400,130);
        connect(towerbtn03,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
                puttowersound();
                QString towpath02=":/yasina.png";
                Tower* tower03=new Tower(this,QPoint(440,140),towpath02,500,8,150,1);
                my_towerList.push_back(tower03);
                MONEY-=150;
                towerbtn03->hide();
            }

        });
        connect(towerbtn03,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
                puttowersound();
                QString towpath02=":/wei01.png";
                Tower* tower03=new Tower(this,QPoint(440,140),towpath02,1400,35,120,2);
                my_towerList.push_back(tower03);
                MONEY-=200;
                towerbtn03->hide();
            }

        });
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
        timer->start(20);
        QTimer::singleShot(300, this, SLOT(loadWave()));
        break;
        }
     case 1:
    {       
        makeway2();
        Mypushbutton* backbtn=new Mypushbutton(":/back.png");
        backbtn->setParent(this);
        backbtn->move(580,280);
        connect(backbtn,&QPushButton::clicked,this,[=](){
            backbtn->jumpdown();
            backbtn->jumpup();
            QTimer::singleShot(350,this,[=](){
                emit sceneback();
            });

        });
        Mypushbutton02* towerbtn01=new Mypushbutton02(":/keng02.png");
        towerbtn01->setParent(this);
        towerbtn01->move(160,230);
        connect(towerbtn01,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(200,250),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn01->hide();
            }
        });
        connect(towerbtn01,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(200,250),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn01->hide();
            }
        });
        Mypushbutton02* towerbtn02=new Mypushbutton02(":/keng02.png");
        towerbtn02->setParent(this);
        towerbtn02->move(290,230);
        connect(towerbtn02,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(330,250),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn02->hide();
            }
        });
        connect(towerbtn02,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(330,250),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn02->hide();
            }
        });
        Mypushbutton02* towerbtn03=new Mypushbutton02(":/keng02.png");
        towerbtn03->setParent(this);
        towerbtn03->move(420,200);
        connect(towerbtn03,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(460,220),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn03->hide();
            }
        });
        connect(towerbtn03,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(460,220),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn03->hide();
            }
        });
        Mypushbutton02* towerbtn04=new Mypushbutton02(":/keng02.png");
        towerbtn04->setParent(this);
        towerbtn04->move(520,200);
        connect(towerbtn04,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(560,220),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn04->hide();
            }
        });
        connect(towerbtn04,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(560,220),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn04->hide();
            }
        });
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
        timer->start(25);
        QTimer::singleShot(300, this, SLOT(loadWave2()));
        break;
    }
     case 2:
    {       
        makeway3();
        Mypushbutton* backbtn=new Mypushbutton(":/back.png");
        backbtn->setParent(this);
        backbtn->move(580,280);
        connect(backbtn,&QPushButton::clicked,this,[=](){
            backbtn->jumpdown();
            backbtn->jumpup();
            QTimer::singleShot(350,this,[=](){
                emit sceneback();
            });

        });
        Mypushbutton02* towerbtn01=new Mypushbutton02(":/keng03.png");
        towerbtn01->setParent(this);
        towerbtn01->move(60,230);
        connect(towerbtn01,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(100,250),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn01->hide();
            }
        });
        connect(towerbtn01,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(100,250),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn01->hide();
            }
        });
        Mypushbutton02* towerbtn02=new Mypushbutton02(":/keng03.png");
        towerbtn02->setParent(this);
        towerbtn02->move(170,130);
        connect(towerbtn02,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(210,150),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn02->hide();
            }
        });
        connect(towerbtn02,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(210,150),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn02->hide();
            }
        });
        Mypushbutton02* towerbtn03=new Mypushbutton02(":/keng03.png");
        towerbtn03->setParent(this);
        towerbtn03->move(250,130);
        connect(towerbtn03,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(290,150),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn03->hide();
            }
        });
        connect(towerbtn03,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(290,150),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn03->hide();
            }
        });
        Mypushbutton02* towerbtn04=new Mypushbutton02(":/keng03.png");
        towerbtn04->setParent(this);
        towerbtn04->move(330,220);
        connect(towerbtn04,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(370,240),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn04->hide();
            }
        });
        connect(towerbtn04,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(370,240),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn04->hide();
            }
        });
        Mypushbutton02* towerbtn05=new Mypushbutton02(":/keng03.png");
        towerbtn05->setParent(this);
        towerbtn05->move(410,220);
        connect(towerbtn05,&Mypushbutton02::choosepowertower,this,[=](){
            if(canBuyTower(150))
            {
             puttowersound();
             QString towpath01=":/yasina.png";
             Tower* tower01=new Tower(this,QPoint(450,240),towpath01,500,8,150,1);
             my_towerList.push_back(tower01);
             MONEY-=150;
             towerbtn05->hide();
            }
        });
        connect(towerbtn05,&Mypushbutton02::choosepowertower02,this,[=](){
            if(canBuyTower(200))
            {
             puttowersound();
             QString towpath01=":/wei01.png";
             Tower* tower01=new Tower(this,QPoint(450,240),towpath01,1400,35,120,2);
             my_towerList.push_back(tower01);
             MONEY-=200;
             towerbtn05->hide();
            }
        });
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
        timer->start(25);
        QTimer::singleShot(300, this, SLOT(loadWave3()));
        break;
    }
    }
 }
void MyWindow::updateMap()
{
    foreach (Monster *enemy, my_monsterList)
        enemy->move();
    foreach (Tower *tower, my_towerList)
        tower->checkinrange();
    update();
}
void MyWindow::DrawBackground(QPainter &painter)
{
    painter.drawPixmap(0,0,this->width(),this->height(),backgroundpix);
}
void MyWindow::paintEvent(QPaintEvent *)
{
    if (gameend || gamewin)
    {
        if(gamewin==true)
        {

            QPixmap win;
            win.load(":/win.png");
            QPainter painter(this);
            painter.drawPixmap(-60,-65,win);
        }
        else
        {
            QPixmap lost;
            lost.load(":/lost.png");
            QPainter painter(this);
            painter.drawPixmap(0,-100,lost);
        }
        return;
    }
    QString scenepath01=":/level01background.png";
    QString scenepath02=":/level02background.jpg";
    QString scenepath03=":/level03background.png";
    QPixmap aaa;
    if(levelnumber==0)
        aaa.load(scenepath01);
    if(levelnumber==1)
        aaa.load(scenepath02);
    if(levelnumber==2)
        aaa.load(scenepath03);
    QPainter pa(&aaa);
    foreach (const Tower *tower, my_towerList)
        tower->draw(&pa);
    foreach (const Monster *monster, my_monsterList)
        monster->draw(&pa);
    foreach (const Bullet *bullet, my_bulletList)
        bullet->draw(&pa);
    drawHP(&pa);
    drawMONEY(&pa);
    QPainter painter(this);
    painter.drawPixmap(0,0,aaa);
}
bool MyWindow::loadWave()
{
        if (mon_waves >=2)
            return false;
        Way *startwayPoint = my_wayList.back();
        int monsterstartinterval01[] = { 100, 1000};
        for (int i = 0; i < 2; i++)
        {
            QString str01=":/jiang.png";
            Monster *enemy = new Monster (startwayPoint, this,str01,60,1.0);
            my_monsterList.push_back(enemy);
            QTimer::singleShot(monsterstartinterval01[i], enemy, SLOT(canmove()));
        }
        int monsterstartinterval02[] = { 3000, 3700,4300,5000};
        for (int i = 0; i < 3; i++)
        {
            QString str01=":/qiqiu01.png";
            Monster *enemy = new Monster (startwayPoint, this,str01,20,2.0);
            my_monsterList.push_back(enemy);
            QTimer::singleShot(monsterstartinterval02[i], enemy, SLOT(canmove()));
        }
        return true;
}
bool MyWindow::loadWave2()
{
    if (mon_waves >=3)
        return false;
    Way *startwayPoint = my_wayList.back();
    int monsterstartinterval01[] = { 100, 1000,1900,2800};
    for (int i = 0; i < 4; i++)
    {
        QString str01=":/jiang.png";
        Monster *monster = new Monster (startwayPoint, this,str01,60,1.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval01[i], monster, SLOT(canmove()));
    }
    int monsterstartinterval02[] = { 3000, 3700,4300,5000,5900};
    for (int i = 0; i < 5; i++)
    {
        QString str01=":/qiqiu01.png";
        Monster *monster = new Monster (startwayPoint, this,str01,20,2.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval02[i], monster, SLOT(canmove()));
    }
    int monsterstartinterval03[] = { 7000, 10000};
    for (int i = 0; i < 2; i++)
    {
        QString str01=":/shuitong.png";
        Monster *monster = new Monster (startwayPoint, this,str01,200,1.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval03[i], monster, SLOT(canmove()));
    }
    return true;
}
bool MyWindow::loadWave3()
{
    if (mon_waves >=2)
        return false;
    Way *startwayPoint = my_wayList.back();
    int monsterstartinterval01[] = { 100, 1000,5000,6000,7000};
    for (int i = 0; i < 5; i++)
    {
        QString str01=":/jiang.png";
        Monster *monster = new Monster (startwayPoint, this,str01,60,1.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval01[i], monster, SLOT(canmove()));
    }
    int monsterstartinterval02[] = { 3000, 3700,4300,5000,5900};
    for (int i = 0; i < 5; i++)
    {
        QString str01=":/qiqiu01.png";
        Monster *monster = new Monster (startwayPoint, this,str01,20,2.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval02[i], monster, SLOT(canmove()));
    }
    int monsterstartinterval03[] = { 9000, 11000,13000};
    for (int i = 0; i < 3; i++)
    {
        QString str01=":/shuitong.png";
        Monster *monster = new Monster (startwayPoint, this,str01,200,1.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval03[i], monster, SLOT(canmove()));
    }
    int monsterstartinterval04[] = { 18000};
    for (int i = 0; i < 1; i++)
    {
        QString str01=":/ju.png";
        Monster *monster = new Monster (startwayPoint, this,str01,400,1.0);
        my_monsterList.push_back(monster);
        QTimer::singleShot(monsterstartinterval04[i], monster, SLOT(canmove()));
    }
    return true;
}
void MyWindow::makeway()
{
    Way *theway8 = new Way(QPoint(640, 50));
    my_wayList.push_back(theway8);

    Way *theway7 = new Way(QPoint(510, 50));
    my_wayList.push_back(theway7);
    theway7->setnextpoint(theway8);

    Way *theway6 = new Way(QPoint(510, 125));
    my_wayList.push_back(theway6);
    theway6->setnextpoint(theway7);

    Way *theway5 = new Way(QPoint(320, 125));
    my_wayList.push_back(theway5);
    theway5->setnextpoint(theway6);

    Way *theway4 = new Way(QPoint(320, 40));
    my_wayList.push_back(theway4);
    theway4->setnextpoint(theway5);

    Way *theway3 = new Way(QPoint(100, 40));
    my_wayList.push_back(theway3);
    theway3->setnextpoint(theway4);

    Way *theway2 = new Way(QPoint(100, 140));
    my_wayList.push_back(theway2);
    theway2->setnextpoint(theway3);

    Way *theway1 = new Way(QPoint(20, 140));
    my_wayList.push_back(theway1);
    theway1->setnextpoint(theway2);
}
void MyWindow::makeway2()
{
    Way *theway6 = new Way(QPoint(630, 95));
    my_wayList.push_back(theway6);

    Way *theway5 = new Way(QPoint(420, 95));
    my_wayList.push_back(theway5);
    theway5->setnextpoint(theway6);

    Way *theway4 = new Way(QPoint(420, 30));
    my_wayList.push_back(theway4);
    theway4->setnextpoint(theway5);

    Way *theway3 = new Way(QPoint(310, 30));
    my_wayList.push_back(theway3);
    theway3->setnextpoint(theway4);

    Way *theway2 = new Way(QPoint(310, 130));
    my_wayList.push_back(theway2);
    theway2->setnextpoint(theway3);

    Way *theway1 = new Way(QPoint(20, 130));
    my_wayList.push_back(theway1);
    theway1->setnextpoint(theway2);
}
void MyWindow::makeway3()
{
    Way *theway6 = new Way(QPoint(560, 120));
    my_wayList.push_back(theway6);

    Way *theway5 = new Way(QPoint(310, 120));
    my_wayList.push_back(theway5);
    theway5->setnextpoint(theway6);

    Way *theway4 = new Way(QPoint(310, 30));
    my_wayList.push_back(theway4);
    theway4->setnextpoint(theway5);

    Way *theway3 = new Way(QPoint(95, 30));
    my_wayList.push_back(theway3);
    theway3->setnextpoint(theway4);

    Way *theway2 = new Way(QPoint(95, 130));
    my_wayList.push_back(theway2);
    theway2->setnextpoint(theway3);

    Way *theway1 = new Way(QPoint(20, 130));
    my_wayList.push_back(theway1);
    theway1->setnextpoint(theway2);
}
QList<Monster*> MyWindow::monsterList() const
{
    return my_monsterList;
}
void MyWindow::removebullet(Bullet *bullet)
{
    Q_ASSERT(bullet);
    my_bulletList.removeOne(bullet);
    delete bullet;
}
void MyWindow::removemonster(Monster *monster)
{
    Q_ASSERT(monster);
    my_monsterList.removeOne(monster);
    delete monster;
    if (my_monsterList.empty())
    {
        ++mon_waves;
        if (!loadWave())
        {
            gamewin = true;
        }
    }
}
void MyWindow::makebullet(Bullet *bullet)
{
    Q_ASSERT(bullet);
    my_bulletList.push_back(bullet);
}
void MyWindow::drawHP(QPainter *painter)
{
    QFont font;
    font.setPointSize(15);
    font.setFamily("宋体");
    painter->setPen(QPen(Qt::blue));
    painter->setFont(font);
    painter->drawText(QRect(50, 8, 150, 30), QString("HP : %1").arg(HP));
}
void MyWindow::drawMONEY(QPainter *painter)
{
    QFont font;
    font.setPointSize(15);
    font.setFamily("宋体");
    painter->setPen(QPen(Qt::blue));
    painter->setFont(font);
    painter->drawText(QRect(250, 8, 200, 30), QString("MONEY : %1").arg(MONEY));
}
void MyWindow::addmoney(int money)
{
    MONEY += money;
    update();
}
void MyWindow::HPreduce(int damage)
{
    QMediaPlayer* mus=new QMediaPlayer(this);
    mus->setMedia(QUrl::fromLocalFile("E:/code/tower666002/reduceHP.mp3"));//请务必改为本地文件地址
    mus->play();
    HP -= damage;
    if (HP <= 0)
        gameover();
}
bool MyWindow::canBuyTower(int money)
{
    if (MONEY >= money)
        return true;
    return false;
}
void MyWindow::gameover()
{
    if (!gameend)
    {
        gameend = true;
    }
}
void MyWindow::puttowersound()
{
    QMediaPlayer* mus=new QMediaPlayer(this);
    mus->setMedia(QUrl::fromLocalFile("E:/code/tower666002/towerput.mp3"));//请务必改为本地文件地址
    mus->play();
}
MyWindow::~MyWindow()
{
    mus=NULL;
}
