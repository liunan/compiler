#ifndef CKLANEMAP_H
#define CKLANEMAP_H

#include <QtWidgets/QMainWindow>
#include "ui_cklanemap.h"
#include <QtWidgets/QMenu>
#include <QAction>
#include "../persistence/persistence.h"
#include <QPrinter>

class CKLaneScene;
class QGraphicsView;
class cklanemap : public QMainWindow
{
	Q_OBJECT

public:
	cklanemap(QWidget *parent = 0);
	~cklanemap();

private slots:
	void onOpen();
	void onSave();
	void onPrint();
	void onPrintPreview();
	void onPaintRequested(QPrinter * printer);

	void onZoomIn();
	void onZoomOut();
private:
	Ui::cklanemapClass ui;


	QMenu* fileMenu;
	QMenu* viewMenu;
	QMenu* itemMenu;
	QMenu* aboutMenu;

	QAction* openAction;
	QAction* saveAction;
	QAction* printAction;
	QAction* printPreviewAction;

	QAction* zoomInAction;
	QAction* zoomOutAction;

	CKLaneScene* m_pScene;
	QGraphicsView* m_pView;
	persistence m_persistence;
private:
	void createMenu();
	void createActions();



};

#endif // CKLANEMAP_H
