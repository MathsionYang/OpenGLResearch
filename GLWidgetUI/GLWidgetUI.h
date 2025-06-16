#pragma once

#include <QtWidgets/QMainWindow>

#include "glui/GLWidget.h"
#include "ui_GLWidgetUI.h"
class GLWidgetUI : public QMainWindow {
  Q_OBJECT

 public:
  GLWidgetUI(QWidget* parent = nullptr);
  ~GLWidgetUI();

  public slots:
  void on_actiontest(bool b);

 private:
  Ui::GLWidgetUIClass ui;
  ogl::GLWidget* m_GLWidget = nullptr;
};
