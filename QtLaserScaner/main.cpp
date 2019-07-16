#include "QtLaserScaner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtLaserScaner w;
	w.show();
	return a.exec();
}
