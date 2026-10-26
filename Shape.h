#ifndef OOP4_SHAPE_H
#define OOP4_SHAPE_H

#include <QColor>
#include <QPainter>
#include <QRect>

class Shape
{
protected:
    int x;
    int y;
    QColor color;
    bool selected;
    virtual bool canResize(int delta) const = 0;
    virtual void changeSize(int delta) = 0;

public:
    Shape(int x, int y);

    virtual ~Shape() = default;

    virtual void draw(QPainter &painter) const = 0;
    virtual bool contains(int pointX, int pointY) const = 0;

    bool isSelected() const;
    void setSelected(bool value);
    void toggleSelected();
    void move(int dx, int dy, const QRect &bounds);

    virtual QRect boundingRect() const = 0;
    void setColor(const QColor &newColor);
    void resize(int delta, const QRect &bounds);
    bool fitsInBounds(const QRect &bounds) const;
};

#endif