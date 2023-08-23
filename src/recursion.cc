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
        // GENERIC CREATE_WINDOW MACRO. DEFINE YOURS IN CONFIG.HH
        CREATE_WINDOW();

        engine_ptr = this;
        is_running = true;

        layer_stack = new layer::LayerStack{};
        imgui_layer = new window::ImguiLayer_glfw_opengl_impl{((window::LinuxWindow *)window)->get_window()};
        layer_stack->add_layer(imgui_layer); 

        REC_CORE_INFO("Engine Created!");
    }
    
    void Engine::add_application(Application *application){
        layer_stack->add_layer(application);
        this->application.reset(application);
    }

    Engine::~Engine()
    {
        delete layer_stack;
        REC_CORE_INFO("Engine Terminated!");
    }

    bool Engine::on_event(Recursion::core::events::Event &e)
    {
        namespace events = Recursion::core::events;
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
        REC_CORE_INFO("Engine Started!");
        DELTA_TIME_INIT();
        while (OPT_LIKELY(is_running))
        {
            DELTA_TIME_UPDATE();
            // Enable depth test
            glClearColor(.6f, 0.2f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            imgui_layer->begin_loop();
 
            REC_CORE_TRACE("FPS {}", GET_FPS()); 
            application->on_update(delta_time);

            imgui_layer->end_loop();
            window->on_update();

        }
    }

} // namespace Recursion::core
