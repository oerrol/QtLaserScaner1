#include "CSurface.h"



CSurface::CSurface():
	m_startCNCPoint(cv::Point3f(0.0, 0.0, 0.0)),
	m_endCNCPoint(cv::Point3f(0.0, 250.0, 0.0)),
	m_fScanSpeed(0.0f),
	m_bIsYUpdated(false)
{
}

CSurface::CSurface(cv::Point3f  startCNCPoint,cv::Point3f  endCNCPoint,float ScanSpeed)
{
	m_startCNCPoint = startCNCPoint;
	m_endCNCPoint = endCNCPoint;
	m_fScanSpeed = ScanSpeed;
}

CSurface::~CSurface()
{
}

//设置机床起始位置，扫描速度
void CSurface::SetCNCStartPoint(cv::Point3f startCNCPoint)
{
	m_startCNCPoint = startCNCPoint;
}
void CSurface::SetCNCEndPoint(cv::Point3f endCNCPoint)
{
	m_endCNCPoint = endCNCPoint;
}
void CSurface::SetScanSpeed(float ScanSpeed)
{
	m_fScanSpeed = ScanSpeed;
}

//根据起始位置更新Y坐标值
void CSurface::UpdateScanY()
{
	assert(!m_vecSurfaceData.empty());

	long iProfileNum = m_vecSurfaceData.size();
	float fScanLength = m_endCNCPoint.y - m_startCNCPoint.y;//扫描长度
	//假设轮廓沿y像等距分布
	float fScanInterval = fScanLength / iProfileNum;//两条轮廓之间的扫描间隔
	for (int i = 0; i < iProfileNum; i++)
	{
		//设置每条轮廓的y坐标
		m_vecSurfaceData[i].SetScanY(m_startCNCPoint.x + fScanInterval * i);
	}
	//更改标识符，显示y已更新
	m_bIsYUpdated = true;
}

//接收profile数据
void CSurface::RecieveProfileData(CProfile profile_data)
{
	m_vecSurfaceData.push_back(profile_data);
}