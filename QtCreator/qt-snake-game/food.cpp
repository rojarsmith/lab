#include <QPainter>

#include "constants.h"
#include "food.h"

static const qreal FOOD_RADIUS = 10.0;

Food::Food(qreal x, qreal y)
{
    setPos(x, y);
    setData(GD_Type, GO_Food);
}

QRectF Food::boundingRect() const
{
    return QRectF(-FOOD_RADIUS,    -FOOD_RADIUS,
                   FOOD_RADIUS * 2, FOOD_RADIUS * 2 );
}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}

QPainterPath Food::shape() const
{
    QPainterPath p;
    p.addEllipse(QPointF(FOOD_RADIUS / 2, FOOD_RADIUS / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}
