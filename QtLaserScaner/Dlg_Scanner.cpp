#include "Dlg_Scanner.h"
#include "GoCator.h"


Dlg_Scanner::Dlg_Scanner(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QVBoxLayout *layout = ui.verticalLayout_LineDisplay;
//	layout->addWidget(CQtViewCharts);
	QObject::connect(this->ui.btn_Connect, SIGNAL(clicked()), this, SLOT(ScannerConnect()));//���߼���ɨ�����

	ScanViewTimer = new QTimer();  
	//connect(ScanViewTimer, SIGNAL(timeout()), this, SLOT(SLOT_NumAppend()));
	ScanViewTimer->start(10); 

	//��ʼ���߼�����ʾcharts
	CQtViewCharts = new QtViewCharts();

	CChartView = new QChartView(this);
	CChartView->resize(700, 500);
	CQtViewCharts->ChartsInitialize();
	CChartView->setChart(CQtViewCharts);

}

Dlg_Scanner::~Dlg_Scanner()
{
}

//���Ӵ�����
void Dlg_Scanner::ScannerConnect()
{
	GoCatorThread.start();
	GoCatorThread.m_Gocator.Initialize();
	//���������̼߳�ontimer
	GoCatorThread.Scaning();//���Gocator�ɼ��߳�

	//GoCatorThread.m_profileDataBuffer
	//CQtViewCharts->addSeries();
}

//�Ͽ�����������
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
	ScanViewTimer->start(10); // 100ms����
}

void Dlg_Scanner::DataUpdate()
{

}
