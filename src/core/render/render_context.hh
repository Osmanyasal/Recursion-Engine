#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_CONTEXT_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_CONTEXT_HH

#include <window.hh>
namespace Recursion::core::render
{
    /**
     * @brief This class is about the window that we see that all the rendering is taking place
     * as window technology one can use glfw (for opengl and vulkan since it supports them) or any other like metal or d3d supports
     * we would like to have the followings
     * 
     *  class OpenGLRenderContext : public RenderContext<GLFWwindow>
     *  class VulkanRenderContext : public RenderContext<GLFWwindow>
     * 
     * and is given to a window technology as follows
     * 
     * 
     * window = new Recursion::core::window::LinuxWindow{new Recursion::core::render::OpenGLRenderContext{default_props}};
     * 
     * linux window can be constructed for opengl or vulkan etc.
    */
    template <typename T>
    class RenderContext
    {
    public:
        inline RenderContext() {}
        virtual ~RenderContext() {}

        virtual void swap_buffer() = 0;

        inline virtual T *get_window() final { return window; }
        inline virtual void set_window(T *window) final { this->window = window; }

        inline virtual void set_window_props(const window::WindowProps &render_window_props) final { this->render_window_props = render_window_props; } // copy asggin
        inline virtual const window::WindowProps &get_window_props() const final { return this->render_window_props; }

    private:
        T *window; // GLFWwindow ie.
        window::WindowProps render_window_props;
    };

} // namespace Recursion::core::render
#endif