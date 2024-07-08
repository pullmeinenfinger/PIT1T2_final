#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "dialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();



    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_TestDrawCity_clicked();

    void on_testmap_clicked();

    void on_actionTest_Mode_triggered();

    void on_testSimple_Draw_clicked();

    void on_testDialog_clicked();

    void on_testStrasse_clicked();

    void on_addCity_clicked();

    void on_FillMap_clicked();

    void on_TestAbstractMap_clicked();

    void on_TestDijkstra_clicked();

    void on_addStrasse_clicked();

    void on_buttonDijkstra_clicked();

    void on_pushButton_clicked();

    void on_uploadButton_clicked();

    void on_actionReset_Scene_triggered();

    void on_actionClear_Map_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QMessageBox msgBox;
    Map map;
    MapIo* mapio;
};
#endif // MAINWINDOW_H
