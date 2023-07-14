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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, CONF__REC__GLFW_CONTEXT_VERSION_MAJOR);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, CONF__REC__GLFW_CONTEXT_VERSION_MAJOR);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a GLFW window
        gl_window = glfwCreateWindow(default_props.win_width, default_props.win_height, default_props.win_title.c_str(), nullptr, nullptr);

        // Associate your data with the GLFW window
        glfwSetWindowUserPointer(gl_window, (void *)&default_props);

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

        set_event_callback();
    }

    void LinuxWindow::set_event_callback() const
    {
        glfwSetKeyCallback(gl_window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
                               Recursion::core::events::KeyPressEvent keypress{(short)key, (bool)mods};
                               Recursion::core::events::EventBinder event_binder{keypress};
                               WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                               event_binder.bind<Recursion::core::events::KeyPressEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowCloseCallback(gl_window, [](GLFWwindow *window) {
            

        });
    }

    void LinuxWindow::on_update()
    {
        // Process events
        glfwPollEvents();

        // Swap buffers
        glfwSwapBuffers(gl_window);
    };

} // namespace window
