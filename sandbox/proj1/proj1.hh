#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>
#include <opengl_shader.hh>
#include <opengl_vertex_buffer.hh>
#include <utils.hh>
#include <Input.hh>
#include <recursion.hh>

namespace render = Recursion::opengl::render;
class Proj1 : public Recursion::core::Engine
{
public:
    Proj1();
    ~Proj1();
    virtual void application() override;

private:
    render::OpenGLShader sh;
    unsigned int vertex_array;
    render::VertexBuffer *VB;
    unsigned int index_buffer;
    float *data;

    unsigned int vertex_array2;
    unsigned int vertex_buffer2;
    unsigned int index_buffer2;
    float *data2;
};

#endif