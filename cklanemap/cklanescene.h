#ifndef CKLANESCENE_H
#define CKLANESCENE_H

#include <QGraphicsScene>

class CKLaneScene : public QGraphicsScene
{
	Q_OBJECT

public:
	CKLaneScene(QObject *parent);
	~CKLaneScene();



protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
	QGraphicsItem* m_pCurrent;
};

#endif // CKLANESCENE_H
