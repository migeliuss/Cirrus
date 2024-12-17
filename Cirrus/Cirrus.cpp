#include "Cirrus.h"

Cirrus::Cirrus(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");

    scene = new paintScene();
    ui.graphicsView->setBackgroundBrush(Qt::gray);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cirrus::slotTimer);
    timer->start(100);

    rgb = new QGraphicsScene();
    red = green = blue = 0;
}

Cirrus::Cirrus(int red, int green, int blue, QWidget* parent)
    : QMainWindow(parent), red(red), green(green), blue(blue)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");

    scene = new paintScene();
    ui.graphicsView->setBackgroundBrush(Qt::gray);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cirrus::slotTimer);
    timer->start(100);

    rgb = new QGraphicsScene();
    ui.brushRGB->setScene(rgb);
    ui.brushRGB->setBackgroundBrush(QBrush(QColor(red, green, blue, 255)));
}

Cirrus::Cirrus(paintScene* scene, QWidget* parent)
    : QMainWindow(parent), red(0), green(0), blue(0), scene(scene)
{
    ui.setupUi(this);
    setWindowTitle("Cirrus");

    ui.graphicsView->setBackgroundBrush(Qt::gray);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Cirrus::slotTimer);
    timer->start(100);

    rgb = new QGraphicsScene();
}

Cirrus::~Cirrus() {
    delete scene;
    delete timer;
    delete rgb;
}

void Cirrus::on_createFile_triggered() {
    ui.graphicsView->setScene(scene);
    ui.graphicsView->setBackgroundBrush(QBrush(Qt::lightGray, Qt::Dense2Pattern));
}

void Cirrus::on_openFile_triggered() {
    QString newPath = QFileDialog::getOpenFileName(this, "Load PNG", path, tr("PNG files (*.png)"));
    if (newPath.isEmpty()) return;

    path = newPath;

    QImage image;
    if (!image.load(path)) {
        return;
    }

    scene->setSceneRect(0, 0, image.width() - 20, image.height() - 20);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
}

void Cirrus::on_saveFile_triggered() {
    if (!scene->isActive()) {
        return;
    }

    QString newPath = QFileDialog::getSaveFileName(this, "Save PNG", path, tr("PNG files (*.png)"));
    if (newPath.isEmpty()) {
        return;
    }

    path = newPath;

    QImage image(scene->width(), scene->height(), QImage::Format_RGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    scene->render(&painter);

    if (!image.save(path)) {
    }
}

void Cirrus::slotTimer() {
    timer->stop();
    scene->setSceneRect(0, 0, ui.graphicsView->width() - 20, ui.graphicsView->height() - 20);
}

void Cirrus::resizeEvent(QResizeEvent* event) {
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Cirrus::on_brush_clicked(bool checked) {
    if (checked) {
        scene->instrument = 2;
    }
}

void Cirrus::on_pen_clicked(bool checked) {
    if (checked) {
        scene->instrument = 1;
    }
}

void Cirrus::on_eraser_clicked(bool checked) {
    if (checked) {
        scene->instrument = 3;
    }
}

void Cirrus::on_verticalSlider_valueChanged(int value) {
    scene->brushWidth = value;
}

void Cirrus::on_red_valueChanged(int value) {
    scene->red = value;
    red = value;
    ui.brushRGB->setScene(rgb);
    ui.brushRGB->setBackgroundBrush(QBrush(QColor(red, green, blue, 255)));
}

void Cirrus::on_green_valueChanged(int value) {
    scene->green = value;
    green = value;
    ui.brushRGB->setBackgroundBrush(QBrush(QColor(red, green, blue, 255)));
}

void Cirrus::on_blue_valueChanged(int value) {
    scene->blue = value;
    blue = value;
    ui.brushRGB->setBackgroundBrush(QBrush(QColor(red, green, blue, 255)));
}

void Cirrus::on_actionundo_triggered() {
    scene->undo();
}

void Cirrus::on_actionredo_triggered() {
    scene->redo();
}
