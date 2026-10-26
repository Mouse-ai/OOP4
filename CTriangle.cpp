//
// Created by alexei on 26.10.2026.
//

#include "CTriangle.h"

CTriangle::CTriangle(int x, int y)
    : Shape(x, y), width(80), height(70)
{
}
QPolygon CTriangle::getPolygon() const
{
    QPolygon polygon;

    polygon << QPoint(x, y - height / 2)
            << QPoint(x - width / 2, y + height / 2)
            << QPoint(x + width / 2, y + height / 2);

    return polygon;
}
bool CTriangle::contains(int pointX, int pointY) const
{
    return getPolygon().containsPoint(
        QPoint(pointX, pointY),
        Qt::OddEvenFill
    );
}
void CTriangle::draw(QPainter &painter) const
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

    painter.drawPolygon(getPolygon());

    painter.restore();
}
QRect CTriangle::boundingRect() const
{
    return QRect(
        x - width / 2,
        y - height / 2,
        width,
        height
    );
}
bool CTriangle::canResize(int delta) const
{
    return width + delta >= 20 &&
           height + delta >= 20;
}

void CTriangle::changeSize(int delta)
{
    width += delta;
    height += delta;
}