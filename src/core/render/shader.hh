#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_CONTEXT_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_CONTEXT_HH

#include <utils.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Recursion::core::render
{
    class Shader
    {

    public:
        Shader();
        Shader(std::string vs_location, std::string fs_location);
        ~Shader();

        void bind();
        void unbind();

    private:
        unsigned int program_id;
        void read_and_bind_shader(unsigned int &shader, std::string location);
    };

} // namespace Recursion::core::render

#endif