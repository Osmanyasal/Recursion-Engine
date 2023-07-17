
#include <Input.hh>

namespace Recursion::core::input
{
    GLFWwindow *Input::gl_window = nullptr;

    void Input::init(GLFWwindow *gl_window)
    {
        Input::gl_window = gl_window;
    }
    bool Input::is_key_pressed(int key_code)
    {
        int res = glfwGetKey(Input::gl_window, key_code);
        return res == GLFW_PRESS || res == GLFW_REPEAT;
    }
    bool Input::is_mouse_button_pressed(int mouse_button_code)
    {
        return glfwGetMouseButton(Input::gl_window,mouse_button_code) == GLFW_PRESS;
    }
    void Input::get_cursor_pos(double* xpos, double* ypos)
    {
        return glfwGetCursorPos(Input::gl_window,xpos,ypos);
    }
}