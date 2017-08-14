#include "persistence.h"

#include "ifeature.h"
#include <QGraphicsItem>
#include <fstream>
#include <string>
persistence::persistence(QGraphicsScene* pScene):
m_pScene(pScene)
{

}

persistence::~persistence()
{

}

bool persistence::Export(const char* szFilePath)
{
	bool bRet = false;
	do{
		if (!szFilePath)
			break;

		std::ofstream ostream(szFilePath);
		if (!ostream.is_open())
			break;

		for (store_type::iterator it = m_store.begin(); it != m_store.end(); ++it)
		{
			const char* featureId = (*it)->GetName();
			ostream << featureId << "\t";
			QGraphicsItem* pGraphicItem = (*it)->GetViewItem();

			QPointF itemPos = pGraphicItem->pos();
			ostream << itemPos.x() << "\t" << itemPos.y() <<std::endl;
		}
		bRet = true;
	} while (false);
	return bRet;
}

bool persistence::Import(const char* szFilePath)
{
	bool bRet = false;
	do{
		if (!szFilePath)
			break;

		std::ifstream istream(szFilePath);
		if (!istream.is_open())
			break;

		while (!istream.eof())
		{
			std::string szName;
			istream >> szName;
			if (istream.eof())
				break;
			double x, y;
			istream >> x;
			istream >> y;
		}
		bRet = true;

	} while (false);
	return bRet;
}

int persistence::AddFeature(IFeature* pFeature)
{
	if (pFeature)
	{
		m_store.push_back(pFeature);
	}
	return 0;
}
int persistence::DeleteFeature(IFeature* pFeature)
{
	return 0;
}