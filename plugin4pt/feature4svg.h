#ifndef FEATURE4SVG_H
#define FEATURE4SVG_H

#include "ifeature.h"
#include <QGraphicsSvgItem>

class feature4svg : public QGraphicsSvgItem, public IFeature
{
	Q_OBJECT

public:
	const char* GetName(){ return "SVG"; }
	QGraphicsItem* GetViewItem(){ return this; }
	feature4svg(const QString & fileName, QGraphicsItem * parent = 0);
	~feature4svg();

private:
	
};

#endif // FEATURE4SVG_H
