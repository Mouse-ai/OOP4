#ifndef OOP4_MAINWINDOW_H
#define OOP4_MAINWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>

#include "ShapeStorage.h"

class MainWindow : public QWidget
{
public:
    enum class ShapeType
    {
        Circle,
        Rectangle
    };
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    ShapeStorage storage;
    ShapeType currentShapeType = ShapeType::Circle;

};

#endif