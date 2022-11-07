#pragma once
#include <QDebug>
#include <qopenglshaderprogram.h>
#include <QOpenGLShader>
#include <QString>
#include <QMatrix4x4>
#include <QVector4D>
#include <QVector3D>

#include <iostream>
using namespace std;
class Shader
{
public:
	Shader( const QString& vertSource,const QString& fragmSource);
	~Shader();

	
	QOpenGLShaderProgram m_ShaderProgram;
public:
	void useShader();

	template<typename  T>
	void setValue(const QString& name, T  value);

private:
	
};

template<typename T>
inline void Shader::setValue(const QString& name, T value)
{
	GLuint loc = m_ShaderProgram.uniformLocation(name);
	m_ShaderProgram.setUniformValue(loc, value);
}

