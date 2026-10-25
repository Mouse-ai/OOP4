#include "MainWindow.h"
#include "Ccircle.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
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

        Shape *newShape = new CCircle(point.x(), point.y());

        if (ctrlPressed)
        {
            newShape->setSelected(true);
        }

        storage.add(newShape);
    }
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

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

    QWidget::keyPressEvent(event);
}