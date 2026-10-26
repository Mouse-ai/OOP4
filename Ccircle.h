#ifndef OOP4_CCIRCLE_H
#define OOP4_CCIRCLE_H
#include <QPainter>
#include <QPen>
#include "Shape.h"

class CCircle:public Shape {
private:
    int radius = 30;
public:
    CCircle(int x, int y): Shape(x, y),radius(30) {};
    bool contains(int pointx, int pointy) const override;
    void draw(QPainter &painter) const override;
    QRect boundingRect() const override;
    bool canResize(int delta) const override;
    void changeSize(int delta) override;
};


#endif