#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Cirrus.h"

class Cirrus : public QMainWindow
{
    Q_OBJECT

public:
    Cirrus(QWidget *parent = nullptr);
    ~Cirrus();

private:
    Ui::CirrusClass ui;
};
