#pragma once

#include "ifeature.h"
#include <QGraphicsPathItem>
#include <QVector>
class BasicPolyline : public QGraphicsPathItem,public IFeature
{
	
public:
	BasicPolyline();
	~BasicPolyline();
	
public:
	const char* GetName(){ return "BasicPolyline"; }
	QGraphicsItem* GetViewItem(){ return this; }	

protected:
	void	mousePressEvent(QGraphicsSceneMouseEvent * event);

private:
	typedef QVector<QPoint> geom_store_type;
	geom_store_type m_pts;

};

