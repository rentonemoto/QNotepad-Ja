#include <QApplication>
#include "mainwindow.h"
#include <QTranslator>
#include <QLibraryInfo>
int main(int argc, char *argv[])
{

	QApplication app(argc, argv);
	MainWindow mainWindow;
	if(argc > 1)
		mainWindow.withFile(argv[1]);
    QTranslator translator;
    translator.load("qt_ja_JP", QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    qApp->installTranslator(&translator);
	mainWindow.show();
	return app.exec();
}
