#include "Cirrus.h"
#include "ui_Cirrus.h"

Cirrus::Cirrus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");
    scene = new paintScene();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Cirrus::slotTimer);
    timer->start(100);
}

Cirrus::~Cirrus() {

}

void Cirrus::on_createFile_triggered() {
    ui.graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::white);
}

void Cirrus::on_menuFile_aboutToShow() {

}

void Cirrus::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0, 0, ui.graphicsView->width() - 20, ui.graphicsView->height() - 100);
}

void Cirrus::resizeEvent(QResizeEvent* event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}