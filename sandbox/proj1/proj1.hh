#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>
#include <opengl_shader.hh>
#include <opengl_vertex_buffer.hh>
#include <opengl_index_buffer.hh>
#include <opengl_vertex_array.hh>
#include <opengl_buffer_layout.hh>
#include <utils.hh>
#include <Input.hh>
#include <recursion.hh>
#include <camera.hh>

namespace render = Recursion::opengl::render;

class Proj1 : public Recursion::core::Engine
{
public:
    Proj1();
    ~Proj1();
    virtual void application(float delta_time) override;

private:
    render::OpenGLShader sh;

    render::VertexArray VAO;
    float *data;

    render::VertexArray VAO2;
    float *data2;

    Recursion::core::render::OrthographicCamera cam;
};

#endif