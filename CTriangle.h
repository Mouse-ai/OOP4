#ifndef OOP4_CTRIANGLE_H
#define OOP4_CTRIANGLE_H

#include "Shape.h"
#include <QPolygon>

class CTriangle : public Shape
{
private:
    int width;
    int height;
    QPolygon getPolygon() const;

protected:
    bool canResize(int delta) const override;
    void changeSize(int delta) override;

public:
    CTriangle(int x, int y);

    bool contains(int pointX, int pointY) const override;
    void draw(QPainter &painter) const override;
    QRect boundingRect() const override;
};

#endif