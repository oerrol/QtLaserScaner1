#include "ScanThread.h"

ScanThread::ScanThread()
{
}

ScanThread::~ScanThread()
{
}

void ScanThread::run()
{
	while (m_Gocator.isConnected())
	{
		//m_Gocator.m_profileBuffer

	}
	//	int iii = 0;
	//while (1)
	//{
	//iii++;
	//}
	//exec();
}

void ScanThread::Scaning()
{
	//timerEvent;
	while (m_Gocator.isConnected())
	{
		//����豸�ɼ���������
		m_Gocator.CollectSingleProfile();
		//����ɼ�������������
		m_profileDataBuffer = m_Gocator.GetProfileData();
		m_ChartViewData = m_Gocator.GetQtListData();
		//���¿��ر����ڼ�ʱ������ʾ����
		if (m_profileDataBuffer.size() != 0)
		{
			m_dataReady = true;
		}
		
		if (IsMeasuringStarted())
		{
			//�趨�������ݵ�y����
			if (m_surfaceData.m_fScanSpeed != 0)
			{
				m_profileDataBuffer.SetScanY((m_surfaceData.m_fScanSpeed / m_ScanFrequency / 60) *m_lProfileNum); //GoCator�������ɼ�Ƶ��Ϊ50Hz
			}
			else //��m_fScanSpeed = 0 ��Ĭ�ϰ���0.2mm�ļ������ɨ������
			{
				m_profileDataBuffer.SetScanY(0.2*m_lProfileNum);
			}
			//������������
			SaveProfileData();//�������˿�ʼ���������������� m_profileDataBuffer������ m_surfaceData��
			m_lProfileNum++; //���պ�Ƶ�ʵȼ�������Y����
		}
	}
	
}
