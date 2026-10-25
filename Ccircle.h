#ifndef OOP4_CCIRCLE_H
#define OOP4_CCIRCLE_H
#include <QPainter>
#include <QPen>
#include "Shape.h"

class CCircle:public Shape {
private:
    static constexpr int radius = 30;
public:
    CCircle(int x, int y): Shape(x, y) {};
    bool contains(int pointx, int pointy) const override;
    void draw(QPainter &painter) const override;
    QRect boundingRect() const override;
};


#endif