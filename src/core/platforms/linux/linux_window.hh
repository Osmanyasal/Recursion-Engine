#ifndef RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH
// TODO:set these based on the config.
#include <window.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <event_core.hh>
namespace Recursion::core::window
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps &default_props = WindowProps());
        virtual ~LinuxWindow() { glfwTerminate(); }
        virtual void on_update() override;

    protected:
        virtual void set_event_callback() const override;

    private:
        GLFWwindow *gl_window; 
    };
}
#endif