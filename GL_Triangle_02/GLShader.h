#pragma once

#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace GLUtils {
class  GLShader {
 public:
  GLShader(const char* vertexPath, const char* fragmentPath);
  void use();

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

 private:
  void checkCompileErrors(unsigned int shader, std::string type);

 public:
  unsigned int ID;
};
}  // namespace GLUtils
