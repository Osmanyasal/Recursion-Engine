#include <recursion.hh>
#include <utils.hh>
namespace Recursion::core
{
    Engine *engine_ptr;

    template <typename T>
    bool core_on_event(T &e)
    {
        if (OPT_LIKELY(engine_ptr != nullptr))
            engine_ptr->on_event(e);
        return true;
    }

    Engine::Engine()
    {
        engine_ptr = this;
        Recursion::utils::BaseLogger::init();
        is_running = true;
        REC_CORE_INFO("Engine Created!");
    }

    Engine::~Engine()
    {
        REC_CORE_INFO("Engine Terminated!");
    }

    bool Engine::on_event(Recursion::core::events::Event &e)
    {
        namespace events = Recursion::core::events;
        REC_CORE_INFO("Hello from original on_event!! {}", e.to_string());
        if (INSTANCEOF(events::WindowCloseEvent, e))
            is_running = false;

        return true;
    }

    void Engine::start()
    {
        REC_CORE_INFO("Engine Started!");

        Recursion::core::window::WindowProps default_props;
        default_props.engine_callback_func = &core_on_event;
        window = new core::window::LinuxWindow{default_props};
        this->application();

        double previous_time = glfwGetTime();
        short frame_count = 0;
        while (OPT_LIKELY(is_running))
        {
            glClearColor(.6f, 0.2f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Measure speed
            double current_time = glfwGetTime();
            frame_count++;
            // If a second has passed.
            if (OPT_UNLIKELY(current_time - previous_time >= 1.0)) // delta time
            {
                // Display the frame count here any way you want.
                //REC_CORE_INFO("FPS: {}", frame_count);

                frame_count = 0;
                previous_time = current_time;
            }
            window->on_update();
        }
    }

} // namespace Recursion::core
