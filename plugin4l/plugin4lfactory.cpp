#include "plugin4lfactory.h"

#include "basicpolyline.h"

plugin4lFactory::plugin4lFactory()
{

}

plugin4lFactory::~plugin4lFactory()
{

}

const char* plugin4lFactory::GetID() const
{
	return "LineFeatureFactory";
}
const int plugin4lFactory::GetProductCount() const
{
	return 1;
}
const char* plugin4lFactory::GetProductName(int idx) const
{
	return NULL;
}
IFeature* plugin4lFactory::CreateFeature(int idx)const
{
	IFeature* pRetFeature = NULL;
	switch (idx)
	{
	case 0:
	{
			  pRetFeature = new BasicPolyline;
	}
		break;

	}
	return pRetFeature;
}
