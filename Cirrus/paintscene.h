#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <stack>
#include "action.h"

class paintScene : public QGraphicsScene {
    Q_OBJECT

public:
    explicit paintScene(QObject* parent = nullptr);
    ~paintScene();

    void drawItem(QGraphicsItem* item);
    void undo();
    void redo();
    int brushWidth;
    int instrument;
    int red, green, blue;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

private:
    std::stack<Action*> undoStack;
    std::stack<Action*> redoStack;
    QPointF previousPoint;
};

#endif // PAINTSCENE_H
