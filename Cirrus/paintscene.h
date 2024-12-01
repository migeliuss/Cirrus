#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>


class paintScene  : public QGraphicsScene
{
	Q_OBJECT

public:
	paintScene(QObject *parent = nullptr);
	~paintScene();
private:
	QPointF previousPoint;
private:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};
