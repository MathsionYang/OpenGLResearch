#include "GLWidgetUI.h"

GLWidgetUI::GLWidgetUI(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  m_GLWidget = new ogl::GLWidget(this);
  this->setCentralWidget(m_GLWidget);
  connect(ui.actiontest, &QAction::triggered, this, &GLWidgetUI::on_actiontest);
 
}

GLWidgetUI::~GLWidgetUI() {}

void GLWidgetUI::on_actiontest(bool b) {

  // ���ö�������
  std::vector<float> vertices = {
      // λ��
      -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  m_GLWidget->setVertices(vertices);

  // ������ɫ����
  std::vector<float> colors = {
      // ��ɫ
      1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  m_GLWidget->setColors(colors);

  // ������������
  std::vector<float> texCoords = {// ��������
                                  0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f};
  m_GLWidget->setTexCoords(texCoords);

  // ������������ (EBO)
  std::vector<unsigned int> indices = {0, 1, 2};
  m_GLWidget->setIndices(indices);

  // �������
  QImage textureImage("../resource/image/container.jpg");
  unsigned int texId = m_GLWidget->addTexture(textureImage);

  // ������ɫ��
  m_GLWidget->setShaderProgram("D:/QOpenGLResearch/OpenGLResearch/GLWidgetUI/shader.vert",
                               "D:/QOpenGLResearch/OpenGLResearch/GLWidgetUI/shader.frag");
  m_GLWidget->update();
}
