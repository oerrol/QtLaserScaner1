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
	// ���������
	mychart = new QChart();
	chartView = new QChartView(mychart);
	chartView->setRubberBand(QChartView::RectangleRubberBand);

	//QValueAxis *axisX = new QValueAxis; //����X��
	m_axisX = new QValueAxis;//����X��
	m_axisX->setRange(-100, 100); //���÷�Χ
	m_axisX->setLabelFormat("%g"); //���ÿ̶ȵĸ�ʽ  ����Ҫ��ʾ����λ���� //%g ������ֵ��ͬ�Զ�ѡ��f��e��
	m_axisX->setTitleText("X Axis"); //����X��ı���
	m_axisX->setGridLineVisible(true); //�����Ƿ���ʾ������
	// m_axisX->setTickCount(20); //���ָ�������0��10�ֳ�20����λ
	m_axisX->setMinorTickCount(4); //����С�̶��ߵ���Ŀ
   // m_axisX->setLabelsVisible(false); //���ÿ̶��Ƿ���ʾ

	//QValueAxis *m_axisY = new QValueAxis;
	m_axisY = new QValueAxis; // ����Y��
	m_axisY->setRange(-200, 200);
	m_axisY->setTitleText("Y Axis");
	m_axisY->setLabelFormat("%.2f");
	m_axisY->setGridLineVisible(true);

}

void QtViewCharts::ChartAddQLine()
{
	mychart->addSeries(m_series);

	m_series = new QLineSeries();
	m_series->setUseOpenGL(true);//openGl ����

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
		{//��ʱ����ʱ��,//ģ���������	
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
		if (filepath.isEmpty())     //���δѡ���ļ���ȷ�ϣ�������
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