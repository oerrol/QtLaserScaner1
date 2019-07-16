#pragma once

#include <QtCharts> 
//#include <QtCore/QTimer>   //定时器
#include "QTimer"
#include "QTime"

#include<QtCharts\QChartView>   //两个基本模块
#include<QPointF>     //点类
#include<QList>         //列表

#include <QtCharts/QLineSeries> 
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>  //坐标轴设置


QT_CHARTS_USE_NAMESPACE   //使用qtchart需要加入这条语句

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
	void ChartsInitialize();//初始化
	//QChartView *m_chartView;   //因为布局时其它函数会访问这个画布，所以设为public
	//QList<QPointF> setdata();    //预留这个函数作为一个设置图表数据的接口，将外界数据传给图表
	void ChartAddQLine();//添加新的曲线
	void ChartLineUpDate(QList<QPointF> list);
	void ChartDelQLine();//删除曲线
	void readDataFromTxt(QString filepath);//测试用 后面删掉

protected:
	void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;

};

