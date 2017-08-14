#ifndef IFEATURE__H
#define IFEATURE__H

class QGraphicsItem;

class IFeature {
public:
	virtual const char* GetName() = 0;
	virtual QGraphicsItem* GetViewItem() = 0;
};
#endif
