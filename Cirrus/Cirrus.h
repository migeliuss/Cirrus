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

class Cirrus : public QMainWindow
{
    Q_OBJECT

public:
    Cirrus(QWidget* parent = nullptr);
    ~Cirrus();
public slots:
    void on_createFile_triggered();
    void on_openFile_triggered();
    void on_saveFile_triggered();
    void slotTimer();
    void on_brush_clicked(bool checked);
    void on_pen_clicked(bool checked);
    void on_eraser_clicked(bool checked);
    void on_verticalSlider_valueChanged(int value);
    
private:
    Ui::CirrusClass ui;
    QTimer* timer;
    paintScene *scene;
    QString path;
private:
    void resizeEvent(QResizeEvent* event);
};