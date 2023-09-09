#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_HH

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Recursion::core::input
{
    class Input
    {
    public:
        static void init(GLFWwindow* gl_window);
        static bool is_key_pressed(int32_t key_code);
        static bool is_mouse_button_pressed(int32_t mouse_button_code);
        static void get_cursor_pos(double* xpos, double* ypos);

    private:
        Input();
        ~Input();
        static GLFWwindow *gl_window;

    };
} // namespace Recursion::core::input

#endif