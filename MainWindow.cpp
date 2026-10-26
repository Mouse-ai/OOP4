#include "MainWindow.h"
#include "Ccircle.h"
#include "CRectangle.h"
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setupActions();
    QWidget *workArea = new QWidget(this);
    workArea->setAttribute(Qt::WA_TransparentForMouseEvents);

    setCentralWidget(workArea);
}
void MainWindow::changeSelectedColor()
{
    QColor newColor = QColorDialog::getColor();

    if (!newColor.isValid())
    {
        return;
    }

    for (int i = 0; i < storage.getCount(); i++)
    {
        Shape *shape = storage.getObject(i);

        if (shape->isSelected())
        {
            shape->setColor(newColor);
        }
    }

    storage.clearSelection();
    update();
}
QRect MainWindow::getWorkAreaRect() const
{
    return centralWidget()->geometry();
}
void MainWindow::setupActions()
{
    circleAction = new QAction("Круг", this);
    rectangleAction = new QAction("Прямоугольник", this);
    colorAction = new QAction("Цвет", this);

    connect(colorAction, &QAction::triggered, this, [this]()
    {
        changeSelectedColor();
    });
    connect(circleAction, &QAction::triggered, this, [this]()
{
    currentShapeType = ShapeType::Circle;
});
    connect(rectangleAction, &QAction::triggered, this, [this]() {
        currentShapeType = ShapeType::Rectangle;
    });
    QMenu *shapeMenu = menuBar()->addMenu("Фигура");
    shapeMenu->addAction(circleAction);
    shapeMenu->addAction(rectangleAction);
    QMenu *editMenu = menuBar()->addMenu("Редактирование");
    editMenu->addAction(colorAction);
    QToolBar *toolBar = addToolBar("Фигуры");
    toolBar->addAction(circleAction);
    toolBar->addAction(rectangleAction);
    toolBar->addAction(colorAction);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;

    QPoint point = event->pos();

    bool ctrlPressed =
        event->modifiers() & Qt::ControlModifier;

    bool shapeFound = false;
    for (int i = storage.getCount() - 1; i >= 0; --i)
    {
        Shape *shape = storage.getObject(i);

        if (shape->contains(point.x(), point.y()))
        {
            shapeFound = true;

            if (ctrlPressed)
            {
                shape->toggleSelected();
            }
            else
            {
                storage.clearSelection();
                shape->setSelected(true);
            }

            break;
        }

    }
    if (!shapeFound)
    {
        if (!ctrlPressed)
        {
            storage.clearSelection();
        }
        Shape *newShape = nullptr;

        if (currentShapeType == ShapeType::Circle)
        {
            newShape = new CCircle(point.x(), point.y());
        }
        else if (currentShapeType == ShapeType::Rectangle)
        {
            newShape = new CRectangle(point.x(), point.y());
        }

        if (newShape != nullptr) {
            QRect bounds = getWorkAreaRect();

            if (newShape->fitsInBounds(bounds))
            {
                if (ctrlPressed)
                {
                    newShape->setSelected(true);
                }

                storage.add(newShape);
            }
            else
            {
                delete newShape;
            }
        }
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    QPainter painter(this);

    for (int i = 0; i < storage.getCount(); i++)
    {
        Shape *shape = storage.getObject(i);
        shape->draw(painter);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Delete)
    {
        storage.removeSelected();
        update();
        return;
    }
    if (event->key() == Qt::Key_1)
    {
        currentShapeType = ShapeType::Circle;
        return;
    }

    if (event->key() == Qt::Key_2)
    {
        currentShapeType = ShapeType::Rectangle;
        return;
    }

    int dx = 0;
    int dy = 0;

    if (event->key() == Qt::Key_Left)
    {
        dx = -5;
    }
    else if (event->key() == Qt::Key_Right)
    {
        dx = 5;
    }
    else if (event->key() == Qt::Key_Up)
    {
        dy = -5;
    }
    else if (event->key() == Qt::Key_Down)
    {
        dy = 5;
    }
    if (dx != 0 || dy != 0)
    {
        QRect bounds = getWorkAreaRect();

        for (int i = 0; i < storage.getCount(); i++)
        {
            Shape *shape = storage.getObject(i);

            if (shape->isSelected())
            {
                shape->move(dx, dy, bounds);
            }
        }

        update();
        return;
    }
    if (event->key() == Qt::Key_C)
    {
        changeSelectedColor();
        return;
    }
    int resizeDelta = 0;

    if (event->key() == Qt::Key_Plus)
    {
        resizeDelta = 5;
    }
    else if (event->key() == Qt::Key_Minus)
    {
        resizeDelta = -5;
    }
    if (resizeDelta != 0)
    {
        QRect bounds = getWorkAreaRect();

        for (int i = 0; i < storage.getCount(); i++)
        {
            Shape *shape = storage.getObject(i);

            if (shape->isSelected())
            {
                shape->resize(resizeDelta, bounds);
            }
        }

        update();
        return;
    }
    QMainWindow::keyPressEvent(event);
}