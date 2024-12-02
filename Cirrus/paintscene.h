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
	int brushWidth;
	int instrument;
private:
	QPointF previousPoint;
	QPainter* painter;
private:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
};
