#include <opengl_render_context.hh>

namespace Recursion::platforms::opengl::render
{
    OpenGLRenderContext::OpenGLRenderContext(const core::window::WindowProps &default_props) : RenderContext{core::render::RenderAPI::OPENGL}
    {
        REC_CORE_PROFILE_FUNCTION();

        this->set_window_props(default_props);

        // Initialize GLFW
        if (OPT_UNLIKELY(!glfwInit()))
        {
            REC_CORE_ERROR("Failed to initialize GLFW");
            return;
        }

        // Set GLFW window hints (optional)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CONF__REC__GLFW_CONTEXT_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CONF__REC__GLFW_CONTEXT_VERSION_MAJOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a GLFW window
        GLFWwindow *window = glfwCreateWindow(get_window_props().win_width, get_window_props().win_height, get_window_props().win_title.c_str(), nullptr, nullptr);
        this->set_window(window);

        if (OPT_UNLIKELY(!this->get_window()))
        {
            REC_CORE_ERROR("Failed to create GLFW window");
            return;
        }
        glfwSetWindowPos(this->get_window(), get_window_props().win_posx, get_window_props().win_posy);
        // Associate your data with the GLFW window
        glfwSetWindowUserPointer(this->get_window(), (void *)&get_window_props());
        // Make the window's context current
        glfwMakeContextCurrent(this->get_window());

        // Initialize GLEW
        if (OPT_UNLIKELY(glewInit() != GLEW_OK))
        {
            REC_CORE_ERROR("Failed to initialize GLEW");
            return;
        }

        glfwSwapInterval(1); // 1 enables VSync, 0 disables it

        // Standard deoth test
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        // Standard transparency blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        REC_CORE_INFO("Linux Window Started (id={})", get_window_props().guid.substr(0, CONF__LOG__PRINT_GUID_LENGTH));
        REC_CORE_INFO("Name={}, Resoulution width={} height={}", get_window_props().win_title, get_window_props().win_width, get_window_props().win_height);
    }

    void OpenGLRenderContext::swap_buffer()
    {
        // Swap buffers
        glfwSwapBuffers(get_window());
        
        // Process events
        glfwPollEvents();
    }
} // namespace Recursion::core::render