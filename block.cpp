#include "block.h"

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

Block::Block(QString text, QGraphicsItem *parent) //: QWidget(parent)
{
    QPainterPath p;
    p.addRoundedRect(-50, -15, 100, 30, 5, 5);
    setPath(p);
    setPen(QPen(Qt::darkGreen));
    setBrush(Qt::green);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
//    horzMargin = 20;
//    vertMargin = 5;
//    width = horzMargin;
//    height = vertMargin;
//    QVBoxLayout *layout = new QVBoxLayout();
//    blockText = text;
//    QLabel *label = new QLabel(text);
//    layout->addWidget(label);
//    this->setLayout(layout);
}

QString Block::getText()
{
    return blockText;
}

void Block::mousePressEvent(QMouseEvent *event)
{
//    QByteArray itemData;

//    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

//    dataStream << getText() << QPoint(event->pos());

//    QMimeData *mimeData = new QMimeData;
//    mimeData->setData("application/x-dnditemdata", itemData);

//    QDrag *drag = new QDrag(this);
//    drag->setMimeData(mimeData);
//    drag->setHotSpot(event->pos());
//    drag->setPixmap(this->grab());
//    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
//    {
//        this->close();
//    }
}

QPixmap GetDummyBlock(Block *block)
{
    QGraphicsScene *dummyScene = new QGraphicsScene();
    dummyScene->addItem(block);
    QRectF r = block->boundingRect();
    QPixmap pixmap(r.width(), r.height());
    pixmap.fill(QColor(0, 0, 0, 0));
    QPainter painter(&pixmap);
    //painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter.drawRect(r);
    dummyScene->render(&painter, QRectF(), block->sceneBoundingRect());
    painter.end();
    return pixmap;
}

DummyBlock::DummyBlock(Block *block)
{
    QPixmap pixmap = GetDummyBlock(block);
    this->setPixmap(pixmap);
//    this->swap(GetDummyBlock(block));
}
