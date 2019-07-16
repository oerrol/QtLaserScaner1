#include "Dlg_Scanner.h"
#include "GoCator.h"


Dlg_Scanner::Dlg_Scanner(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QVBoxLayout *layout = ui.verticalLayout_LineDisplay;
//	layout->addWidget(CQtViewCharts);
	QObject::connect(this->ui.btn_Connect, SIGNAL(clicked()), this, SLOT(ScannerConnect()));//打开线激光扫描界面

	ScanViewTimer = new QTimer();  
	//connect(ScanViewTimer, SIGNAL(timeout()), this, SLOT(SLOT_NumAppend()));
	ScanViewTimer->start(10); 

	//初始化线激光显示charts
	CQtViewCharts = new QtViewCharts();

	CChartView = new QChartView(this);
	CChartView->resize(700, 500);
	CQtViewCharts->ChartsInitialize();
	CChartView->setChart(CQtViewCharts);

}

Dlg_Scanner::~Dlg_Scanner()
{
}

//连接传感器
void Dlg_Scanner::ScannerConnect()
{
	GoCatorThread.start();
	GoCatorThread.m_Gocator.Initialize();
	//开启测量线程及ontimer
	GoCatorThread.Scaning();//大恒Gocator采集线程

	//GoCatorThread.m_profileDataBuffer
	//CQtViewCharts->addSeries();
}

//断开传感器连接
void Dlg_Scanner::ScannerDisconnect()
{
	
}

void Dlg_Scanner::ScannerClose()
{
	Cgocator.Close();
}

void Dlg_Scanner::InitChartView()
{

}



void Dlg_Scanner::SetTimer()
{
	ScanViewTimer = new QTimer();
	connect(ScanViewTimer, SIGNAL(timeout()), this, SLOT(DataUpdate()));
	ScanViewTimer->start(10); // 100ms更新
}

void Dlg_Scanner::DataUpdate()
{

}
