#include "block.h"

#include <QLabel>
#include <QLayout>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QGraphicsProxyWidget>

#include <iostream>

using namespace std;

Block::Block(QString text, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    blockText = text;
    QLabel *label = new QLabel(text);
    layout->addWidget(label);
    this->setLayout(layout);
}

QString Block::getText()
{
    return blockText;
}

void Block::mousePressEvent(QMouseEvent *event)
{
    QByteArray itemData;

    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    dataStream << getText() << QPoint(event->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos());
    drag->setPixmap(this->grab());
    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}
