#include "blockmenu.h"
#include "block.h"

#include <QLabel>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <iostream>

using namespace std;

BlockMenu::BlockMenu()
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);

    buildMenu();
}

void BlockMenu::buildMenu()
{
    vector<QString> blocks;
    blocks.push_back("These");
    blocks.push_back("Are");
    blocks.push_back("blocks");
    blocks.push_back("And");
    blocks.push_back("I");
    blocks.push_back("Am");
    blocks.push_back("Testing");
    blocks.push_back("Them");

    QVBoxLayout *vLayout = new QVBoxLayout(this);

    int hSize = 2;
    int locCount = 0;

    QHBoxLayout *hLayout = new QHBoxLayout();

    for (QString block : blocks)
    {
        cout << "Adding Block" << endl;
        if (locCount == hSize)
        {
            vLayout->addLayout(hLayout);
            hLayout = new QHBoxLayout();
            locCount = 0;
        }
        Block *temp = new Block(block);
//        temp->setAttribute(Qt::WA_DeleteOnClose);
        hLayout->addWidget(new DummyBlock(temp));
        locCount++;
    }
    vLayout->addLayout(hLayout);
}


void BlockMenu::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void BlockMenu::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void BlockMenu::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->ignore();
        } else
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
    } else
    {
        event->ignore();
    }
}

void BlockMenu::mousePressEvent(QMouseEvent *event)
{
}
