#include "CEllipse.h"

CEllipse::CEllipse(int x, int y)
    : CEllipse(x, y, 45, 30)
{
}

CEllipse::CEllipse(
    int x,
    int y,
    int radiusX,
    int radiusY
)
    : Shape(x, y),
      radiusX(radiusX),
      radiusY(radiusY)
{
}

bool CEllipse::contains(int pointX, int pointY) const
{
    double dx = pointX - x;
    double dy = pointY - y;

    double normalizedX = dx / radiusX;
    double normalizedY = dy / radiusY;

    return normalizedX * normalizedX +
           normalizedY * normalizedY <= 1.0;
}

void CEllipse::draw(QPainter &painter) const
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
        x - radiusX,
        y - radiusY,
        radiusX * 2,
        radiusY * 2
    );

    painter.restore();
}

QRect CEllipse::boundingRect() const
{
    return QRect(
        x - radiusX,
        y - radiusY,
        radiusX * 2,
        radiusY * 2
    );
}

bool CEllipse::canResize(int delta) const
{
    return radiusX + delta >= 10 &&
           radiusY + delta >= 10;
}

void CEllipse::changeSize(int delta)
{
    radiusX += delta;
    radiusY += delta;
}