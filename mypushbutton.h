#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Mypushbutton(QWidget *parent = nullptr);
    Mypushbutton(QString normshape,QString pressshape=0);

    QString normpath;
    QString presspath;
    void jumpup();
    void jumpdown();
signals:

};

#endif // MYPUSHBUTTON_H
