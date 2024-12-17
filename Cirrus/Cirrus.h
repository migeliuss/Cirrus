#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QPointF>
#include <QAbstractSlider>
#include <QPixMap>
#include <QFileDialog>
#include <QPainter>

#include "ui_Cirrus.h"
#include "paintscene.h"
#include "actionmanager.h"
#include "drawaction.h"

class Cirrus : public QMainWindow
{
    Q_OBJECT

public:
    Cirrus(QWidget* parent = nullptr);
    Cirrus(int red, int green, int blue, QWidget* parent = nullptr);
    Cirrus(paintScene* scene, QWidget* parent = nullptr);
    ~Cirrus();
    int red;
    int green;
    int blue;
public slots:
    void on_createFile_triggered();
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void on_actionundo_triggered();
    void on_actionredo_triggered();
    void slotTimer();
    void on_brush_clicked(bool checked);
    void on_pen_clicked(bool checked);
    void on_eraser_clicked(bool checked);
    void on_verticalSlider_valueChanged(int value);
    void on_red_valueChanged(int value);
    void on_green_valueChanged(int value);
    void on_blue_valueChanged(int value);

    
private:
    Ui::CirrusClass ui;
    QTimer* timer;
    paintScene *scene;
    QGraphicsScene *rgb;
    QString path;
private:
    void resizeEvent(QResizeEvent* event);
};