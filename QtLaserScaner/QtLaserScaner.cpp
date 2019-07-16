#include "QtLaserScaner.h"

#include <QMessageBox>

QtLaserScaner::QtLaserScaner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowIcon(QIcon("../Resources/images/QT.png"));  //�������ͼ��

	//QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
	
	QToolBar *fileToolBar = addToolBar(tr("Scan"));
	const QIcon scanIcon = QIcon::fromTheme("document-new", QIcon("../Resources/images/shape.png")); //���toolbarͼ��
	QAction *ScanAct = new QAction(scanIcon, tr("&OpenScanMoudle"), this);
	ScanAct->setShortcuts(QKeySequence::New);
	ScanAct->setStatusTip(tr("Create a new file"));
	connect(ScanAct, &QAction::triggered, this, &QtLaserScaner::open);//���߼���ɨ�����
	fileToolBar->addAction(ScanAct);
	fileToolBar->addAction(ScanAct);


	const QIcon cloudIcon = QIcon::fromTheme("document-open", QIcon("../Resources/images/shape.png"));
	QAction *PCProcessAct = new QAction(cloudIcon, tr("&Open..."), this);
	PCProcessAct->setShortcuts(QKeySequence::Open);
	PCProcessAct->setStatusTip(tr("Open an existing file"));
	connect(PCProcessAct, &QAction::triggered, this, &QtLaserScaner::open); //�򿪵��ƴ������
	//fileMenu->addAction(PCProcessAct);
	fileToolBar->addAction(PCProcessAct);


	statusBar();

}

void QtLaserScaner::open()
{
	dlg_scanner = new Dlg_Scanner();
	dlg_scanner->show();
}

void QtLaserScaner::about()
{
	QMessageBox::about(this, tr("About Application"),
		tr("The <b>Application</b> example demonstrates how to "
			"write modern GUI applications using Qt, with a menu bar, "
			"toolbars, and a status bar."));
}