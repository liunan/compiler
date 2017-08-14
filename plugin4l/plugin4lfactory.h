#ifndef PLUGIN4LFACTORY_H
#define PLUGIN4LFACTORY_H

#include <QtPlugin>
#include <ifeaturefactory.h>
#include <QObject>

class plugin4lFactory:public QObject, public IFeatureFactory
{
	Q_OBJECT
	//! [4]
	Q_PLUGIN_METADATA(IID FeatureFactoryInterface_iid)
	//! [4]
	Q_INTERFACES(IFeatureFactory)
public:
	plugin4lFactory();
	~plugin4lFactory();

public:
	const char* GetID() const;
	const int GetProductCount() const;
	const char* GetProductName(int idx) const;
	IFeature* CreateFeature(int idx)const;

private:

};

#endif // PLUGIN4LFACTORY_H
