#ifndef RECURSION_ENGINE__SRC__UTILS__WINDOW_HH
#define RECURSION_ENGINE__SRC__UTILS__WINDOW_HH

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <utils.hh>
#include <event.hh>

namespace Recursion::core::window
{

    struct WindowProps
    {
        std::string win_title;
        int win_width;
        int win_height;

        WindowProps(std::string title = "Recursion Engine", int width = 1600, int height = 900) : win_title{title}, win_width{width}, win_height{height}
        {
        }
    };

    // interface representing a window system based Linux
    class Window
    {
    public:
        inline Window() {}
        inline virtual ~Window() {}

        virtual void set_event_callback() = 0;
        virtual int get_width() = 0;
        virtual int get_height() = 0;

        virtual Window *create(const WindowProps &default_props = WindowProps()) = 0;
    };

} // namespace Recursion::core::window

#endif