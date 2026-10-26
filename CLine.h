
#ifndef OOP4_CLINE_H
#define OOP4_CLINE_H

#include "Shape.h"

class CLine : public Shape
{
private:
    int halfLength;

protected:
    bool canResize(int delta) const override;
    void changeSize(int delta) override;

public:
    CLine(int x, int y);

    bool contains(int pointX, int pointY) const override;
    void draw(QPainter &painter) const override;
    QRect boundingRect() const override;
};

#endif