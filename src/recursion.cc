#include <recursion.hh>

namespace Recursion::core
{
    Engine *engine_ptr;

    template <typename T>
    bool core_on_event(T &e)
    {
        if (OPT_LIKELY(engine_ptr != nullptr))
            engine_ptr->on_event(e);
        return true; // at this point, event is handled
    }

    Engine::Engine() : is_running{true},
                       layer_stack{new layer::LayerStack{}}

    {
        engine_ptr = this;
        CREATE_WINDOW(); // GENERIC CREATE_WINDOW MACRO. DEFINE YOURS IN CONFIG.HH
        REC_CORE_INFO("Engine Created!");
    }

    void Engine::add_application(Application *application)
    {
        layer_stack->add_layer((Recursion::core::layer::Layer *)application);
        imgui_layer = new platforms::imgui::window::ImguiLayer_glfw_opengl_impl{((platforms::linux::window::LinuxWindow *)window)->get_window(), &application->framebuffer};
        layer_stack->add_layer(imgui_layer);
        this->application.reset(application);
        REC_CORE_INFO("Application Added!");
    }

    Engine::~Engine()
    {
        delete layer_stack;
        REC_CORE_INFO("Engine Terminated!");
    }

    bool Engine::on_event(Recursion::core::events::Event &e)
    {
        for (auto layer = layer_stack->rbegin(); layer != layer_stack->rend(); layer++)
        {
            if (OPT_LIKELY((*layer)->is_active()))
                (*layer)->on_event(e);
            if (e.is_handled)
                break;
        }

        // all these events, it's unlikely we close the app. this's the general approach.
        if (OPT_UNLIKELY(INSTANCEOF(events::WindowCloseEvent, e) && !e.is_handled))
            is_running = false;

        return true;
    }

    void Engine::start()
    {
        REC_CORE_PROFILE_FUNCTION();

        REC_CORE_INFO("Engine Started!");
        DELTA_TIME_INIT();
        while (OPT_LIKELY(is_running))
        {
            DELTA_TIME_UPDATE();
            
            application->framebuffer.bind();
            // Enable depth test
            glClearColor(.6f, 0.2f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            imgui_layer->begin_loop();

            REC_CORE_TRACE("FPS {}", GET_FPS());
            application->on_update(delta_time);

            imgui_layer->end_loop();

            window->on_update();
            application->framebuffer.unbind();
        }
    }

} // namespace Recursion::core
