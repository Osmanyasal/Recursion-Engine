#include <opengl_shader.hh>

namespace Recursion::opengl::render
{

  OpenGLShader::OpenGLShader() : OpenGLShader("../src/core/render/default_vertex.glsl", "../src/core/render/default_fragment.glsl")
  {
  }

  OpenGLShader::OpenGLShader(std::string vs_location, std::string fs_location)
  {
    // Create an empty vertex shader handle
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);

    read_and_bind_shader(vs, vs_location);
    read_and_bind_shader(fs, fs_location);

    program_id = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(program_id, vs);
    glAttachShader(program_id, fs);
    glLinkProgram(program_id);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(program_id, GL_LINK_STATUS, (int *)&isLinked);
    if (OPT_UNLIKELY(isLinked == GL_FALSE))
    {
      GLint maxLength = 0;
      glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> infoLog(maxLength);
      glGetProgramInfoLog(program_id, maxLength, &maxLength, &infoLog[0]);

      // We don't need the program anymore.
      glDeleteProgram(program_id);
      // Don't leak shaders either.
      glDeleteShader(vs);
      glDeleteShader(fs);

      // Use the infoLog as you see fit.
      REC_CORE_ERROR("Shader Linking Failed for {} and {}", vs_location, fs_location);
      // In this simple program, we'll just leave
      return;
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
  }

  OpenGLShader::~OpenGLShader()
  {
    destroy();
  }

  void OpenGLShader::bind()
  {
    glUseProgram(program_id);
  }

  void OpenGLShader::unbind()
  {
    glUseProgram(0);
  }

  void OpenGLShader::destroy()
  {
    glDeleteProgram(program_id);
  }
  void OpenGLShader::read_and_bind_shader(unsigned int &shader, std::string location)
  {

    std::string code = read_file(location);
    REC_CORE_DEBUG("vs code -> \n{}", code);

    // Send the vertex shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    const char *source = code.c_str();
    glShaderSource(shader, 1, &source, 0);

    // Compile the vertex shader
    glCompileShader(shader);

    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if (OPT_UNLIKELY(isCompiled == GL_FALSE))
    {
      GLint maxLength = 0;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

      // The maxLength includes the NULL character
      std::vector<GLchar> infoLog(maxLength);
      glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

      // We don't need the shader anymore.
      glDeleteShader(shader);

      // Use the infoLog as you see fit.
      REC_CORE_ERROR("Shader Compilation Failed at location {}", location);
      // In this simple program, we'll just leave
      return;
    }
  }
} // namespace Recursion::opengl::render
