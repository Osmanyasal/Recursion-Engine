#include <linux_window.hh>
#include <cstdint>
namespace Recursion::core::window
{

    LinuxWindow::LinuxWindow(render::RenderContext<GLFWwindow> *render_context) : Window{&render_context->get_window_props()}, context{render_context}
    {
        init_Input();
        set_event_callback();
    }

    void LinuxWindow::set_event_callback() const
    {
        namespace events = Recursion::core::events;

        glfwSetCharCallback(context->get_window(), [](GLFWwindow *window, unsigned int codepoint)
                            {
                WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                events::CharTypedEvent char_event{(short int)codepoint};
                events::EventBinder event_binder{char_event};
                event_binder.bind<events::CharTypedEvent>(retrievedData.engine_callback_func); });

        glfwSetKeyCallback(context->get_window(), [](GLFWwindow *window, int key, int scancode, int action, int mods)
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

        glfwSetMouseButtonCallback(context->get_window(), [](GLFWwindow *window, int button, int action, int mods)
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

        glfwSetCursorPosCallback(context->get_window(), [](GLFWwindow *window, double xpos, double ypos)
                                 {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::MouseMovedEvent mouse_moved{xpos,ypos};
            events::EventBinder event_binder{mouse_moved};
            event_binder.bind<events::MouseMovedEvent>(retrievedData.engine_callback_func); });

        glfwSetScrollCallback(context->get_window(), [](GLFWwindow *window, double xoffset, double yoffset)
                              {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::MouseScrolledEvent mouse_moved{xoffset,yoffset};
            events::EventBinder event_binder{mouse_moved};
            event_binder.bind<events::MouseScrolledEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowCloseCallback(context->get_window(), [](GLFWwindow *window)
                                   {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            events::WindowCloseEvent winclose{};
            events::EventBinder event_binder{winclose};
            event_binder.bind<events::WindowCloseEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowFocusCallback(context->get_window(), [](GLFWwindow *window, int focused)
                                   {
                                       WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
                                       if (focused)
                                       {
                                           events::WindowFocusEvent winfocus{};
                                           events::EventBinder event_binder{winfocus};
                                           event_binder.bind<events::WindowFocusEvent>(retrievedData.engine_callback_func);
                                       }
                                       else
                                       {

                                           events::WindowLostFocusEvent winfocus{};
                                           events::EventBinder event_binder{winfocus};
                                           event_binder.bind<events::WindowLostFocusEvent>(retrievedData.engine_callback_func);
                                       } });

        glfwSetWindowSizeCallback(context->get_window(), [](GLFWwindow *window, int width, int height)
                                  {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            retrievedData.win_height = width;
            retrievedData.win_height = height;
            events::WindowResizedEvent resize{width, height};
            events::EventBinder event_binder{resize};
            event_binder.bind<events::WindowResizedEvent>(retrievedData.engine_callback_func); });

        glfwSetWindowPosCallback(context->get_window(), [](GLFWwindow *window, int posx, int posy)
                                 {
            WindowProps &retrievedData = *(WindowProps *)(glfwGetWindowUserPointer(window));
            retrievedData.win_posx = posx;
            retrievedData.win_posy = posy;
            events::WindowMovedEvent win_moved{retrievedData.win_posx, retrievedData.win_posy};
            events::EventBinder event_binder{win_moved};
            event_binder.bind<events::WindowMovedEvent>(retrievedData.engine_callback_func); });
    }

    void LinuxWindow::init_Input()
    {
        Recursion::core::input::Input::init(context->get_window());
    }

    void LinuxWindow::on_update()
    {
        context->swap_buffer();
    };

} // namespace window
