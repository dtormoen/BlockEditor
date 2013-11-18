#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>

class Canvas : public QFrame
{
public:
    Canvas();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // CANVAS_H
