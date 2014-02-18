#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blockmenu.h"
#include "canvas.h"

#include <QHBoxLayout>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(new BlockMenu);
    QGraphicsView *canvasView = new QGraphicsView(this);
    canvasView->setAcceptDrops(true);
    horizontalLayout->addWidget(canvasView);

    ui->setupUi(this);

    this->centralWidget()->setLayout(horizontalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
