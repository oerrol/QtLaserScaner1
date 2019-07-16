#pragma once
#include <QObject>
#include <QWidget>
#include "ui_Dlg_Scanner.h"
#include "Gocator.h"
#include "ScanThread.h"
#include "QtViewCharts.h"

class Dlg_Scanner : public QWidget
{
	Q_OBJECT

public:
	Dlg_Scanner(QWidget *parent = Q_NULLPTR);
	~Dlg_Scanner();

private:
	Ui::Dlg_Scanner ui;
	bool m_bIsStartMeasuring;//�ж��Ƿ�ʼ����
	
public:
	GoCator Cgocator;//����豸
	QTimer *ScanViewTimer;
	ScanThread GoCatorThread;
	QtViewCharts *CQtViewCharts;
	QChartView *CChartView;
	void SetScanY(ProfilePoint* m_profileBuffer, float yTemp);//�趨������ɨ���������

public slots:
	void ScannerConnect();  //���Ӵ�����
	void ScannerDisconnect();  //�Ͽ�������
	void ScannerClose();//�رմ�����

	void SetTimer(); //���ü�ʱ���� ����ʵʱ��ʾ����
	void DataUpdate();
	void InitChartView();
};


