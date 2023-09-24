#include <application.hh>

namespace Recursion::core
{
    Application::Application(const std::string &app_name) : app_name{app_name}
    {
        sh.bind(); // bind shader !
        scene1 = core::render::Renderer2D::init((core::render::Shader &)sh, platforms::opengl::render::OpenGLTexture::TEXTURE_UNIT_LIMIT);
    }
    Application::~Application() {}

    void Application::on_attach() {}
    void Application::on_detach() {}
    void Application::on_update(float delta_time)
    {
        REC_PROFILE_FUNCTION();
        last_delta_time = delta_time;

        scene1.begin_scene(scene_camera.update(delta_time));
        application(delta_time);
        sh.set_uniformMatrix4fv("u_view_projection", GL_FALSE, glm::value_ptr(scene_camera.get_view_projection_matrix()));
        scene1.draw_scene();
        scene1.end_scene();
    }
    void Application::on_event(core::events::Event &event)
    {
        REC_PROFILE_FUNCTION();
        scene1.begin_scene(scene_camera.on_event(event).update(last_delta_time));
        application_event(event);
    }
}