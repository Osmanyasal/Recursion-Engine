#ifndef RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH

#include <window.hh>
#include <opengl_render_context.hh>
#include <memory>
namespace Recursion::platforms::linux::window
{
    class LinuxWindow : public core::window::Window
    {
    public:
        LinuxWindow(core::render::RenderContext<GLFWwindow> *render_context);

        virtual ~LinuxWindow()
        {
            REC_CORE_ERROR("Linux window terminated!!");
            glfwTerminate();
            delete context.get();
        }
        virtual void on_update() override;
        virtual void init_Input() override;

        inline const core::render::RenderContext<GLFWwindow> *get_context()
        {
            return context.get();
        }
        inline GLFWwindow *get_window()
        {
            return context->get_window();
        }

    protected:
        virtual void set_event_callback() const override;

    private:
        std::unique_ptr<core::render::RenderContext<GLFWwindow>> context;
    };
}
#endif