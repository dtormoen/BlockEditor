#include "block.h"
#include "blockfactory.h"

#include <QLabel>
#include <QLayout>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsProxyWidget>
#include <QPixmap>
#include <QGraphicsScene>
#include <QPainter>

#include <iostream>

using namespace std;

Block::Block(QString text, QGraphicsItem *parent)
{
    QPainterPath p;
    p.addRoundedRect(-50, -15, 100, 30, 5, 5);
    setPath(p);
    setPen(QPen(Qt::darkGreen));
    setBrush(Qt::green);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

QString Block::getText()
{
    return blockText;
}

DummyBlock::DummyBlock(Block *block)
{
    QPixmap pixmap = BlockFactory::GetDummyBlock(BlockType::BLOCK1);
    this->setPixmap(pixmap);
}

void DummyBlock::mousePressEvent(QMouseEvent *event)
{
    cout << "Starting Drag" << endl;

    QByteArray itemData;

    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << QPoint(event->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos());
    drag->setPixmap(this->grab());
    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    {
//        this->close();
    }
}
