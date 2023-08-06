#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_SHADER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_SHADER_HH

#include <window.hh>
#include <render_context.hh>
#include <shader.hh>
namespace Recursion::opengl::render
{
    class OpenGLShader : core::render::Shader
    {
    public:
        OpenGLShader();
        OpenGLShader(std::string vs_location, std::string fs_location);
        virtual ~OpenGLShader();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void read_and_bind_shader(unsigned int &shader, std::string location) override;
    };

} // namespace Recursion::core::render

#endif