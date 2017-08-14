#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "persistence_global.h"

#include <QGraphicsScene>
#include <vector>

class IFeature;
class PERSISTENCE_EXPORT persistence
{
public:
	persistence(QGraphicsScene* pScene);
	~persistence();

public:
	bool Export(const char* szFilePath);
	bool Import(const char* szFilePath);

	/*����Ŀ��ͬʱ������������˲���Ҫ��ʾ�ͷż����Ŀ�����*/
	int AddFeature(IFeature* pFeature);
	int DeleteFeature(IFeature* pFeature);

private:
	QGraphicsScene* m_pScene;
	typedef std::vector<IFeature*> store_type;
	store_type m_store;
};

#endif // PERSISTENCE_H
