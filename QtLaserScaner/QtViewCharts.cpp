#include "QtViewCharts.h"

#ifndef QTVIEWCHART_H
#define QTVIEWCHART_H


QtViewCharts::QtViewCharts()
{
}


QtViewCharts::~QtViewCharts()
{
}


void QtViewCharts::ChartsInitialize()
{
	// 先添加曲线
	mychart = new QChart();
	chartView = new QChartView(mychart);
	chartView->setRubberBand(QChartView::RectangleRubberBand);

	//QValueAxis *axisX = new QValueAxis; //定义X轴
	m_axisX = new QValueAxis;//定义X轴
	m_axisX->setRange(-100, 100); //设置范围
	m_axisX->setLabelFormat("%g"); //设置刻度的格式  例如要显示多少位数字 //%g 根据数值不同自动选择％f或％e．
	m_axisX->setTitleText("X Axis"); //设置X轴的标题
	m_axisX->setGridLineVisible(true); //设置是否显示网格线
	// m_axisX->setTickCount(20); //主分隔个数：0到10分成20个单位
	m_axisX->setMinorTickCount(4); //设置小刻度线的数目
   // m_axisX->setLabelsVisible(false); //设置刻度是否显示

	//QValueAxis *m_axisY = new QValueAxis;
	m_axisY = new QValueAxis; // 定义Y轴
	m_axisY->setRange(-200, 200);
	m_axisY->setTitleText("Y Axis");
	m_axisY->setLabelFormat("%.2f");
	m_axisY->setGridLineVisible(true);

}

void QtViewCharts::ChartAddQLine()
{
	mychart->addSeries(m_series);

	m_series = new QLineSeries();
	m_series->setUseOpenGL(true);//openGl 加速

	m_series->append(QLinePoints);
	mychart->setAxisX(m_axisY, m_series);
	mychart->setAxisY(m_axisY, m_series);
	mychart->legend()->hide();
	mychart->setTitle("demo");
}


void QtViewCharts::ChartLineUpDate(QList<QPointF> list)
{
	m_series->replace(list);
}

void QtViewCharts::ChartDelQLine()
{
	m_series->clear();
}

void QtViewCharts::timerEvent(QTimerEvent *event) 
{
		if (event->timerId() == QT_timer)
		{//定时器到时间,//模拟数据填充	
				if (isVisible())
				{
					QLinePoints.clear();
					//readDataFromTxt("E:\\2019_04_20_11_31_45_P.txt");//C:\Users\hc\Desktop
					readDataFromTxt("C:\\Users\\hc\\Desktop\\2019_04_20_11_31_45_P.txt");
					count += 0.1;
					ChartLineUpDate(QLinePoints);
				}
		}
}

void QtViewCharts::readDataFromTxt(QString filepath)
	{	
		if (filepath.isEmpty())     //如果未选择文件便确认，即返回
				return;
			QFile file(filepath);
			if (file.open(QIODevice::ReadOnly | QIODevice::Text))
			{
				while (!file.atEnd())
				{
					QByteArray line = file.readLine();
					QString str(line);
					str.chop(1);
					QStringList list = str.split(" ");
					double d_x = list[0].toDouble();
					double d_y = list[1].toDouble();
					double d_z = list[2].toDouble() + count;
					QLinePoints.append(QPointF(d_x, d_z));
				}

				file.close();
			}
	}


#endif /* QTVIEWCHART_H */