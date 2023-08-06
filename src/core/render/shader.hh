#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_HH

#include <utils.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <bindable.hh>

namespace Recursion::core::render
{
    class Shader : public Bindable
    {
    public:
        Shader() {}
        virtual ~Shader() {}

    protected:
        unsigned int program_id;
        virtual void read_and_bind_shader(unsigned int &shader, std::string location) = 0;
    };

} // namespace Recursion::core::render

#endif