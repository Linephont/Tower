#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QPoint>

class QPainter;
class Way
{
public:
    Way(QPoint poi);
    void setnextpoint(Way *nextPoint);
    Way* nextpoint() ;
    QPoint getnowpoi() ;
private:
    QPoint		way_poi;
    Way *			way_nextpoint;
};

#endif // WAYPOINT_H
