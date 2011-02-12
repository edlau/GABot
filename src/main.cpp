/********************************************************************
 * -= C++ =-
 *
 * Genetic Algorithm bot program demo
 *
 ********************************************************************/

#include <qapplication.h>
#include <qfont.h>
#include <qstring.h>
#include <qtextcodec.h>
#include <qtranslator.h>
#include <qstyle.h>
#include <qwindowsstyle.h>

#include "mainwindow.h"
#include "random.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	Random::initseed();

	a.setStyle(new QWindowsStyle);
	MainWindow *Main=new MainWindow();
	a.setMainWidget(Main);
	Main->show();

	int Err = a.exec();
	delete Main;

	return Err;
}

