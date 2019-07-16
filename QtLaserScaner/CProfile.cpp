#include "CProfile.h"
#include <fstream>


CProfile::CProfile() :m_fScanY(0.0)
{
}
CProfile::CProfile(const std::vector<cv::Point2f>profileDataTemp, float yTemp)
{
	m_vecProfileData = profileDataTemp;
	m_fScanY = yTemp;
}

//拷贝构造
CProfile::CProfile(const CProfile& profileTemp)
{
	m_vecProfileData = profileTemp.m_vecProfileData;
	m_fScanY = profileTemp.m_fScanY;
}

//设置当前轮廓的y坐标
void CProfile::SetScanY(float yTemp)
{
	m_fScanY = yTemp;
}
//重载[]操作符
cv::Point2f  CProfile::operator[](int i)const
{
	return m_vecProfileData[i];
}
//size（）
int CProfile::size()const
{
	return m_vecProfileData.size();
}

void CProfile::SaveAsTXT(std::string filename)
{
	std::ofstream pout;
	pout.open(filename, std::ios::app);
	int data_length = m_vecProfileData.size();
	if (pout.is_open())
		for (int i = 0; i < data_length; i++)
		{
			if ((m_vecProfileData[i].y > -400) && (m_vecProfileData[i].y < 400))
			{
				pout << m_vecProfileData[i].x << " " << m_fScanY << " " << m_vecProfileData[i].y << '\n';
			}
		}
}

CProfile::~CProfile()
{
}
