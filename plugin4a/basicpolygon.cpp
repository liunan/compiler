#include "basicpolygon.h"

#include <QtGui/QPen>
basicpolygon::basicpolygon()
{
	QPolygonF polygon;
	polygon << QPointF(0, 0) << QPointF(20, 0) << QPointF(30, 20) << QPointF(-50, -10);
	setPolygon(polygon);
	QPen colorPen(Qt::red);
	setPen(colorPen);

	QBrush brush(Qt::Dense6Pattern);
	setBrush(brush);
	setScale(2);
}


basicpolygon::~basicpolygon()
{
}

const char* basicpolygon::GetName()
{
	return "baiscPolygon";
}
QGraphicsItem* basicpolygon::GetViewItem()
{
	return this;
}