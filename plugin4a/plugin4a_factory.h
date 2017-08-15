#ifndef PLUGIN4A_H
#define PLUGIN4A_H

#include "plugin4a_global.h"

#include <QtPlugin>
#include <ifeaturefactory.h>
#include <QObject>

class plugin4a_factory:public QObject, public IFeatureFactory
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID FeatureFactoryInterface_iid)
	//! [4]
	Q_INTERFACES(IFeatureFactory)
public:
	plugin4a_factory();
	~plugin4a_factory();


public:
	const char* GetID() const;
	const int GetProductCount() const;
	const char* GetProductName(int idx) const;
	IFeature* CreateFeature(int idx)const;
private:

};

#endif // PLUGIN4A_H
