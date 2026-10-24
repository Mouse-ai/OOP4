#ifndef OOP4_SHAPE_H
#define OOP4_SHAPE_H

#include <QColor>
#include <QPainter>

class Shape
{
protected:
    int x;
    int y;
    QColor color;
    bool selected;

public:
    Shape(int x, int y);

    virtual ~Shape() = default;

    virtual void draw(QPainter &painter) const = 0;
    virtual bool contains(int pointX, int pointY) const = 0;

    bool isSelected() const;
    void setSelected(bool value);
    void toggleSelected();

    void setColor(const QColor &newColor);
};

#endif