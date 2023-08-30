#ifndef RECURSION_ENGINE__SRC__CORE__RECURSION_HH
#define RECURSION_ENGINE__SRC__CORE__RECURSION_HH

#include <iostream>
#include <utils.hh>
#include <event_core.hh>
#include <layer_stack.hh>
#include <imgui_impl.hh>
#include <Input.hh>
#include <linux_window.hh>
#include <opengl_render_context.hh>
namespace Recursion::core
{

    // global on_event function
    extern Engine *engine_ptr;
    template <typename T>
    bool core_on_event(T &e);

    class Application : public layer::Layer
    {
    public:
        Application(const std::string &app_name) : app_name{app_name} {}
        virtual ~Application() {}

        virtual void on_attach() override {}
        virtual void on_detach() override {}
        virtual void on_update(float delta_time) override
        {
            REC_CORE_PROFILE_FUNCTION();
            last_delta_time = delta_time;
            application(delta_time, empty_event);
        }
        virtual void on_event(events::Event &event) override
        {
            REC_CORE_PROFILE_FUNCTION();
            application(last_delta_time, event);
        }

    protected:
        virtual void application(float delta_time, events::Event &event) = 0;

    public:
        const std::string app_name;

    private:
        core::events::EmptyEvent empty_event;
        float last_delta_time;
    };

    class Engine
    {
    public:
        Engine();
        virtual ~Engine();
        void add_application(Application *application);
        virtual void start() final;

        bool on_event(Recursion::core::events::Event &e);

    private:
        std::unique_ptr<Application> application;
        bool is_running;
        window::Window *window;
        window::ImguiLayer_glfw_opengl_impl *imgui_layer;
        layer::LayerStack *layer_stack;
    };

} // namespace Recursion

#endif
