#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_CONTEXT_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_CONTEXT_HH

#include <window.hh>
namespace Recursion::core::render
{
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