#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QLabel>

class Block : public QWidget
{
public:
    Block(QString text, QWidget *parent = 0);
    QString getText();
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QString blockText;
};

#endif // BLOCK_H
