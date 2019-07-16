#pragma once
#include<vector>
#include <opencv2/opencv.hpp>

class CProfile
{
public:
	CProfile();
	CProfile(const std::vector<cv::Point2f>profileDataTemp, float yTemp = 0.0);
	CProfile(const CProfile& profileTemp);

	~CProfile();
public:
	std::vector<cv::Point2f>m_vecProfileData;//���������飬���������ߵ�x��z����
	float m_fScanY;
	void SetScanY(float yTemp);//�趨������ɨ���������
	
	cv::Point2f operator[](int i)const;//����[]������,ֻ��
	int size()const;//����size����
	void SaveAsTXT(std::string filename);	//��������

};

