#pragma once
#include <qopenglshaderprogram.h>
#include <QOpenGLShader>
#include <QString>
#include "glm/fwd.hpp"
namespace ogl {
class Shader {
 public:
  Shader(const QString& vertSource, const QString& fragmSource);
  ~Shader();
  template <typename T>
  void setValuel(const std::string& name, T value) const {
    if constexpr (std::is_same_v<T, bool>) {
      glUniform1i(glGetUniformLocation(ID, name.c_str()),
                  static_cast<int>(value));
    } else if constexpr (std::is_same_v<T, int>) {
      glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    } else if constexpr (std::is_same_v<T, float>) {
      glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    } else {
      static_assert(false, "Unsupported type for setvaluel");
    }
  }
  void setVector3(const std::string& name, float x, float y, float z);

  void setVector3(const std::string& name, const float* values);

  void setVector3(const std::string& name, const glm::vec3 value);

  void setMatrix4x4(const std::string& name, glm::mat4 value);

  void setMatrix4x4Array(const std::string& name, glm::mat4* value, int count);

  void setMatrix3x3(const std::string& name, glm::mat3 value);
 public:
  QOpenGLShaderProgram m_ShaderProgram;
  GLuint nID;
};
}  // namespace ogl