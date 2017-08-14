#ifndef IFEATUREFACTORY__H
#define IFEATUREFACTORY__H

#include <QtPlugin>

class IFeature;
/*
目标符号创建工厂
*/
class IFeatureFactory{
public:
	/*
	*/
	virtual const char* GetID() const = 0;

	/*获取可以创建的产品（符号）数量*/
	virtual const int GetProductCount() const = 0;

	virtual const char* GetProductName(int idx) const = 0;

	/*创建目标
	*/
	virtual IFeature* CreateFeature(int idx)const = 0;
};

QT_BEGIN_NAMESPACE
#define FeatureFactoryInterface_iid "org.cq4cw.lane.FeatureFactoryInterface"

Q_DECLARE_INTERFACE(IFeatureFactory, FeatureFactoryInterface_iid)

QT_END_NAMESPACE
#endif
