#include "MyShader.h"

Shader::Shader(const QString& vertSource, const QString& fragmSource)
{
	QOpenGLShader vertShader(QOpenGLShader::Vertex);
	bool res = vertShader.compileSourceFile(vertSource);
	if (!res)
	{
		qDebug() << "ERROR::SHADER::VERTEX::COMPLIE_FAILED";
	}
	QOpenGLShader fragShader(QOpenGLShader::Fragment);
	res = fragShader.compileSourceFile(fragmSource);
	if (!res)
	{
		qDebug() << "ERROR::SHADER::FRAGMENT::COMPLIE_FAILED";
	}
	m_ShaderProgram.addShader(&vertShader);
	m_ShaderProgram.addShader(&fragShader);
	res = m_ShaderProgram.link();
	if (!res)
	{
		qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED";
	}
}

Shader::~Shader()
{
}

void Shader::useShader()
{
	m_ShaderProgram.bind();
}

