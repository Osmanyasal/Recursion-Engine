
#include <shader.hh>

namespace Recursion::core::render
{

    Shader::Shader() : Shader("../src/core/render/base_vertex.glsl", "../src/core/render/base_fragment.glsl")
    {
    }

    Shader::Shader(std::string vs_location, std::string fs_location)
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

        // Always detach shaders after a successful link.
        glDetachShader(program_id, vs);
        glDetachShader(program_id, fs);
    }

    Shader::~Shader()
    {
    }

    void Shader::bind()
    {
        glUseProgram(program_id);
    }

    void Shader::unbind()
    {
        glUseProgram(0);
    }

    void Shader::read_and_bind_shader(unsigned int &shader, std::string location)
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
}