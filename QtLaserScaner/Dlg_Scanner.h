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
	bool m_bIsStartMeasuring;//判断是否开始测量
	
public:
	GoCator Cgocator;//大恒设备
	QTimer *ScanViewTimer;
	ScanThread GoCatorThread;
	QtViewCharts *CQtViewCharts;
	QChartView *CChartView;
	void SetScanY(ProfilePoint* m_profileBuffer, float yTemp);//设定轮廓在扫描向的坐标

public slots:
	void ScannerConnect();  //连接传感器
	void ScannerDisconnect();  //断开传感器
	void ScannerClose();//关闭传感器

	void SetTimer(); //设置计时函数 用于实时显示轮廓
	void DataUpdate();
	void InitChartView();
};


