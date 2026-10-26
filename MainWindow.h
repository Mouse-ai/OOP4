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
#include "QRect"
class MainWindow : public QMainWindow
{
public:
    enum class ShapeType
    {
        Circle,
        Rectangle,
        Square
    };
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void setupActions();
    QRect getWorkAreaRect() const;
    void changeSelectedColor();
    QAction *circleAction;
    QAction *rectangleAction;
    QAction *colorAction;
    QAction *squareAction;
    ShapeStorage storage;
    ShapeType currentShapeType = ShapeType::Circle;

};

#endif