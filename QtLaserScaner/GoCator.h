#pragma once


#include <GoSdk/GoSdk.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "CProfile.h"
#include "QtViewCharts.h"
#include <opencv2/opencv.hpp>
#include<vector>

#define RECEIVE_TIMEOUT	20000000
#define INVALID_RANGE_16BIT		((signed short)0x8000)			// gocator transmits range data as 16-bit signed integers. 0x8000 signifies invalid range data.
#define DOUBLE_MAX				((k64f)1.7976931348623157e+308)	// 64-bit double - largest positive value.
#define INVALID_RANGE_DOUBLE	((k64f)-DOUBLE_MAX)				// floating point value to represent invalid range data.
#define SENSOR_IP			    "192.168.1.10"

#define NM_TO_MM(VALUE) (((k64f)(VALUE))/1000000.0)
#define UM_TO_MM(VALUE) (((k64f)(VALUE))/1000.0)

typedef struct
{
	double x;	// x-coordinate in engineering units (mm) - position along laser line
	double z;	// z-coordinate in engineering units (mm) - height (at the given x position)
	unsigned char intensity;
}ProfilePoint;

typedef struct
{
	double x;	// x-coordinate in engineering units (mm) - position along laser line
	double y;	// y-coordinate in engineering units (mm) - position along the direction of travel
	double z;	// z-coordinate in engineering units (mm) - height (at the given x position)
	unsigned char intensity;
}SurfacePoint;

class GoCator
{
public:
	GoCator();
	~GoCator();

public:
	/***********GoCator״̬����**************/
	kAssembly m_api;
	kStatus m_status;
	GoSetup m_setup;
	GoSystem m_system;
	GoSensor m_sensor;
	GoDataSet m_dataset;
	kIpAddress m_ipAddress;
	GoDataMsg m_dataObj;
	GoStamp *m_stamp;
	/******************************************/

public:
	void Initialize();   //��ʼ���߼����豸
	CProfile GetProfileData(); //�����������
	QList<QPointF> GetQtListData();//�������������Qt��ʾ
	bool m_bIsconnected;//�ж��豸�Ƿ������ӳɹ�
	void Close();  // �ر��߼����豸

	void CollectSingleProfile();  //�ɼ�����ģʽ����

	bool isConnected()
	{
		return m_bIsconnected;
	}

private:
	ProfilePoint* m_profileBuffer;	//��������ͷ
	SurfacePoint* m_surfaceBuffer;//��������ͷ
	int m_profilePointCount;//��������

};

