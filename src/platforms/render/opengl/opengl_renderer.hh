#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDERER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDERER_HH

#include <window.hh>
#include <render_context.hh>
namespace Recursion::core::render
{
    class OpenGLRenderContext : public RenderContext<GLFWwindow>
    {
    public:
        OpenGLRenderContext(const window::WindowProps &default_props = window::WindowProps());
        inline virtual ~OpenGLRenderContext() {}
        virtual void swap_buffer() override;
    };

} // namespace Recursion::core::render

#endif