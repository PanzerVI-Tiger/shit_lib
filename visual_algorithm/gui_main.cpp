#include "visual_algorithm.h"

#include <QtWidgets/QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    visual_algorithm w;
    w.show();
    QByteArray l;
	
    return a.exec();
}
