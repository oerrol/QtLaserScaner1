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
		//大恒设备采集轮廓数据
		m_Gocator.CollectSingleProfile();
		//导入采集到的轮廓数据
		m_profileDataBuffer = m_Gocator.GetProfileData();
		m_ChartViewData = m_Gocator.GetQtListData();
		//更新开关变量在计时器中显示轮廓
		if (m_profileDataBuffer.size() != 0)
		{
			m_dataReady = true;
		}
		
		if (IsMeasuringStarted())
		{
			//设定轮廓数据的y坐标
			if (m_surfaceData.m_fScanSpeed != 0)
			{
				m_profileDataBuffer.SetScanY((m_surfaceData.m_fScanSpeed / m_ScanFrequency / 60) *m_lProfileNum); //GoCator传感器采集频率为50Hz
			}
			else //若m_fScanSpeed = 0 则默认按照0.2mm的间距生成扫描数据
			{
				m_profileDataBuffer.SetScanY(0.2*m_lProfileNum);
			}
			//保存轮廓数据
			SaveProfileData();//如果点击了开始测量，则将轮廓数据 m_profileDataBuffer保存在 m_surfaceData中
			m_lProfileNum++; //按照恒频率等间距的设置Y坐标
		}
	}
	
}
