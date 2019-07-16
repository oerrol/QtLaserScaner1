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

//���û�����ʼλ�ã�ɨ���ٶ�
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

//������ʼλ�ø���Y����ֵ
void CSurface::UpdateScanY()
{
	assert(!m_vecSurfaceData.empty());

	long iProfileNum = m_vecSurfaceData.size();
	float fScanLength = m_endCNCPoint.y - m_startCNCPoint.y;//ɨ�賤��
	//����������y��Ⱦ�ֲ�
	float fScanInterval = fScanLength / iProfileNum;//��������֮���ɨ����
	for (int i = 0; i < iProfileNum; i++)
	{
		//����ÿ��������y����
		m_vecSurfaceData[i].SetScanY(m_startCNCPoint.x + fScanInterval * i);
	}
	//���ı�ʶ������ʾy�Ѹ���
	m_bIsYUpdated = true;
}

//����profile����
void CSurface::RecieveProfileData(CProfile profile_data)
{
	m_vecSurfaceData.push_back(profile_data);
}