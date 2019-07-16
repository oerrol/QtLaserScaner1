#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtLaserScaner.h"
#include "Dlg_Scanner.h"
#include <QAction>
#include <QMenuBar>


class QtLaserScaner : public QMainWindow
{
	Q_OBJECT

public:
	QtLaserScaner(QWidget *parent = Q_NULLPTR);

private:
	void open();
	void about();


private:
	Ui::QtLaserScanerClass ui;
	Dlg_Scanner *dlg_scanner;

};
