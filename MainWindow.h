#ifndef OOP4_MAINWINDOW_H
#define OOP4_MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include "ShapeStorage.h"
#include <QRect>
#include <QResizeEvent>
class MainWindow : public QMainWindow
{
public:
    enum class ShapeType
    {
        Circle,
        Rectangle,
        Square,
        Triangle,
        Ellipse,
        Line
    };
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void setupActions();
    QRect getWorkAreaRect() const;
    void changeSelectedColor();
    QAction *circleAction;
    QAction *rectangleAction;
    QAction *colorAction;
    QAction *triangleAction;
    QAction *squareAction;
    QAction *ellipseAction;
    QAction *lineAction;
    ShapeStorage storage;
    ShapeType currentShapeType = ShapeType::Circle;

};

#endif