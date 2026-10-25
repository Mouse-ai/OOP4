//
// Created by alexei on 24.10.2026.
//

#include "Shape.h"
Shape::Shape(int x, int y): x(x), y(y), color(Qt::black), selected(false){}
bool Shape::isSelected() const {
    return selected;
}
void Shape::setSelected(bool value) {
    selected = value;
}
void Shape:: toggleSelected() {
    selected = !selected;
}
void Shape::setColor(const QColor &newColor) {
    color = newColor;
}
void Shape::move(int dx, int dy, const QRect &bounds)
{
    QRect newRect = boundingRect().translated(dx, dy);

    if (bounds.contains(newRect))
    {
        x += dx;
        y += dy;
    }
}