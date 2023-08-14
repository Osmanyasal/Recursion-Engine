#include <opengl_shader.hh>

namespace Recursion::opengl::render
{

  OpenGLShader::OpenGLShader() : OpenGLShader("../src/core/render/default_vertex.glsl", "../src/core/render/default_fragment.glsl")
  {
  }

  OpenGLShader::OpenGLShader(std::string vs_location, std::string fs_location)
  {
    // Create an empty vertex shader handle
    uint32_t vs = glCreateShader(GL_VERTEX_SHADER);
    uint32_t fs = glCreateShader(GL_FRAGMENT_SHADER);

    read_and_bind_shader(vs, vs_location);
    read_and_bind_shader(fs, fs_location);

    program_id = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(program_id, vs);
    glAttachShader(program_id, fs);
    glLinkProgram(program_id);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(program_id, GL_LINK_STATUS, (int32_t *)&isLinked);
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
  void OpenGLShader::read_and_bind_shader(uint32_t &shader, std::string location)
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
  void OpenGLShader::set_uniform1f(const std::string &name, float v0) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1f(temp->second, v0);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1f(uniform_location, v0);
      }
    }
  }
  void OpenGLShader::set_uniform2f(const std::string &name, float v0, float v1) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2f(temp->second, v0, v1);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2f(uniform_location, v0, v1);
      }
    }
  }
  void OpenGLShader::set_uniform3f(const std::string &name, float v0, float v1, float v2) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3f(temp->second, v0, v1, v2);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3f(uniform_location, v0, v1, v2);
      }
    }
  }
  void OpenGLShader::set_uniform4f(const std::string &name, float v0, float v1, float v2, float v3) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4f(temp->second, v0, v1, v2, v3);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4f(uniform_location, v0, v1, v2, v3);
      }
    }
  }
  void OpenGLShader::set_uniform1i(const std::string &name, int32_t v0) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1i(temp->second, v0);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1i(uniform_location, v0);
      }
    }
  }
  void OpenGLShader::set_uniform2i(const std::string &name, int32_t v0, int32_t v1) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2i(temp->second, v0, v1);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2i(uniform_location, v0, v1);
      }
    }
  }

  void OpenGLShader::set_uniform3i(const std::string &name, int32_t v0, int32_t v1, int32_t v2) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3i(temp->second, v0, v1, v2);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3i(uniform_location, v0, v1, v2);
      }
    }
  }

  void OpenGLShader::set_uniform4i(const std::string &name, int32_t v0, int32_t v1, int32_t v2, int32_t v3) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4i(temp->second, v0, v1, v2, v3);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4i(uniform_location, v0, v1, v2, v3);
      }
    }
  }

  void OpenGLShader::set_uniform1ui(const std::string &name, uint32_t v0) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1ui(temp->second, v0);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1ui(uniform_location, v0);
      }
    }
  }

  void OpenGLShader::set_uniform2ui(const std::string &name, uint32_t v0, uint32_t v1) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2ui(temp->second, v0, v1);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2ui(uniform_location, v0, v1);
      }
    }
  }

  void OpenGLShader::set_uniform3ui(const std::string &name, uint32_t v0, uint32_t v1, uint32_t v2) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3ui(temp->second, v0, v1, v2);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3ui(uniform_location, v0, v1, v2);
      }
    }
  }

  void OpenGLShader::set_uniform4ui(const std::string &name, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4ui(temp->second, v0, v1, v2, v3);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4ui(uniform_location, v0, v1, v2, v3);
      }
    }
  }

  void OpenGLShader::set_uniform1fv(const std::string &name, uint32_t count, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1fv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1fv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform2fv(const std::string &name, uint32_t count, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2fv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2fv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform3fv(const std::string &name, uint32_t count, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3fv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3fv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform4fv(const std::string &name, uint32_t count, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4fv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4fv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform1iv(const std::string &name, uint32_t count, const int32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1iv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1iv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform2iv(const std::string &name, uint32_t count, const int32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2iv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2iv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform3iv(const std::string &name, uint32_t count, const int32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3iv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3iv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform4iv(const std::string &name, uint32_t count, const int32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4iv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4iv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform1uiv(const std::string &name, uint32_t count, const uint32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform1uiv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform1uiv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform2uiv(const std::string &name, uint32_t count, const uint32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform2uiv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform2uiv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform3uiv(const std::string &name, uint32_t count, const uint32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform3uiv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform3uiv(uniform_location, count, value);
      }
    }
  }

  void OpenGLShader::set_uniform4uiv(const std::string &name, uint32_t count, const uint32_t *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniform4uiv(temp->second, count, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniform4uiv(uniform_location, count, value);
      }
    }
  }
  void OpenGLShader::set_uniformMatrix2fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix2fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix2fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix3fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix3fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix3fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix4fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix4fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix4fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix2x3fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix2x3fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix2x3fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix3x2fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix3x2fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix3x2fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix2x4fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix2x4fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix2x4fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix4x2fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix4x2fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix4x2fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix3x4fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix3x4fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix3x4fv(uniform_location, count, transpose, value);
      }
    }
  }

  void OpenGLShader::set_uniformMatrix4x3fv(const std::string &name, uint32_t count, GLboolean transpose, const float *value) const
  {
    auto temp = uniform_cache.find(name);
    if (OPT_LIKELY(temp != uniform_cache.end()))
      glUniformMatrix4x3fv(temp->second, count, transpose, value);
    else
    {
      int32_t uniform_location = glGetUniformLocation(program_id, name.c_str());
      if (OPT_UNLIKELY(uniform_location == -1))
      {
        REC_CORE_ERROR("uniform name doesn't exists {}", name);
      }
      else
      {
        uniform_cache.insert({name,uniform_location});
        glUniformMatrix4x3fv(uniform_location, count, transpose, value);
      }
    }
  }

} // namespace Recursion::opengl::render
