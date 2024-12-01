#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QPointF>

#include "ui_Cirrus.h"
#include "paintscene.h"

class Cirrus : public QMainWindow
{
    Q_OBJECT

public:
    Cirrus(QWidget* parent = nullptr);
    ~Cirrus();
public slots:
    void on_menuFile_aboutToShow();
    void on_createFile_triggered();
    void slotTimer();
private:
    Ui::CirrusClass ui;
    QTimer* timer;
    paintScene *scene;
private:
    void resizeEvent(QResizeEvent* event);
};