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
        Application(const std::string &app_name);
        virtual ~Application();

        virtual void on_attach() override;
        virtual void on_detach() override;
        virtual void on_update(float delta_time) override;
        virtual void on_event(core::events::Event &event) override;

    protected:
        virtual void application(float delta_time) = 0;
        virtual void application_event(core::events::Event &event){}
        shader sh;
        core::render::Renderer2D renderer;
        OrthographicCamera cam{CONF__REC__WINDOW_WIDTH / CONF__REC__WINDOW_HEIGHT};

    public:
        const std::string app_name;
        OpenGLFrameBuffer framebuffer{CONF__REC__WINDOW_WIDTH, CONF__REC__WINDOW_HEIGHT};

    private:
        float last_delta_time;
    };
}
#endif