#ifndef RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH

#include <window.hh>
#include <event_core.hh>
namespace Recursion::core::window
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps &default_props = WindowProps());
        
        inline virtual ~LinuxWindow()
        {
            glfwTerminate();
        }
        virtual void on_update() override;
        virtual void init_Input(GLFWwindow*) override;
        inline GLFWwindow *get_window()
        {
            return this->gl_window;
        }

    protected:
        virtual void set_event_callback() const override;

    private:
        GLFWwindow *gl_window;
    };
}
#endif