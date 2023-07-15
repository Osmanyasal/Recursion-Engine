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
        Recursion::utils::BaseLogger::init();
        window = nullptr;
        is_running = true;
        layer_stack = new layer::LayerStack{};
        engine_ptr = this;
        REC_CORE_INFO("Engine Created!");
    }

    Engine::~Engine()
    {
        delete layer_stack;
        delete window;
        REC_CORE_INFO("Engine Terminated!");
    }

    bool Engine::on_event(Recursion::core::events::Event &e)
    {
        namespace events = Recursion::core::events;
        REC_CORE_INFO(e.to_string());

        for (auto iter = layer_stack->rbegin(); iter != layer_stack->rend(); iter++)
        {
            if (e.is_handled)
                break;
            if (OPT_LIKELY((*iter)->is_active()))
                (*iter)->on_event(e);
        }
        if (INSTANCEOF(events::WindowCloseEvent, e))
        {
            is_running = false;
        }
        return true;
    }

    void Engine::start()
    {
        REC_CORE_INFO("Engine Started!");
        // GENERIC CREATE_WINDOW MACRO. DEFINE YOURS IN CONFIG.HH
        CREATE_WINDOW();

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
                // REC_CORE_INFO("FPS: {}", frame_count);

                frame_count = 0;
                previous_time = current_time;
            }
            window->on_update();
        }
    }

} // namespace Recursion::core
