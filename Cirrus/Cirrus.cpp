#include "Cirrus.h"

Cirrus::Cirrus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");
    scene = new QGraphicsScene();
}

Cirrus::~Cirrus()
{ }

void Cirrus::on_btnClose_clicked() {
    ui.graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::white);
    ui.btnClose->close();

}