// drawaction.h
#ifndef DRAWACTION_H
#define DRAWACTION_H

#include "action.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

class DrawAction : public Action {
public:
    DrawAction(QGraphicsItem* item, QGraphicsScene* scene)
        : item(item), scene(scene) {}

    void execute() override {
        scene->addItem(item);
    }

    void undo() override {
        scene->removeItem(item);
    }

    void redo() override {
        scene->addItem(item);
    }

private:
    QGraphicsItem* item;
    QGraphicsScene* scene;
};

#endif // DRAWACTION_H
