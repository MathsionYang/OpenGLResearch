#include "GLWidget.h"

GLWidget::GLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{}

GLWidget::~GLWidget() {}

void GLWidget::initializeGL() {}

void GLWidget::resizeGL(int w, int h) {}

void GLWidget::paintGL() {}

