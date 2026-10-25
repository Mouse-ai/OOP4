//
// Created by alexei on 25.10.2026.
//

#ifndef OOP4_SHAPESTORAGE_H
#define OOP4_SHAPESTORAGE_H
#include <vector>
#include "Shape.h"

class ShapeStorage {
private:
    std::vector<Shape *> shapes;

public:
    void add(Shape *shape);

    int getCount() const;
    Shape *getObject(int index) const;

    void clearSelection();
    void removeSelected();

    ~ShapeStorage();
};


#endif //OOP4_SHAPESTORAGE_H
