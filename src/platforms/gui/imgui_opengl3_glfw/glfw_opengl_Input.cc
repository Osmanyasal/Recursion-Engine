
#include <glfw_opengl_Input.hh>

namespace Recursion::platforms::imgui::window
{
    Glfw_OpenGL_Input::Glfw_OpenGL_Input(GLFWwindow *gl_window)
    {
        this->gl_window = gl_window;
    }
    bool Glfw_OpenGL_Input::is_key_pressed(int32_t key_code)
    {
        int32_t res = glfwGetKey(gl_window, key_code);
        return res == GLFW_PRESS || res == GLFW_REPEAT;
    }
    bool Glfw_OpenGL_Input::is_mouse_button_pressed(int32_t mouse_button_code)
    {
        return glfwGetMouseButton(gl_window, mouse_button_code) == GLFW_PRESS;
    }
    void Glfw_OpenGL_Input::get_cursor_pos(double *xpos, double *ypos)
    {
        return glfwGetCursorPos(gl_window, xpos, ypos);
    }
}