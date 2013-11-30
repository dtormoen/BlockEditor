#ifndef BLOCKMENU_H
#define BLOCKMENU_H

#include <QFrame>

class BlockMenu : public QFrame
{
public:
    BlockMenu();

private:
    void buildMenu();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

};

#endif BLOCKMENU_H
