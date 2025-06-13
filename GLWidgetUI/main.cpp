#include "GLWidgetUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GLWidgetUI window;
    window.show();
    return app.exec();
}
