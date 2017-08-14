#ifndef IFEATUREFACTORY__H
#define IFEATUREFACTORY__H

#include <QtPlugin>

class IFeature;
/*
Ŀ����Ŵ�������
*/
class IFeatureFactory{
public:
	/*
	*/
	virtual const char* GetID() const = 0;

	/*��ȡ���Դ����Ĳ�Ʒ�����ţ�����*/
	virtual const int GetProductCount() const = 0;

	virtual const char* GetProductName(int idx) const = 0;

	/*����Ŀ��
	*/
	virtual IFeature* CreateFeature(int idx)const = 0;
};

QT_BEGIN_NAMESPACE
#define FeatureFactoryInterface_iid "org.cq4cw.lane.FeatureFactoryInterface"

Q_DECLARE_INTERFACE(IFeatureFactory, FeatureFactoryInterface_iid)

QT_END_NAMESPACE
#endif
