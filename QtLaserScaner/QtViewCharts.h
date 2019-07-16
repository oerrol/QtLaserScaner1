#pragma once

#include <QtCharts> 
//#include <QtCore/QTimer>   //��ʱ��
#include "QTimer"
#include "QTime"

#include<QtCharts\QChartView>   //��������ģ��
#include<QPointF>     //����
#include<QList>         //�б�

#include <QtCharts/QLineSeries> 
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>  //����������


QT_CHARTS_USE_NAMESPACE   //ʹ��qtchart��Ҫ�����������

class QtViewCharts : public QChart
{
public:
	QtViewCharts();
	~QtViewCharts();

public:
	int QT_timer;//QTimer updateTimer;

	QChart *mychart;
	QChartView *chartView;
	//QSplineSeries *m_series;
	QLineSeries *m_series;
	QValueAxis *m_axisX;
	QValueAxis *m_axisY;
    QList<QPointF> QLinePoints;
	double count = 0.5;
	void ChartsInitialize();//��ʼ��
	//QChartView *m_chartView;   //��Ϊ����ʱ����������������������������Ϊpublic
	//QList<QPointF> setdata();    //Ԥ�����������Ϊһ������ͼ�����ݵĽӿڣ���������ݴ���ͼ��
	void ChartAddQLine();//����µ�����
	void ChartLineUpDate(QList<QPointF> list);
	void ChartDelQLine();//ɾ������
	void readDataFromTxt(QString filepath);//������ ����ɾ��

protected:
	void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

};

