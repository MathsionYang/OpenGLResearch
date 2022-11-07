#include "OpenGl_01_drawTri.h"
#include <qimage.h>
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
	m_Shader = new Shader("Shader/tri.vert", "Shader/tri.frag");
	GLfloat verticesPostion[] = {
0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
		
	};

	GLfloat verticesColor[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
		
	};

	GLfloat verticesTexturePostion[] = {
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f
		
	};


	m_GLCore->glGenVertexArrays(1, &m_VAO);
	
	// ´´½¨VBO
	m_GLCore->glGenBuffers(1, &VBOPostion);
	m_GLCore->glGenBuffers(1, &VBOColor);
	m_GLCore->glGenBuffers(1, &VBOTexturePostion);
	/// @brief 
	m_GLCore->glBindVertexArray(m_VAO);


	m_GLCore->glBindBuffer(GL_ARRAY_BUFFER, VBOPostion);
	m_GLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPostion), verticesPostion, GL_STATIC_DRAW);
	m_GLCore->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	m_GLCore->glEnableVertexAttribArray(0);

	m_GLCore->glBindBuffer(GL_ARRAY_BUFFER, VBOColor);
	m_GLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesColor), verticesColor, GL_STATIC_DRAW);
	m_GLCore->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	m_GLCore->glEnableVertexAttribArray(1);

	m_GLCore->glBindBuffer(GL_ARRAY_BUFFER, VBOTexturePostion);
	m_GLCore->glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTexturePostion), verticesTexturePostion, GL_STATIC_DRAW);
	m_GLCore->glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2* sizeof(GLfloat), (void*)0);
	m_GLCore->glEnableVertexAttribArray(2);

	m_GLCore->glBindVertexArray(0);
	

	

	m_texture = new QOpenGLTexture(QImage("face.bmp").mirrored(), QOpenGLTexture::GenerateMipMaps);
	if (!m_texture->isCreated())
		qDebug() << "ERROR::LOAD_TEXTURE_FAILED";

	m_texture->setWrapMode(QOpenGLTexture::Repeat);
	m_texture->setMinificationFilter(QOpenGLTexture::Nearest);
	m_texture->setMagnificationFilter(QOpenGLTexture::Linear);

	m_Shader->useShader();
	m_Shader->m_ShaderProgram.setUniformValue(m_Shader->m_ShaderProgram.uniformLocation("texture1"), 0);

	m_GLCore->glClearColor(0.2f,0.3f,0.3f,1.0f);
}

void OpenGl_01_drawTri::resizeGL(int w, int h)
{

}

void OpenGl_01_drawTri::paintGL()
{
	
	m_GLCore->glClear(GL_COLOR_BUFFER_BIT );
	m_GLCore->glActiveTexture(GL_TEXTURE0);
	m_texture->bind();

	m_Shader->useShader();
	m_GLCore->glBindVertexArray(m_VAO);
	m_GLCore->glDrawArrays(GL_TRIANGLES, 0, 3);
	//m_GLCore->glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	update();
}
