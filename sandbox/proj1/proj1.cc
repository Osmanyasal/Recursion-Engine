#include <proj1.hh>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include <opengl_texture.hh>

Proj1::Proj1() : Application{"Project1"}
{
    sh.bind(); // bind shader !
    renderer = Renderer2D::init((Recursion::core::render::Shader&)sh);

    data = new float[3 * 9]{
        // positions         // colors       // texture
        // First Triangle
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f,   // top
        0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // bottom right
    };
    unsigned int index[3 * 1] = {0, 1, 2}; // 3, 4, 5};

    VAO.bind();
    VAO.bind_vertex_buffer({data, sizeof(float) * 3 * 8})
        .add_layout({"position",
                     0,
                     render::Quantity::Float3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"color",
                     1,
                     render::Quantity::Float3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"texture",
                     2,
                     render::Quantity::Float2,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .bind_index_buffer({index, sizeof(unsigned int) * 3 * 1})
        .add_texture({"/home/rt7/Desktop/glsl_learning/assets/container.png"})
        .build();

    data2 = new float[3 * 6]{

        -1.0f, 1.0f, 0.0f, .2f, 1.0f, 1.0f, // bottom
        -1.0f, 0.0f, 0.0f, .2f, 1.0f, 1.0f, // left
        -0.5f, 0.5f, 0.0f, .2f, 1.0f, 1.0f  // right
    };

    VAO2.bind();
    VAO2.bind_vertex_buffer({data2, sizeof(float) * 3 * 6})
        .add_layout({"position",
                     0,
                     render::Quantity::Float3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"color",
                     1,
                     render::Quantity::Float3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .build();
}
Proj1::~Proj1()
{
    delete[] data;
    delete[] data2;
}
void Proj1::application(float delta_time, events::Event &event)
{
    renderer.begin_scene(cam.on_event(event).update(delta_time));
    sh.set_uniformMatrix4fv("mvp", GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));

    renderer.submit(VAO);
    renderer.submit(VAO2);


    renderer.end_scene();
}