#pragma once
#include "CProfile.h"


class CSurface
{
public:
	CSurface();
	CSurface(cv::Point3f  startCNCPoint,cv::Point3f  endCNCPoint,float ScanSpeed);
	~CSurface();
private:
	std::vector<CProfile>m_vecSurfaceData;//��Ҫ���ݴ��
	float m_fSensorDistance; //������������ĸ߶Ⱦ���
	bool m_bIsYUpdated;//�ж�y�����Ƿ��Ѹ���

public:
	float m_fScanSpeed;     //ɨ���ٶ�,��ʱ��ʹ��
	cv::Point3f  m_startCNCPoint;//��ʼ����ʱ������λ��
	cv::Point3f  m_endCNCPoint;//��������ʱ������λ��

	

	void SetCNCStartPoint(cv::Point3f  startCNCPoint);//���û�����ʼλ��
	void SetCNCEndPoint(cv::Point3f  endCNCPoint);//���û�����ʼλ��
	void SetScanSpeed(float ScanSpeed);//���û���ɨ���ٶ�
	void UpdateScanY();//������ʼλ�ø���Y����ֵ
	void RecieveProfileData(CProfile profile_data);//����profile����

	bool IsEmpty()
	{
		return m_vecSurfaceData.size() == 0;
	}

	void clear()
	{
		m_vecSurfaceData.clear();
	}
	//��������
//������ͼ����depthImage������������ʵ�������ת������map
//	void TransToDepthImage(cv::Mat& depthImage, cv::Mat& map)const;
	//����������͵�����
//	pcl::PointCloud<pcl::PointXYZ>::Ptr  ToPointCloud();
	//д��txt�ļ�
//	void WriteSurfaceDataAsTXTFile(std::string filename);
};

