#include "OpenGl_01_drawTri.h"

OpenGl_01_drawTri::OpenGl_01_drawTri(QWidget *parent)
    : QOpenGLWidget(parent)
{
    //ui.setupUi(this);
}

OpenGl_01_drawTri::~OpenGl_01_drawTri()
{
}

void OpenGl_01_drawTri::initializeGL()
{
	m_GLCore = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_4_1_Core>();

	GLfloat vertices[] = {
		0.5f,0.5f,0.0f,
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		-0.5f,0.5f,0.0f
	};
	GLuint indices[] = {
		0,1,3,
		1,3,2
	};

	m_GLCore->glGenVertexArrays(1, &m_VAO);
	m_GLCore->glBindVertexArray(m_VAO);

	// 创建VBO
	m_GLCore->glGenBuffers(1, &m_VBO);
	m_GLCore->glGenBuffers(1, &m_EBO);

	//绑定缓冲对象
	m_GLCore->glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	m_GLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	m_GLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	m_GLCore->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	m_GLCore->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	m_GLCore->glEnableVertexAttribArray(0);

	m_GLCore->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	m_GLCore->glBindVertexArray(0);
	m_GLCore->glBindBuffer(GL_ARRAY_BUFFER, 0);
	m_GLCore->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	//顶点着色器
	QOpenGLShader vertexShader(QOpenGLShader::Vertex);

	QOpenGLShader fragemnShader(QOpenGLShader::Fragment);


	vertexShader.compileSourceFile("Shader/tri.vert");
	fragemnShader.compileSourceFile("Shader/tri.frag");

	shaderProgram.addShader(&vertexShader);
	shaderProgram.addShader(&fragemnShader);
	shaderProgram.link();


}

void OpenGl_01_drawTri::resizeGL(int w, int h)
{

}

void OpenGl_01_drawTri::paintGL()
{
	m_GLCore->glClearColor(qAbs(sin((float)time.elapsed() / 1000.0)), 0.4f, 0.6f, 1.0f);
	m_GLCore->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	shaderProgram.bind();

	GLuint location = shaderProgram.uniformLocation("ourColor");
	shaderProgram.setUniformValue(location, QVector4D(0.4, qAbs(sin((float)time.elapsed() / 1000.0)), 0.8, 1.0));

	m_GLCore->glBindVertexArray(m_VAO);


	//m_GLCore->glDrawArrays(GL_TRIANGLES,0,3);

	m_GLCore->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	update();
}
