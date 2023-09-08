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
#include <renderer.hh>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <opengl_texture.hh>
#include <game_object.hh>
#include <opengl_shapes.hh>

namespace render = Recursion::opengl::render;
namespace opengl_scene = Recursion::opengl::scene;

namespace input = Recursion::core::input;
namespace events = Recursion::core::events;
namespace core_render = Recursion::core::render;
namespace scene = Recursion::core::scene;

using Recursion::core::render::Renderer2D;
class Proj1 : public Recursion::core::Application
{
public:
    Proj1();
    ~Proj1();
    virtual void application(float delta_time, events::Event &event) override;

private:
    render::OpenGLShader sh;
    
    Renderer2D renderer;
    
    render::VertexArray VAO;
    float *data;

    render::VertexArray VAO2;
    float *data2;

    render::VertexArray VAO3;
    float *data3;

    scene::GameObject obj;
    render::VertexArray* VAO4;

    Recursion::core::scene::OrthographicCamera cam{CONF__REC__WINDOW_WIDTH / CONF__REC__WINDOW_HEIGHT};
};

#endif