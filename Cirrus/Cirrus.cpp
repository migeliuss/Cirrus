#include "Cirrus.h"
#include "ui_Cirrus.h"

Cirrus::Cirrus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");

    scene = new paintScene();
    ui.graphicsView->setBackgroundBrush(Qt::gray);

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

void Cirrus::on_openFile_triggered() {
    QString newPath = QFileDialog::getOpenFileName(this, "Load PNG",
        path, tr("PNG files (*.png)"));

    if (newPath.isEmpty())
        return;
    ui.graphicsView->setScene(scene);

    path = newPath;

    QImage image;
    image.load(path);
    scene->setSceneRect(0, 0, image.width() - 20, image.height() - 20);

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
}
void Cirrus::on_saveFile_triggered() {
    if (!(scene->isActive())) {
        return;
    }
    QString newPath = QFileDialog::getSaveFileName(this, "Save PNG",
        path, tr("PNG files (*.png)"));

    if (newPath.isEmpty()) {
        return;
    }
        
    path = newPath;

    QImage image(scene->width(), scene->height(), QImage::Format_RGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    scene->render(&painter);

    image.save(path);
}

void Cirrus::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0, 0, ui.graphicsView->width() - 20, ui.graphicsView->height() - 20);
}

void Cirrus::resizeEvent(QResizeEvent* event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Cirrus::on_brush_clicked(bool checked) {
    if (checked)
    {
        scene->instrument = 2;

    }
}
void Cirrus::on_pen_clicked(bool checked) {
    if (checked)
    {
        scene->instrument = 1;
    }
}

void Cirrus::on_eraser_clicked(bool checked) {
    if (checked)
    {
        scene->instrument = 3;
    }
}

void Cirrus::on_verticalSlider_valueChanged(int value) {
    scene->brushWidth = value;
}