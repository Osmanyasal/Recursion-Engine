#include <linux_window.hh>
namespace Recursion::core::window
{
    LinuxWindow::LinuxWindow(const WindowProps &default_props)
    {
        // Initialize GLFW
        if (!glfwInit())
        {
            REC_CORE_ERROR("Failed to initialize GLFW");
            return;
        }

        // Set GLFW window hints (optional)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, REC_GLFW_CONTEXT_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, REC_GLFW_CONTEXT_VERSION_MINOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a GLFW window
        gl_window = glfwCreateWindow(default_props.win_width, default_props.win_height, default_props.win_title.c_str(), nullptr, nullptr);

        /*  SET ICON

            GLFWimage images[1];
            images[0].pixels = stbi_load("PATH", &images[0].width, &images[0].height, 0, 4); // rgba channels
            glfwSetWindowIcon(gl_window, 1, images);
            stbi_image_free(images[0].pixels);
            glfwSetWindowIcon(window, 2, images);
        */
        if (!gl_window)
        {
            REC_CORE_ERROR("Failed to create GLFW window");
            return;
        }
        // Make the window's context current
        glfwMakeContextCurrent(gl_window);

        // Initialize GLEW
        if (glewInit() != GLEW_OK)
        {
            REC_CORE_ERROR("Failed to initialize GLEW");
            return;
        }

        REC_CORE_INFO("Linux Window Started (id={})", default_props.guid.substr(0, 4));
        REC_CORE_INFO("Name={}, Resoulution width={} height={}", default_props.win_title, default_props.win_width, default_props.win_height);
    }

    void LinuxWindow::set_event_callback()
    {
    }

    void LinuxWindow::on_update()
    {
        // Process events
        glfwPollEvents();

        // Swap buffers
        glfwSwapBuffers(gl_window);
    };

} // namespace window
