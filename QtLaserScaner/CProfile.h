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
	std::vector<cv::Point2f>m_vecProfileData;//轮廓点数组，单条激光线的x，z坐标
	float m_fScanY;
	void SetScanY(float yTemp);//设定轮廓在扫描向的坐标
	
	cv::Point2f operator[](int i)const;//重载[]操作符,只读
	int size()const;//定义size方法
	void SaveAsTXT(std::string filename);	//保存数据

};

