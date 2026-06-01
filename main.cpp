#include <QtGui/QApplication>
#include <QTime>
#include <QTextCodec>
#include "mainwindow.h"

extern QTranslator AppTranslator;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Setting determination of russian locale strings
    QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "Windows-1251" ));

    // Seeds RNG
    QTime midnight(0, 0, 0);
    qsrand( midnight.secsTo( QTime::currentTime() ) );

    a.installTranslator(&AppTranslator);

    MainWindow w;
    w.show();
    return a.exec();
}
