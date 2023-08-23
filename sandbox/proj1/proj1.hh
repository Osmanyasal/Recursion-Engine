#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>
#include <opengl_shader.hh>
#include <opengl_vertex_buffer.hh>
#include <opengl_index_buffer.hh>
#include <opengl_vertex_array.hh>
#include <opengl_buffer_layout.hh>
#include <utils.hh> 
#include <recursion.hh>
#include <camera.hh>

namespace render = Recursion::opengl::render;
namespace input = Recursion::core::input;
namespace events = Recursion::core::events;
class Proj1 : public Recursion::core::Application
{
public:
    Proj1();
    ~Proj1();
    virtual void application(float delta_time, events::Event &event) override;

private:
    render::OpenGLShader sh;

    render::VertexArray VAO;
    float *data;

    render::VertexArray VAO2;
    float *data2;

    Recursion::core::render::OrthographicCamera cam;
};

#endif