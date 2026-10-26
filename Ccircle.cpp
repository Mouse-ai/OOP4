
#include "Ccircle.h"

bool CCircle::contains(int pointX, int pointY) const
{
    int dx = pointX - x;
    int dy = pointY - y;

    return dx * dx + dy * dy <= radius * radius;
}
void CCircle::draw(QPainter &painter) const
{
    painter.save();
    QPen pen;
    if (selected)
    {
        pen.setColor(Qt::red);
    }
    else
    {
        pen.setColor(color);
    }
    pen.setWidth(3);

    painter.setPen(pen);
    painter.drawEllipse(
        x - radius,
        y - radius,
        radius * 2,
        radius * 2
    );
    painter.restore();
}
QRect CCircle::boundingRect() const
{
    return QRect(
        x - radius,
        y - radius,
        radius * 2,
        radius * 2
    );
}
bool CCircle::canResize(int delta) const
{
    return radius + delta >= 10;
}

void CCircle::changeSize(int delta)
{
    radius += delta;
}