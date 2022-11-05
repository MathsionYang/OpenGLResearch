#include "OpenGl_01_drawTri.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGl_01_drawTri w;
    w.show();
    return a.exec();
}
