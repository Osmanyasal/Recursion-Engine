#ifndef RECURSION_ENGINE__SRC__CORE__APPLICATION_HH
#define RECURSION_ENGINE__SRC__CORE__APPLICATION_HH

#include <app_config.hh>
#include <core_modules.hh>
#include <platform_impl.hh>

namespace Recursion::core
{
    class Application : public core::layer::Layer
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
        virtual void on_event(core::events::Event &event) override
        {
            REC_CORE_PROFILE_FUNCTION();
            application(last_delta_time, event);
        }

    protected:
        virtual void application(float delta_time, core::events::Event &event) = 0;

    public:
        const std::string app_name;
        platforms::opengl::render::OpenGLFrameBuffer framebuffer{CONF__REC__WINDOW_WIDTH, CONF__REC__WINDOW_HEIGHT};

    private:
        core::events::EmptyEvent empty_event;
        float last_delta_time;
    };
}
#endif