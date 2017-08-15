#pragma once
#include "ifeature.h"
#include <QGraphicsPolygonItem>
class basicpolygon : public QGraphicsPolygonItem,public IFeature
{
public:
	basicpolygon();
	~basicpolygon();

public:
	virtual const char* GetName();
	virtual QGraphicsItem* GetViewItem();
};

