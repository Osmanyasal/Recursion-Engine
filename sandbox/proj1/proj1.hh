#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>

using Recursion::core::render::Renderer2D;
class Proj1 : public Recursion::core::Application
{
public:
    Proj1();
    ~Proj1();
    virtual void application(float delta_time, core::events::Event &event) override;

private:
    platforms::opengl::render::OpenGLShader sh;
    Renderer2D renderer;
    
    core::scene::GameObject container;
    core::scene::GameObject container_specular;
    core::scene::GameObject tile_map;
    Recursion::core::scene::OrthographicCamera cam{CONF__REC__WINDOW_WIDTH / CONF__REC__WINDOW_HEIGHT};
};

#endif