#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include <QGraphicsScene>

class Canvas : public QGraphicsScene
{
public:
    Canvas();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent  *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CANVAS_H
