#include <proj1.hh>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

Proj1::Proj1()
{
    /*
            in this settings

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);

            By default, based on my expierments
            it starts drawing + to -
            in collision it draws the last one on top of it
            here, sinde 0.2 is drawn later, it gets on top of it.
    */
    sh.bind(); // bind shader !

    data = new float[6 * 6]{
        // positions         // colors
        // First Triangle
         0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f,  // bottom right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, // bottom left
         0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f,   // top

        // Second Triangle
        0.9f, -0.5f, -1.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.9f, -0.5f, -1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        0.0f, 0.5f, -1.0f, 1.0f, 0.0f, 0.0f,   // top
    };
    unsigned int index[3 * 2] = {0, 2, 1, 3, 4, 5};

    VAO.bind();
    VAO.bind_vertex_buffer({data, sizeof(float) * 36})
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
        .bind_index_buffer({index, sizeof(unsigned int) * 3 * 2})
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
void Proj1::application(float delta_time)
{

    // cam.set_rotation(cam.get_rotation() + 10 * delta_time);
    sh.set_uniformMatrix4fv("mvp", 1, GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));
    VAO.bind();
    VAO.draw();

    VAO2.bind();
    VAO2.draw();
}