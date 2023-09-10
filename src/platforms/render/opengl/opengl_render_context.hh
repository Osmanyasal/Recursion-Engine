#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDER_CONTEXT_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDER_CONTEXT_HH

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <render_context.hh>
namespace Recursion::platforms::opengl::render
{
    class OpenGLRenderContext : public core::render::RenderContext<GLFWwindow>
    {
    public:
        OpenGLRenderContext(const core::window::WindowProps &default_props = core::window::WindowProps());
        virtual ~OpenGLRenderContext() {}
        virtual void swap_buffer() override;
    };

} // namespace Recursion::opengl::render

#endif