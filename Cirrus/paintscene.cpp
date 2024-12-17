// paintscene.cpp
#include "paintscene.h"
#include "drawaction.h"

paintScene::paintScene(QObject* parent)
    : QGraphicsScene(parent), brushWidth(1), instrument(1), red(0), green(0), blue(0) {}

paintScene::~paintScene() {
    while (!undoStack.empty()) {
        delete undoStack.top();
        undoStack.pop();
    }
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}

void paintScene::drawItem(QGraphicsItem* item) {
    DrawAction* action = new DrawAction(item, this);
    action->execute();
    undoStack.push(action);

    // Очистка стека redo
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}

void paintScene::undo() {
    if (!undoStack.empty()) {
        Action* action = undoStack.top();
        action->undo();
        redoStack.push(action);
        undoStack.pop();
    }
}

void paintScene::redo() {
    if (!redoStack.empty()) {
        Action* action = redoStack.top();
        action->redo();
        undoStack.push(action);
        redoStack.pop();
    }
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsItem* newItem = nullptr;

    switch (instrument) {
    case 1:
        newItem = addEllipse(event->scenePos().x() - 0.5,
            event->scenePos().y() - 0.5,
            1, 1,
            QPen(Qt::NoPen),
            QBrush(Qt::gray));
        break;
    case 2:
        newItem = addEllipse(event->scenePos().x() - brushWidth / 2,
            event->scenePos().y() - brushWidth / 2,
            brushWidth, brushWidth,
            QPen(Qt::NoPen),
            QBrush(QColor(red, green, blue, 255)));
        break;
    case 3:
        newItem = addEllipse(event->scenePos().x() - brushWidth / 2,
            event->scenePos().y() - brushWidth / 2,
            brushWidth, brushWidth,
            QPen(Qt::NoPen),
            QBrush(Qt::black));
        addEllipse(event->scenePos().x() - brushWidth / 2,
            event->scenePos().y() - brushWidth / 2,
            brushWidth, brushWidth,
            QPen(Qt::NoPen),
            QBrush(Qt::lightGray, Qt::Dense2Pattern));
        break;
    default:
        break;
    }

    if (newItem) {
        drawItem(newItem);
    }

    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsItem* newItem = nullptr;

    switch (instrument) {
    case 1:
        newItem = addLine(previousPoint.x(), previousPoint.y(),
            event->scenePos().x(), event->scenePos().y(),
            QPen(Qt::gray, 1, Qt::SolidLine, Qt::RoundCap));
        break;
    case 2:
        newItem = addLine(previousPoint.x(), previousPoint.y(),
            event->scenePos().x(), event->scenePos().y(),
            QPen(QColor(red, green, blue, 255), brushWidth, Qt::SolidLine, Qt::RoundCap));
        break;
    case 3:
        newItem = addLine(previousPoint.x(), previousPoint.y(),
            event->scenePos().x(), event->scenePos().y(),
            QPen(QBrush(Qt::black), brushWidth, Qt::SolidLine, Qt::RoundCap));
        addLine(previousPoint.x(), previousPoint.y(),
            event->scenePos().x(), event->scenePos().y(),
            QPen(QBrush(Qt::lightGray, Qt::Dense2Pattern), brushWidth, Qt::SolidLine, Qt::RoundCap));
        break;
    default:
        break;
    }

    if (newItem) {
        drawItem(newItem);
    }

    previousPoint = event->scenePos();
}
