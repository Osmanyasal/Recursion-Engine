#include <linux_window.hh>
namespace Recursion::core::window
{
    LinuxWindow::LinuxWindow(const WindowProps &default_props)
    {

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
        gl_window = glfwCreateWindow(default_props.win_width, default_props.win_height, default_props.win_title.c_str(), nullptr, nullptr);

        // Associate your data with the GLFW window
        glfwSetWindowUserPointer(gl_window, (void *)&default_props);

        /*  TODO:SET ICON

            GLFWimage images[1];
            images[0].pixels = stbi_load("PATH", &images[0].width, &images[0].height, 0, 4); // rgba channels
            glfwSetWindowIcon(gl_window, 1, images);
            stbi_image_free(images[0].pixels);
            glfwSetWindowIcon(window, 2, images);
        */
        if (OPT_UNLIKELY(!gl_window))
        {
            REC_CORE_ERROR("Failed to create GLFW window");
            return;
        }
        // Make the window's context current
        glfwMakeContextCurrent(gl_window);

        // Initialize GLEW
        if (OPT_UNLIKELY(glewInit() != GLEW_OK))
        {
            REC_CORE_ERROR("Failed to initialize GLEW");
            return;
        }

        REC_CORE_INFO("Linux Window Started (id={})", default_props.guid.substr(0, CONF__LOG__PRINT_GUID_LENGTH));
        REC_CORE_INFO("Name={}, Resoulution width={} height={}", default_props.win_title, default_props.win_width, default_props.win_height);

        set_event_callback();
    }

    void LinuxWindow::set_event_callback() const
    {
        namespace events = Recursion::core::events;

        glfwSetCharCallback(gl_window, [](GLFWwindow *window, unsigned int codepoint)
                            {
                WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                events::CharTypedEvent char_event{(unsigned int)codepoint};
                events::EventBinder event_binder{char_event};
                event_binder.bind<events::CharTypedEvent>(retrievedData.engine_callback_func); });

        glfwSetKeyCallback(gl_window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
                if(action == GLFW_PRESS || action == GLFW_REPEAT){
                    WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                    events::KeyPressEvent keypress{(short)key, (bool)mods};
                    events::EventBinder event_binder{keypress};
                    event_binder.bind<events::KeyPressEvent>(retrievedData.engine_callback_func); 
                }
                else if(action == GLFW_RELEASE){
                    WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                    events::KeyReleasedEvent release{(short)key};
                    events::EventBinder event_binder{release};
                    event_binder.bind<events::KeyReleasedEvent>(retrievedData.engine_callback_func); 
                } });

        glfwSetMouseButtonCallback(gl_window, [](GLFWwindow *window, int button, int action, int mods)
                                   {
            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                events::MouseButtonPressed mouse_press{(short)button};
                events::EventBinder event_binder{mouse_press};
                event_binder.bind<events::MouseButtonPressed>(retrievedData.engine_callback_func); 
            }else if(action == GLFW_RELEASE){
                WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                events::MouseButtonReleased mouse_released{(short)button};
                events::EventBinder event_binder{mouse_released};
                event_binder.bind<events::MouseButtonReleased>(retrievedData.engine_callback_func); 
            } });

        glfwSetCursorPosCallback(gl_window, [](GLFWwindow *window, double xpos, double ypos)
                                 {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::MouseMovedEvent mouse_moved{xpos,ypos};
            events::EventBinder event_binder{mouse_moved};
            event_binder.bind<events::MouseMovedEvent>(retrievedData.engine_callback_func); });

        glfwSetScrollCallback(gl_window, [](GLFWwindow *window, double xoffset, double yoffset)
                              {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::MouseScrolledEvent mouse_moved{xoffset,yoffset};
            events::EventBinder event_binder{mouse_moved};
            event_binder.bind<events::MouseScrolledEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowCloseCallback(gl_window, [](GLFWwindow *window)
                                   {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::WindowCloseEvent winclose{};
            events::EventBinder event_binder{winclose};
            event_binder.bind<events::WindowCloseEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowFocusCallback(gl_window, [](GLFWwindow *window, int focused)
                                   {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::WindowFocusEvent finfocus{};
            events::EventBinder event_binder{finfocus};
            event_binder.bind<events::WindowFocusEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowSizeCallback(gl_window, [](GLFWwindow *window, int width, int height)
                                  {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            retrievedData.win_height = width;
            retrievedData.win_height = height;
            events::WindowResizedEvent resize{width, height};
            events::EventBinder event_binder{resize};
            event_binder.bind<events::WindowResizedEvent>(retrievedData.engine_callback_func); });
    }

    void LinuxWindow::on_update()
    {
        // Process events
        glfwPollEvents();

        // Swap buffers
        glfwSwapBuffers(gl_window);
    };

} // namespace window
