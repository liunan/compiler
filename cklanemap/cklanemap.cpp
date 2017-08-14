#include "cklanemap.h"
#include "cklanescene.h"
#include "ifeature.h"
#include "ifeaturefactory.h"


#include <qgraphicsview.h>

#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QPluginLoader>

#include <QFileDialog>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPrinter>
#include <QDir>



cklanemap::cklanemap(QWidget *parent)
: QMainWindow(parent), m_persistence(NULL)
{
	ui.setupUi(this);
	createActions();
	createMenu();

	m_pScene = new CKLaneScene(this);
	m_pScene->setSceneRect(QRectF(0, 0, 1000, 1000));
	m_pView = new QGraphicsView(m_pScene);

	m_pView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pView->setDragMode(QGraphicsView::NoDrag);

	setCentralWidget(m_pView);

	QString appPath = QApplication::instance()->applicationDirPath();
	QDir  pluginsDir = QDir(QApplication::instance()->applicationDirPath());
	foreach(QString fileName, pluginsDir.entryList(QDir::Files)) {
		QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
		QString str = loader.errorString();
		QObject *plugin = loader.instance();
		if (plugin) {
			IFeatureFactory * featureFactoryInstance = qobject_cast<IFeatureFactory *>(plugin);
			if (featureFactoryInstance)
			{
				const char* name = featureFactoryInstance->GetID();
				int productCount = featureFactoryInstance->GetProductCount();
				IFeature* pFeature = featureFactoryInstance->CreateFeature(0);
				if (pFeature)
				{

					m_persistence.AddFeature(pFeature);

					QGraphicsItem* pItem = pFeature->GetViewItem();
					pItem->setPos(500, 500);
					m_pScene->addItem(pItem);

					pItem->setFlag(QGraphicsItem::ItemIsMovable, true);
					pItem->setFlag(QGraphicsItem::ItemIsSelectable, true);
				}

				IFeature* pFeature2 = featureFactoryInstance->CreateFeature(0);
				if (pFeature2)
				{
					m_persistence.AddFeature(pFeature2);
					pFeature2->GetViewItem()->setPos(0, 0);
					m_pScene->addItem(pFeature2->GetViewItem());

				}
				
			}			
		}
	}

}

cklanemap::~cklanemap()
{

}

void cklanemap::createActions()
{
	openAction = new QAction(tr("&Open"),this);
	connect(openAction, SIGNAL(triggered()), this, SLOT(onOpen()));
	saveAction = new QAction(tr("&Save"),this);
	connect(saveAction, SIGNAL(triggered()), this, SLOT(onSave()));
	printAction = new QAction(tr("&Print"), this);
	connect(printAction, SIGNAL(triggered()), this, SLOT(onPrint()));
	printPreviewAction = new QAction(tr("PrintPreview"), this);
	connect(printPreviewAction, SIGNAL(triggered()), this, SLOT(onPrintPreview()));

	zoomInAction = new QAction(tr("ZoomIn"), this);
	connect(zoomInAction, SIGNAL(triggered()), this, SLOT(onZoomIn()));
	zoomOutAction = new QAction(tr("ZoomOut"), this);
	connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(onZoomOut()));
}

void cklanemap::createMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(printAction);
	fileMenu->addAction(printPreviewAction);

	viewMenu = menuBar()->addMenu(tr("&View"));
	viewMenu->addAction(zoomInAction);
	viewMenu->addAction(zoomOutAction);

	itemMenu = menuBar()->addMenu(tr("&Item"));
	//itemMenu->addAction(deleteAction);
	/*itemMenu->addSeparator();
	itemMenu->addAction(toFrontAction);
	itemMenu->addAction(sendBackAction);
	*/
	aboutMenu = menuBar()->addMenu(tr("&Help"));
	//aboutMenu->addAction(aboutAction);
}


////////////////////////////
void cklanemap::onOpen()
{
	QString selectedFile = QFileDialog::getOpenFileName(this,
		tr("Open Map"), "/home/jana", tr("Map Files (*.map)"));

	
	m_persistence.Import(selectedFile.toLocal8Bit().data());


}

void cklanemap::onSave()
{
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::AnyFile);
	dialog.setNameFilter(tr("Map Files (*.map)"));
	if (dialog.exec())
	{
		QStringList fileNames = dialog.selectedFiles();
		if (fileNames.length())
		{
			
			m_persistence.Export(fileNames[0].toLocal8Bit().data());
		}
	}

}

void cklanemap::onPrint()
{
	QPrinter printer(QPrinter::HighResolution);
	printer.setPaperSize(QPrinter::A4);
	QPrintDialog printDialog(&printer, this);
	if (printDialog.exec() == QDialog::Accepted) {
		// print ...
		
		QPainter painter(&printer);
		m_pScene->render(&painter);

	}
}


void cklanemap::onPrintPreview()
{
	QPrinter printer(QPrinter::HighResolution);
	QPrintPreviewDialog preview(&printer);
	connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(onPaintRequested(QPrinter*)));

	preview.exec();
}

void cklanemap::onPaintRequested(QPrinter * printer)
{
	QPainter painter(printer);
	m_pScene->render(&painter);
}

void cklanemap::onZoomIn()
{
	m_pView->scale(2, 2);
}

void cklanemap::onZoomOut()
{
	m_pView->scale(0.5, 0.5);
}