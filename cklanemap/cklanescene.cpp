#include "cklanescene.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

CKLaneScene::CKLaneScene(QObject *parent)
: QGraphicsScene(parent), m_pCurrent(NULL)
{
	setStickyFocus(true);

}

CKLaneScene::~CKLaneScene()
{

}



void CKLaneScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (mouseEvent->button() != Qt::LeftButton)
		return;
	//if (selectedItems().length()==1)
	//{
	//	selectedItems().front()->mousePressEvent(mouseEvent);
	//	return;
	//}
	
	QGraphicsScene::mousePressEvent(mouseEvent);

}
void CKLaneScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (m_pCurrent)
	{
		m_pCurrent->setPos(mouseEvent->pos());

	}

	QGraphicsScene::mouseMoveEvent(mouseEvent);

}
void CKLaneScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	m_pCurrent = NULL;
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}