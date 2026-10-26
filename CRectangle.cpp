//
// Created by alexei on 25.10.2026.
//

#include "CRectangle.h"
CRectangle::CRectangle(int x, int y)
    : Shape(x, y), width(80), height(50)
{
}
bool CRectangle::contains(int pointX, int pointY) const {
    int left = x -width/2;
    int right = x + width/2;
    int top = y -height/2;
    int bottom = y + height/2;
    return left<=pointX && right>=pointX && top<=pointY && bottom>=pointY;
}
void CRectangle::draw(QPainter &painter) const {
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
    painter.drawRect(
    x - width / 2,
    y - height / 2,
    width,
    height
    );
    painter.restore();
}
QRect CRectangle::boundingRect() const
{
    return QRect(
        x - width / 2,
        y - height / 2,
        width,
        height
    );
}
bool CRectangle::canResize(int delta) const
{
    return width + delta >= 20 &&
           height + delta >= 20;
}

void CRectangle::changeSize(int delta)
{
    width += delta;
    height += delta;
}