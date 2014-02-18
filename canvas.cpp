#include "canvas.h"
#include "block.h"
#include "blockfactory.h"

#include <QLabel>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>

#include <iostream>

using namespace std;

Canvas::Canvas()
{ }

void Canvas::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    cout << "DragEnter" << endl;
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this->parent()) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Canvas::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    cout << "DragLeave" << endl;
//    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
//        if (event->source() == this) {
//            event->setDropAction(Qt::MoveAction);
//            event->accept();
//        } else {
//            event->acceptProposedAction();
//        }
//    } else {
//        event->ignore();
//    }
}

void Canvas::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    cout << "DragMove" << endl;
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this->parent()) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Canvas::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    cout << "Drop event" << endl;
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        cout << "Drop!" << endl;

        QString text;
        QPoint offset;
        dataStream >> text >> offset;

        Block *block = BlockFactory::GetBlock(BlockType::BLOCK1);
        this->addItem(block);

//        block->move(event->pos() - offset);
//        block->moveBy(/**/
//        block->setAttribute(Qt::WA_DeleteOnClose);
        block->show();

        if (event->source()->parent() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}
