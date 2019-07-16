#pragma once
#include <qthread.h>
#include "GoCator.h"
#include "CProfile.h"
#include "CSurface.h"

class ScanThread :
	public QThread
{
public:
	ScanThread();
	~ScanThread();
private:
	bool m_bIsStartMeasuring;//判断是否开始测量
protected:
	void run();
public:
	void Scaning();
	GoCator m_Gocator;//大恒设备
	CProfile m_profileDataBuffer;//用来缓存轮廓数据
	CSurface m_surfaceData;//单次扫描的表面检测数据
	QList<QPointF> m_ChartViewData;
	//QtViewCharts m_qtViewCharts;
	long m_lProfileNum = 0 ;//测量时保存的轮廓数
	bool m_dataReady = false;//判断轮廓数据是否已读入/更新
	double m_ScanFrequency = 50; //默认线激光扫描频率为50Hz
	//判断是否点击了开始测量
	bool IsMeasuringStarted()
	{
		return m_bIsStartMeasuring;
	}
	
	//将当前采集到的轮廓数据 m_profileDataBuffer保存在 m_surfaceData中
	void SaveProfileData()
	{
		m_surfaceData.RecieveProfileData(m_profileDataBuffer);
	}

};

