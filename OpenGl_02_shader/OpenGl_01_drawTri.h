#pragma once


#include <QWidget>
#include "ui_OpenGl_01_drawTri.h"
#include <QOpenGLWidget>
#include <qopenglfunctions_4_1_core.h>
#include "GL/GLU.H"
#include "GL/GL.H"

#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <complex>
#include <math.h>
#include <QVector4D>
#include <QTime>

#include "MyShader.h"

#include <qopengltexture.h>
class OpenGl_01_drawTri : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGl_01_drawTri(QWidget *parent = nullptr);
    ~OpenGl_01_drawTri();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    Ui::OpenGl_01_drawTriClass ui;

    QOpenGLFunctions_4_1_Core* m_GLCore;
    GLuint m_VBO;
    GLuint m_VAO;
    GLuint m_EBO;
   

    QTime time = QTime::currentTime();

    Shader* m_Shader;

    GLuint VBOPost, VBOColor, VBOTexture;
    QOpenGLTexture* m_texture;
};
