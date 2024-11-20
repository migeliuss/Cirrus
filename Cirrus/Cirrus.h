#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include "ui_Cirrus.h"

class Cirrus : public QMainWindow
{
    Q_OBJECT

public:
    Cirrus(QWidget* parent = nullptr);
    ~Cirrus();
public slots:
    void on_btnClose_clicked();
private:
    Ui::CirrusClass ui;
    QGraphicsScene *scene;
};
