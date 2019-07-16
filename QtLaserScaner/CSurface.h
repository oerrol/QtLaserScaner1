#pragma once
#include "CProfile.h"


class CSurface
{
public:
	CSurface();
	CSurface(cv::Point3f  startCNCPoint,cv::Point3f  endCNCPoint,float ScanSpeed);
	~CSurface();
private:
	std::vector<CProfile>m_vecSurfaceData;//主要数据存放
	float m_fSensorDistance; //传感器与零件的高度距离
	bool m_bIsYUpdated;//判断y坐标是否已更新

public:
	float m_fScanSpeed;     //扫描速度,暂时不使用
	cv::Point3f  m_startCNCPoint;//开始测量时机床的位置
	cv::Point3f  m_endCNCPoint;//结束测量时机床的位置

	

	void SetCNCStartPoint(cv::Point3f  startCNCPoint);//设置机床起始位置
	void SetCNCEndPoint(cv::Point3f  endCNCPoint);//设置机床起始位置
	void SetScanSpeed(float ScanSpeed);//设置机床扫描速度
	void UpdateScanY();//根据起始位置更新Y坐标值
	void RecieveProfileData(CProfile profile_data);//接收profile数据

	bool IsEmpty()
	{
		return m_vecSurfaceData.size() == 0;
	}

	void clear()
	{
		m_vecSurfaceData.clear();
	}
	//导出数据
//输出深度图数据depthImage和像素坐标与实际坐标的转换矩阵map
//	void TransToDepthImage(cv::Mat& depthImage, cv::Mat& map)const;
	//输出点云类型的数据
//	pcl::PointCloud<pcl::PointXYZ>::Ptr  ToPointCloud();
	//写成txt文件
//	void WriteSurfaceDataAsTXTFile(std::string filename);
};

