#include "plugin4a_factory.h"


#include "basicpolygon.h"
plugin4a_factory::plugin4a_factory()
{

}

plugin4a_factory::~plugin4a_factory()
{

}


const char* plugin4a_factory::GetID() const
{
	return "PolygonFeatureFactory";
}
const int plugin4a_factory::GetProductCount() const
{
	return 1;
}
const char* plugin4a_factory::GetProductName(int idx) const
{
	return "basic";
}
IFeature* plugin4a_factory::CreateFeature(int idx)const
{
	return new basicpolygon;
}