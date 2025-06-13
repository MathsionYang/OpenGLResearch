#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GLWidgetUI.h"

class GLWidgetUI : public QMainWindow
{
    Q_OBJECT

public:
    GLWidgetUI(QWidget *parent = nullptr);
    ~GLWidgetUI();

private:
    Ui::GLWidgetUIClass ui;
};

