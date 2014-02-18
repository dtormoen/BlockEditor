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
private:
    QString blockText;
};

class DummyBlock : public QLabel
{
public:
    DummyBlock(Block *block);
private:
    void mousePressEvent(QMouseEvent *event);
};

#endif // BLOCK_H
