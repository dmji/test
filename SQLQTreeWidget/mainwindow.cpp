#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTreeWidget>
#include <QInputDialog>
#include <QtWidgets>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    treeClass = new CSQLTree(ui->treeWidget, "Root");
    createActions();

    connect(ui->button_serialize, SIGNAL(clicked()), this, SLOT(on_TreeSerialize()));
    connect(ui->button_deserialize, SIGNAL(clicked()), this, SLOT(on_TreeDeserialize()));
}

void MainWindow::on_TreeSerialize()
{
    treeClass->serialize();
}
void MainWindow::on_TreeDeserialize()
{
    treeClass->deserialize();
}

void MainWindow::on_NodeCreate()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Create node", "Node name:", QLineEdit::Normal, "Default", &ok);
    if(ok && !text.isEmpty())
    {
        auto node = treeClass->findNode(ui->treeWidget->currentItem());
        if(node)
            node->addNode(text);
    }
}

void MainWindow::on_NodeEdit()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Edit node", "New name:", QLineEdit::Normal, "Default", &ok);
    if(ok && !text.isEmpty())
    {
        auto node = treeClass->findNode(ui->treeWidget->currentItem());
        if(node)
            node->editNode(text);
    }
}

void MainWindow::on_NodeDelete()
{
    auto node = treeClass->findNode(ui->treeWidget->currentItem());
    if(node)
        node->deleteNode();
}

MainWindow::~MainWindow()
{

    delete ui;
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(nodeCreateAct);
    menu.addAction(nodeEditAct);
    menu.addAction(nodeDeleteAct);
    menu.exec(event->globalPos());
}

void MainWindow::createActions()
{
    nodeCreateAct = new QAction(tr("&Create"), this);
    nodeCreateAct->setStatusTip(tr("Create a child node"));
    connect(nodeCreateAct, &QAction::triggered, this, &MainWindow::on_NodeCreate);

    nodeEditAct = new QAction(tr("&Edit"), this);
    nodeEditAct->setStatusTip(tr("Edit current node"));
    connect(nodeEditAct, &QAction::triggered, this, &MainWindow::on_NodeEdit);

    nodeDeleteAct = new QAction(tr("&Delete"), this);
    nodeDeleteAct->setStatusTip(tr("Delete current node"));
    connect(nodeDeleteAct, &QAction::triggered, this, &MainWindow::on_NodeDelete);
}
#endif // QT_NO_CONTEXTMENU
