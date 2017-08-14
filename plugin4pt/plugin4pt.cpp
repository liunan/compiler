#include "plugin4pt.h"

#include <QGraphicsSvgItem>
#include "feature4svg.h"
const char* PointFeatureFactory::GetID() const
{
	return "PointFeatureFactory";
}
const int PointFeatureFactory::GetProductCount() const
{
	return 1;
}
const char* PointFeatureFactory::GetProductName(int idx) const
{
	return NULL;
}
IFeature* PointFeatureFactory::CreateFeature(int idx)const
{
	IFeature* pRetFeature = NULL;
	switch (idx)
	{
	case 0:
	{
			  feature4svg* pSVGItem = NULL;
			  pRetFeature = pSVGItem = new feature4svg(QString(":/plugin4pt/target.svg"));			  
			  pSVGItem->setScale(0.1);
			  pSVGItem->setFlag(QGraphicsItem::ItemIsMovable, true);
			  pSVGItem->setFlag(QGraphicsItem::ItemIsSelectable, true);			  
	}
		break;

	}
	return pRetFeature;
}