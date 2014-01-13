#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPathItem>
#include <QGraphicsLayoutItem>
#include <QWidget>
#include <Qlabel>

class Block : public QGraphicsPathItem
{
public:
    Block(QString text, QGraphicsItem *parent = 0);
    QString getText();
protected:
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;

    void mousePressEvent(QMouseEvent *event);
private:
    QString blockText;
};

class DummyBlock : public QLabel
{
public:
    DummyBlock(Block *block);
};

#endif // BLOCK_H
