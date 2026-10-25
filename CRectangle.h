
#ifndef OOP4_CRECTANGLE_H
#define OOP4_CRECTANGLE_H

#include "Shape.h"

class CRectangle : public Shape
{
private:
    int width;
    int height;

public:
    CRectangle(int x, int y);

    bool contains(int pointX, int pointY) const override;
    void draw(QPainter &painter) const override;
};

#endif