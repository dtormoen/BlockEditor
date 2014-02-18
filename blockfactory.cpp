#include "blockfactory.h"

#include <QGraphicsScene>
#include <QPainter>

BlockFactory::BlockFactory()
{
}

Block* BlockFactory::GetBlock(BlockType type)
{
    return CreateBlock(type);
}

QPixmap BlockFactory::GetDummyBlock(BlockType type)
{
    Block* block = CreateBlock(type);
    QGraphicsScene dummyScene;
    dummyScene.addItem(block);
    QRectF r = block->boundingRect();
    QPixmap pixmap(r.width(), r.height());
    pixmap.fill(QColor(0, 0, 0, 0));
    QPainter painter(&pixmap);
    //painter.setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter.drawRect(r);
    dummyScene.render(&painter, QRectF(), block->sceneBoundingRect());
    painter.end();
    return pixmap;
}

Block* BlockFactory::CreateBlock(BlockType type)
{
    return new Block(QString("Test"));
}
