#include "basicpolyline.h"

#include <QtGui/QPainterPath>
#include <QGraphicsSceneMouseEvent>
BasicPolyline::BasicPolyline()
{
	QPainterPath path;
	path.moveTo(-50, 50);
	path.lineTo(50, 50);
	path.lineTo(0, -100);
	path.closeSubpath();
	setPath(path);

	m_pts.push_back(QPoint(-50, 50));
	m_pts.push_back(QPoint(50, 50));
	m_pts.push_back(QPoint(0, -100));
}


BasicPolyline::~BasicPolyline()
{
}

void BasicPolyline::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		grabMouse();
		m_pts.push_back(QPoint(event->pos().x(),event->pos().y()));
		QPainterPath path;
		path.moveTo(m_pts[0].x(), m_pts[0].y());
		for (int i = 1; i < m_pts.length(); ++i)
		{
			path.lineTo(m_pts[i].x(), m_pts[i].y());
		}
		setPath(path);
	}

	
}
