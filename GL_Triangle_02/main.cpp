#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GLShader.h"
#include <iostream>
//void processInput(GLFWwindow* window) {
//  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//    glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback
//// function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//  // make sure the viewport matches the new window dimensions; note that width
//  // and height will be significantly larger than specified on retina displays.
//  glViewport(0, 0, width, height);
//}
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource =
//    "#version 330 core\n"
//    "layout (location = 0) in vec3 aPos;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//    "}\0";
//const char* fragmentShader1Source =
//    "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "uniform vec4 ourColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = ourColor;\n"
//    "}\n\0";
//const char* fragmentShader2Source =
//    "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//    "}\n\0";
//int main() {
//  glfwInit();
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//  GLFWwindow* window =
//      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//  if (window == NULL) {
//    std::cout << "Failed to create GLFW window" << std::endl;
//    glfwTerminate();
//    return -1;
//  }
//  glfwMakeContextCurrent(window);
//  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//  // glad: load all OpenGL function pointers
//  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//    std::cout << "Failed to initialize GLAD" << std::endl;
//    return -1;
//  }
//
//  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//  GLUtils::GLShader shader("shader.vs", "shader.fs");
//  // build and compile our shader program
//  // ------------------------------------
//  // vertex shader
// 
//  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//  glCompileShader(vertexShader);
//  int success;
//  char infoLog[512];
//  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//  if (!success) {
//    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
//              << infoLog << std::endl;
//  }
//
//  // fragment shader
//  unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//  glShaderSource(fragmentShader1, 1, &fragmentShader1Source, NULL);
//  glCompileShader(fragmentShader1);
//
//  // check for shader compile errors
//  glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
//  if (!success) {
//    glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
//    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
//              << infoLog << std::endl;
//  }
//
//  unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//  glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
//  glCompileShader(fragmentShader2);
//
//  unsigned int shaderProgram1 = glCreateProgram();
//  unsigned int shaderProgram2 = glCreateProgram();
//  glAttachShader(shaderProgram1, vertexShader);
//  glAttachShader(shaderProgram1, fragmentShader1);
//  glLinkProgram(shaderProgram1);
//  glAttachShader(shaderProgram2, vertexShader);
//  glAttachShader(shaderProgram2, fragmentShader2);
//  glLinkProgram(shaderProgram2);
//
//  glDeleteShader(vertexShader);
//  glDeleteShader(fragmentShader1);
//  glDeleteShader(fragmentShader2);
//
//  
//
//
//  float vertices[] = {
//      0.5f,  0.5f,  0.0f,  // top right
//      0.5f,  -0.5f, 0.0f,  // bottom right
//      -0.5f, -0.5f, 0.0f,  // bottom left
//      -0.5f, 0.5f,  0.0f   // top left
//  };
//  unsigned int indices[] = {
//      // note that we start from 0!
//      0, 1, 3,  // first Triangle
//      1, 2, 3   // second Triangle
//  };
//  unsigned int VBO, VAO, EBO;
//  glGenVertexArrays(1, &VAO);
//  glGenBuffers(1, &VBO);
//  glGenBuffers(1, &EBO);
//
//  glBindVertexArray(VAO);
//  glBindBuffer(GL_ARRAY_BUFFER, VBO);
//  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
//               GL_STATIC_DRAW);
//  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//  glEnableVertexAttribArray(0);
//
//  glBindBuffer(GL_ARRAY_BUFFER, 0);
//  glBindVertexArray(0);
//
//  while (!glfwWindowShouldClose(window)) {
//    // input
//    // -----
//    processInput(window);
//
//    // render
//    // ------
//    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // draw our first triangle
//    glUseProgram(shaderProgram1);
//    glBindVertexArray(VAO);  // seeing as we only have a single VAO there's no
//                             // need to bind it every time, but we'll do so to
//                             // keep things a bit more organized
//    float timeValue = glfwGetTime();
//    float greenValue = sin(timeValue) / 2.0f + 0.5f;
//    int vertexColorLocation = glGetUniformLocation(shaderProgram1, "ourColor");
//    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//
//
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
//
//    glUseProgram(shaderProgram2);
//    glBindVertexArray(VAO);  // seeing as we only have a single VAO there's no
//                             // need to bind it every time, but we'll do so to
//                             // keep things a bit more organized
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,
//                   (void*)(3 * sizeof(float)));
//
//    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    // glBindVertexArray(0); // no need to unbind it every time
//
//    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
//    // etc.)
//    // -------------------------------------------------------------------------------
//    glfwSwapBuffers(window);
//    glfwPollEvents();
//  }
//
//  // optional: de-allocate all resources once they've outlived their purpose:
//  // ------------------------------------------------------------------------
//  glDeleteVertexArrays(1, &VAO);
//  glDeleteBuffers(1, &VBO);
//  glDeleteBuffers(1, &EBO);
//  glDeleteProgram(shaderProgram1);
//  glDeleteProgram(shaderProgram2);
//
//  // glfw: terminate, clearing all previously allocated GLFW resources.
//  // ------------------------------------------------------------------
//  glfwTerminate();
//  return 0;
//}



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  // --------------------
  GLFWwindow* window =
      glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // build and compile our shader program
  // ------------------------------------
  GLUtils::GLShader ourShader("shader.vs", "shader.fs");

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
      // positions         // colors
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
      0.0f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f   // top
  };

  unsigned int VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and
  // then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  // You can unbind the VAO afterwards so other VAO calls won't accidentally
  // modify this VAO, but this rarely happens. Modifying other VAOs requires a
  // call to glBindVertexArray anyways so we generally don't unbind VAOs (nor
  // VBOs) when it's not directly necessary. glBindVertexArray(0);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window)) {
    // input
    // -----
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // render the triangle
    ourShader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved
    // etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}