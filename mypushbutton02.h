#ifndef MYPUSHBUTTON02_H
#define MYPUSHBUTTON02_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QAction>
class Mypushbutton02 : public QPushButton
{
    Q_OBJECT
public:
    Mypushbutton02(QString str);
    QPixmap pix;
signals:
  void choosepowertower();
  void choosepowertower02();
};

#endif // MYPUSHBUTTON02_H
