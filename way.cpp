#include "way.h"
#include <QPainter>
#include <QColor>

Way::Way(QPoint poi)
    : way_poi(poi)
    , way_nextpoint(NULL)
{
}

void Way::setnextpoint(Way *nextPoint)
{
    way_nextpoint = nextPoint;
}

Way* Way::nextpoint()
{
    return way_nextpoint;
}

QPoint Way::getnowpoi()
{
    return way_poi;
}

