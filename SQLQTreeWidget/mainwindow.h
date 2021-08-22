#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CSQLTree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU
    void createActions();
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    QAction *nodeEditAct;
    QAction *nodeDeleteAct;
    QAction *nodeCreateAct;
private slots:
    void on_NodeCreate();
    void on_NodeEdit();
    void on_NodeDelete();
    void on_TreeSerialize();
    void on_TreeDeserialize();

private:
    Ui::MainWindow *ui;
    CSQLTree* treeClass;
};
#endif // MAINWINDOW_H
