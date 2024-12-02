#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    paintScene::brushWidth = 1;
    paintScene::instrument = 1;
}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    switch (paintScene::instrument)
    {
    case 1:
        addEllipse(event->scenePos().x() - 0.5,
            event->scenePos().y() - 0.5,
            1,
            1,
            QPen(Qt::NoPen),
            QBrush(Qt::gray));
        break;
    case 2:
        addEllipse(event->scenePos().x() - paintScene::brushWidth/2,
            event->scenePos().y() - paintScene::brushWidth / 2,
            paintScene::brushWidth,
            paintScene::brushWidth,
            QPen(Qt::NoPen),
            QBrush(Qt::black));
        break;
    case 3:
        addEllipse(event->scenePos().x() - paintScene::brushWidth / 2,
            event->scenePos().y() - paintScene::brushWidth / 2,
            paintScene::brushWidth,
            paintScene::brushWidth,
            QPen(Qt::NoPen),
            QBrush(Qt::white));
        break;
    default:
        break;
    }
    
    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    switch (paintScene::instrument)
    {
    case 1:
        addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap));
        break;
    case 2:
        addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::black, paintScene::brushWidth, Qt::SolidLine, Qt::RoundCap));
        break;
    case 3:
        addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::white, paintScene::brushWidth, Qt::SolidLine, Qt::RoundCap));
        break;
    default:
        break;
    }

    previousPoint = event->scenePos();
}