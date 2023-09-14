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
        Application(const std::string &app_name) : app_name{app_name}
        {
            sh.bind(); // bind shader !
            renderer = core::render::Renderer2D::init((core::render::Shader &)sh);
        }
        virtual ~Application() {}

        virtual void on_attach() override {}
        virtual void on_detach() override {}
        virtual void on_update(float delta_time) override
        {
            REC_PROFILE_FUNCTION();

            last_delta_time = delta_time;
            renderer.begin_scene(cam.on_event(empty_event).update(delta_time));
            application(delta_time, empty_event);
            sh.set_uniformMatrix4fv("u_view_projection", GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));
            renderer.draw_scene();
            renderer.end_scene();
        }
        virtual void on_event(core::events::Event &event) override
        {
            REC_PROFILE_FUNCTION();

            renderer.begin_scene(cam.on_event(event).update(last_delta_time));
            application(last_delta_time, event);
            sh.set_uniformMatrix4fv("u_view_projection", GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));
            renderer.draw_scene();
            renderer.end_scene();
        }

    protected:
        virtual void application(float delta_time, core::events::Event &event) = 0;
        shader sh;
        core::render::Renderer2D renderer;
        OrthographicCamera cam{CONF__REC__WINDOW_WIDTH / CONF__REC__WINDOW_HEIGHT};

    public:
        const std::string app_name;
        OpenGLFrameBuffer framebuffer{CONF__REC__WINDOW_WIDTH, CONF__REC__WINDOW_HEIGHT};

    private:
        events::EmptyEvent empty_event;
        float last_delta_time;
    };
}
#endif