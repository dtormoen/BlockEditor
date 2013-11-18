#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blockmenu.h"
#include "canvas.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(new BlockMenu);
    horizontalLayout->addWidget(new Canvas);

    ui->setupUi(this);

    this->centralWidget()->setLayout(horizontalLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
