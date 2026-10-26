#include "CLine.h"

CLine::CLine(int x, int y)
    : Shape(x, y), halfLength(40)
{
}

bool CLine::contains(int pointX, int pointY) const
{
    const int tolerance = 5;

    bool insideX =
        pointX >= x - halfLength &&
        pointX <= x + halfLength;

    bool closeToLine =
        pointY >= y - tolerance &&
        pointY <= y + tolerance;

    return insideX && closeToLine;
}

void CLine::draw(QPainter &painter) const
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

    painter.drawLine(
        x - halfLength,
        y,
        x + halfLength,
        y
    );

    painter.restore();
}

QRect CLine::boundingRect() const
{
    const int margin = 2;

    return QRect(
        x - halfLength,
        y - margin,
        halfLength * 2,
        margin * 2
    );
}

bool CLine::canResize(int delta) const
{
    return halfLength + delta >= 10;
}

void CLine::changeSize(int delta)
{
    halfLength += delta;
}