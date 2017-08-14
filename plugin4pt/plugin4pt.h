#ifndef PLUGIN4PT_H
#define PLUGIN4PT_H

#include "plugin4pt_global.h"

#include <QtPlugin>
#include <ifeaturefactory.h>
#include <QObject>

class PointFeatureFactory : public QObject,public IFeatureFactory  
{

	Q_OBJECT
	//! [4]
	Q_PLUGIN_METADATA(IID FeatureFactoryInterface_iid)
	//! [4]
	Q_INTERFACES(IFeatureFactory)

public:
	const char* GetID() const;
	const int GetProductCount() const;
	const char* GetProductName(int idx) const;
	IFeature* CreateFeature(int idx)const;
private:

};

#endif // PLUGIN4PT_H
