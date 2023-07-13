#include <recursion.hh>
#include <utils.hh>
namespace Recursion::core
{   

    bool core_on_event(Recursion::core::events::Event &e)
    {
        REC_CORE_INFO(EVENT_TO_STRING(e));
        return true;
    }

    Engine::Engine()
    {
        Recursion::utils::BaseLogger::init();
        is_running = true;
        REC_CORE_INFO("Engine Created!");
    }

    Engine::~Engine()
    {
        REC_CORE_INFO("Engine Terminated!");
    }

    bool Engine::on_event(Recursion::core::events::Event &e) const
    {
        // REC_CORE_INFO(EVENT_TO_STRING(e));
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
        while (is_running)
        {
            glClearColor(.6f, 0.2f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Measure speed
            double current_time = glfwGetTime();
            frame_count++;
            // If a second has passed.
            if (current_time - previous_time >= 1.0) // delta time
            {
                // Display the frame count here any way you want.
                REC_CORE_INFO("FPS: {}", frame_count);

                frame_count = 0;
                previous_time = current_time;
            }
            window->on_update();
        }
    }

} // namespace Recursion::core
