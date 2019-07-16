#include "GoCator.h"
#include<QMessageBox>
#include <QString>


GoCator::GoCator() :m_bIsconnected(false)
{
}


GoCator::~GoCator()
{
}

void GoCator::Initialize()
{
	// construct Gocator API Library
	if ((m_status = GoSdk_Construct(&m_api)) != kOK)
	{
		QMessageBox msgBox;	
		msgBox.setText(QString::fromLocal8Bit("GoCator��ʼ��apiʧ��"));
		msgBox.exec();
		return;
	}

	// construct GoSystem object
	if ((m_status = GoSystem_Construct(&m_system, kNULL)) != kOK)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("GoCator��ʼ��systemʧ��"));
		msgBox.exec();
		return;
	}

	// Parse IP address into address data structure
	kIpAddress_Parse(&m_ipAddress, SENSOR_IP);
	// obtain GoSensor object by sensor IP address
	if ((m_status = GoSystem_FindSensorByIpAddress(m_system, &m_ipAddress, &m_sensor)) != kOK)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("GoCator��ʼ��IPʧ��"));
		msgBox.exec();
		return;
	}

	// create connection to GoSensor object
	if ((m_status = GoSensor_Connect(m_sensor)) != kOK)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("GoCator��ʼ��IPʧ��"));
		msgBox.exec();
		return;
	}

	// enable sensor data channel
	if ((m_status = GoSystem_EnableData(m_system, kTRUE)) != kOK)
	{

		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("GoCator��ʼ��EnableDataʧ��"));
		msgBox.exec();
		return;
	}

	// retrieve setup handle //profile mode ���� ���ڼ���profilePointCount����
	if ((m_setup = GoSensor_Setup(m_sensor)) == kNULL)
	{
		QMessageBox msgBox;
		msgBox.setText("Error: GoSensor_Setup: Invalid Handle\n");
		msgBox.exec();
	}


	// retrieve total number of profile points prior to starting the sensor
	if (GoSetup_UniformSpacingEnabled(m_setup))
	{
		// Uniform spacing is enabled. The number is based on the X Spacing setting
		m_profilePointCount = GoSetup_XSpacingCount(m_setup, GO_ROLE_MAIN);
	}
	else
	{
		// non-uniform spacing is enabled. The max number is based on the number of columns used in the camera.
		m_profilePointCount = GoSetup_FrontCameraWidth(m_setup, GO_ROLE_MAIN);
	}
	if ((m_profileBuffer = (ProfilePoint*)malloc(m_profilePointCount * sizeof(ProfilePoint))) == kNULL)
	{
		QMessageBox msgBox;
		msgBox.setText("Error: Cannot allocate profileData");
		msgBox.exec();
		return;
	}
	//    QMessageBox msgBox;
	//    msgBox.setText("EGoSensor��ʼ�������ɹ�");
	m_bIsconnected = true;
}


void GoCator::Close()
{
	// stop Gocator sensor
	if ((m_status = GoSystem_Stop(m_system)) != kOK)
	{
		QMessageBox msgBox;
		msgBox.setText("008:GoSensor �ر�ʧ��");
		msgBox.exec();
		return;
	}
	m_bIsconnected = false;
	// destroy handles
	GoDestroy(m_system);
	GoDestroy(m_api);
}

void GoCator::CollectSingleProfile()
{
	if (GoSystem_ReceiveData(m_system, &m_dataset, RECEIVE_TIMEOUT) == kOK)
	{
		SurfacePoint **surfaceBuffer = NULL;  //��ʼ������ģʽ�Ķ�άָ��surfaceBuffer
		k32u surfaceBufferHeight = 0;
		for (int i = 0; i < GoDataSet_Count(m_dataset); ++i)
		{
			m_dataObj = GoDataSet_At(m_dataset, i);
			//Retrieve GoStamp message
			switch (GoDataMsg_Type(m_dataObj))
			{
			case GO_DATA_MESSAGE_TYPE_STAMP:
			{
				GoStampMsg stampMsg = m_dataObj;
				for (int j = 0; j < GoStampMsg_Count(stampMsg); ++j)
				{
					m_stamp = GoStampMsg_At(stampMsg, j);
				}
			}
			break;
			case GO_DATA_MESSAGE_TYPE_RESAMPLED_PROFILE:		//proile mode ����ģʽ
			{
				GoResampledProfileMsg profileMsg = m_dataObj;
				for (int k = 0; k < GoResampledProfileMsg_Count(profileMsg); ++k)
				{
					unsigned int validPointCount = 0;
					unsigned int invalidPointCount = 0;
					short* data = GoResampledProfileMsg_At(profileMsg, k);
					double XResolution = NM_TO_MM(GoResampledProfileMsg_XResolution(profileMsg));
					double ZResolution = NM_TO_MM(GoResampledProfileMsg_ZResolution(profileMsg));
					double XOffset = UM_TO_MM(GoResampledProfileMsg_XOffset(profileMsg));
					double ZOffset = UM_TO_MM(GoResampledProfileMsg_ZOffset(profileMsg));
					//translate 16-bit range data to engineering units and copy profiles to memory array
					for (int arrayIndex = 0; arrayIndex < GoResampledProfileMsg_Width(profileMsg); ++arrayIndex)
					{
						if (data[arrayIndex] != INVALID_RANGE_16BIT)
						{
							m_profileBuffer[arrayIndex].x = XOffset + XResolution * arrayIndex;
							m_profileBuffer[arrayIndex].z = ZOffset + ZResolution * data[arrayIndex];
							validPointCount++;   //ͳ����Ч������
						}
						else
						{
							m_profileBuffer[arrayIndex].x = XOffset + XResolution * arrayIndex;
							m_profileBuffer[arrayIndex].z = INVALID_RANGE_DOUBLE;
							invalidPointCount++;  //ͳ����Ч������
							//���Գ��Բ�������Ч������ 2018.10.01
						}
					}
				}
			}
			break;
			case GO_DATA_MESSAGE_TYPE_SURFACE:  //surface mode ����ģʽ
				break;
			}//switch
		}//for
	}//if
}

//�����������
CProfile GoCator::GetProfileData()
{
	std::vector<cv::Point2f> profileData(m_profilePointCount);
	for (int i = 0; i < m_profilePointCount; i++)
	{
		// 		if ((m_profileBuffer[i].z > -400) && (m_profileBuffer[i].z < 400))   //-400-400ΪGoCator�����
		// 		{
		profileData[i] = cv::Point2f(m_profileBuffer[i].x, m_profileBuffer[i].z);
		//		}
	}
	return CProfile(profileData, -1);

}

//�������������Qt��ʾ
QList<QPointF> GoCator::GetQtListData()
{
	QList<QPointF> QprofileData;
	{
		for (int i = 0; i < m_profilePointCount; i++)
		{
			QprofileData.append(QPointF(m_profileBuffer[i].x, m_profileBuffer[i].z));
		}
	}
	return QprofileData;
}