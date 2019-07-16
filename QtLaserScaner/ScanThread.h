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
	bool m_bIsStartMeasuring;//�ж��Ƿ�ʼ����
protected:
	void run();
public:
	void Scaning();
	GoCator m_Gocator;//����豸
	CProfile m_profileDataBuffer;//����������������
	CSurface m_surfaceData;//����ɨ��ı���������
	QList<QPointF> m_ChartViewData;
	//QtViewCharts m_qtViewCharts;
	long m_lProfileNum = 0 ;//����ʱ�����������
	bool m_dataReady = false;//�ж����������Ƿ��Ѷ���/����
	double m_ScanFrequency = 50; //Ĭ���߼���ɨ��Ƶ��Ϊ50Hz
	//�ж��Ƿ����˿�ʼ����
	bool IsMeasuringStarted()
	{
		return m_bIsStartMeasuring;
	}
	
	//����ǰ�ɼ������������� m_profileDataBuffer������ m_surfaceData��
	void SaveProfileData()
	{
		m_surfaceData.RecieveProfileData(m_profileDataBuffer);
	}

};

