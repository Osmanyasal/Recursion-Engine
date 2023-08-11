#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDERER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDERER_HH

#include <window.hh>
#include <render_context.hh>
namespace Recursion::opengl::render
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