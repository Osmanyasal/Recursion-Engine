#include <linux_window.hh>
#include <cstdint>
namespace Recursion::platforms::linux::window
{

    LinuxWindow::LinuxWindow(core::render::RenderContext<GLFWwindow> *render_context) : Window{&render_context->get_window_props()}, context{render_context}
    {
        init_Input();
        set_event_callback();
    }

    void LinuxWindow::set_event_callback() const
    {

        glfwSetCharCallback(context->get_window(), [](GLFWwindow *window, uint32_t codepoint)
                            {
                core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                core::events::CharTypedEvent char_event{(int16_t)codepoint};
                core::events::EventBinder event_binder{char_event};
                event_binder.bind<core::events::CharTypedEvent>(retrievedData.engine_callback_func); });

        glfwSetKeyCallback(context->get_window(), [](GLFWwindow *window, int32_t key, int32_t scancode, int32_t action, int32_t mods)
                           {
                if(action == GLFW_PRESS || action == GLFW_REPEAT){
                    core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                    core::events::KeyPressEvent keypress{(int16_t)key, (bool)mods};
                    core::events::EventBinder event_binder{keypress};
                    event_binder.bind<core::events::KeyPressEvent>(retrievedData.engine_callback_func); 
                }
                else if(action == GLFW_RELEASE){
                    core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                    core::events::KeyReleasedEvent release{(int16_t)key};
                    core::events::EventBinder event_binder{release};
                    event_binder.bind<core::events::KeyReleasedEvent>(retrievedData.engine_callback_func); 
                } });

        glfwSetMouseButtonCallback(context->get_window(), [](GLFWwindow *window, int32_t button, int32_t action, int32_t mods)
                                   {
            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                core::events::MouseButtonPressed mouse_press{(int16_t)button};
                core::events::EventBinder event_binder{mouse_press};
                event_binder.bind<core::events::MouseButtonPressed>(retrievedData.engine_callback_func); 
            }else if(action == GLFW_RELEASE){
                core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                core::events::MouseButtonReleased mouse_released{(int16_t)button};
                core::events::EventBinder event_binder{mouse_released};
                event_binder.bind<core::events::MouseButtonReleased>(retrievedData.engine_callback_func); 
            } });

        glfwSetCursorPosCallback(context->get_window(), [](GLFWwindow *window, double xpos, double ypos)
                                 {
            core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
            core::events::MouseMovedEvent mouse_moved{xpos,ypos};
            core::events::EventBinder event_binder{mouse_moved};
            event_binder.bind<core::events::MouseMovedEvent>(retrievedData.engine_callback_func); });

        glfwSetScrollCallback(context->get_window(), [](GLFWwindow *window, double xoffset, double yoffset)
                              {
            core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
            core::events::MouseScrolledEvent mouse_moved{xoffset,yoffset};
            core::events::EventBinder event_binder{mouse_moved};
            event_binder.bind<core::events::MouseScrolledEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowCloseCallback(context->get_window(), [](GLFWwindow *window)
                                   {
            core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
            core::events::WindowCloseEvent winclose{};
            core::events::EventBinder event_binder{winclose};
            event_binder.bind<core::events::WindowCloseEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowFocusCallback(context->get_window(), [](GLFWwindow *window, int32_t focused)
                                   {
                                       core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
                                       if (focused)
                                       {
                                           core::events::WindowFocusEvent winfocus{};
                                           core::events::EventBinder event_binder{winfocus};
                                           event_binder.bind<core::events::WindowFocusEvent>(retrievedData.engine_callback_func);
                                       }
                                       else
                                       {

                                           core::events::WindowLostFocusEvent winfocus{};
                                           core::events::EventBinder event_binder{winfocus};
                                           event_binder.bind<core::events::WindowLostFocusEvent>(retrievedData.engine_callback_func);
                                       } });

        glfwSetWindowSizeCallback(context->get_window(), [](GLFWwindow *window, int32_t width, int32_t height)
                                  {

            glViewport(0, 0, width, height); 
            core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
            retrievedData.win_height = width;
            retrievedData.win_height = height;
            core::events::WindowResizedEvent resize{width, height};
            core::events::EventBinder event_binder{resize};
            event_binder.bind<core::events::WindowResizedEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowPosCallback(context->get_window(), [](GLFWwindow *window, int32_t posx, int32_t posy)
                                 {
            core::window::WindowProps &retrievedData = *(core::window::WindowProps *)(glfwGetWindowUserPointer(window));
            retrievedData.win_posx = posx;
            retrievedData.win_posy = posy; 
            core::events::WindowMovedEvent win_moved{retrievedData.win_posx, retrievedData.win_posy};
            core::events::EventBinder event_binder{win_moved};
            event_binder.bind<core::events::WindowMovedEvent>(retrievedData.engine_callback_func); });
    }

    void LinuxWindow::init_Input()
    {
        Recursion::core::input::Input::init(context->get_window());
    }

    void LinuxWindow::on_update()
    {
        REC_CORE_PROFILE_FUNCTION();
        context->swap_buffer();
    };

} // namespace window
