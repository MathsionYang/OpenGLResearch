#include "GLWidgetUI.h"

GLWidgetUI::GLWidgetUI(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  m_GLWidget = new ogl::GLWidget(this);
  this->setCentralWidget(m_GLWidget);
  connect(ui.actiontest, &QAction::triggered, this, &GLWidgetUI::on_actiontest);
 
}

GLWidgetUI::~GLWidgetUI() {}

void GLWidgetUI::on_actiontest(bool b) {

  // 设置顶点数据
  std::vector<float> vertices = {
      // 位置
      -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  m_GLWidget->setVertices(vertices);

  // 设置颜色数据
  std::vector<float> colors = {
      // 颜色
      1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
  m_GLWidget->setColors(colors);

  // 设置纹理坐标
  std::vector<float> texCoords = {// 纹理坐标
                                  0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f};
  m_GLWidget->setTexCoords(texCoords);

  // 设置索引数据 (EBO)
  std::vector<unsigned int> indices = {0, 1, 2};
  m_GLWidget->setIndices(indices);

  // 添加纹理
  QImage textureImage("../resource/image/container.jpg");
  unsigned int texId = m_GLWidget->addTexture(textureImage);

  // 设置着色器
  m_GLWidget->setShaderProgram("D:/QOpenGLResearch/OpenGLResearch/GLWidgetUI/shader.vert",
                               "D:/QOpenGLResearch/OpenGLResearch/GLWidgetUI/shader.frag");
  m_GLWidget->update();
}
