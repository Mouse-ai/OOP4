//
// Created by alexei on 25.10.2026.
//

#include "ShapeStorage.h"
void ShapeStorage::add(Shape *shape) {
    shapes.push_back(shape);
}
int ShapeStorage::getCount() const {
    return static_cast<int>(shapes.size());
}
Shape *ShapeStorage::getObject(int index) const {
    return shapes[index];
}
void ShapeStorage::clearSelection() {
    for (Shape *shape : shapes) {
        shape->setSelected(false);
    }
}
ShapeStorage::~ShapeStorage() {
    for (Shape *shape : shapes) {
        delete shape;
    }
}

void ShapeStorage::removeSelected() {
    size_t i = 0;
    while (i < shapes.size()) {
        if (shapes[i]->isSelected()) {
            delete shapes[i];
            shapes.erase(shapes.begin()+i);
        }else {
            i++;
        }
    }
}
