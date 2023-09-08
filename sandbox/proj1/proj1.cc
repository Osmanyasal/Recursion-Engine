#include <proj1.hh>

Proj1::Proj1() : Application{"Project1"}
{
    sh.bind(); // bind shader !
    renderer = Renderer2D::init((Recursion::core::render::Shader &)sh);

    data = new float[3 * 8]{
        // positions         // colors       // texture
        // First Triangle
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f,   // top
        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,  // bottom right
    };
    unsigned int index[3 * 1] = {0, 1, 2}; // 3, 4, 5};

    float pos[3 * 3] = {
        -0.5f,
        -0.5f,
        0.0f,

        0.0f,
        0.5f,
        0.0f,

        0.5f,
        -0.5f,
        0.0f,
    };
    float colors[3 * 3] = {
        1.0f,
        1.0f,
        1.0f,

        1.0f,
        1.0f,
        1.0f,

        1.0f,
        1.0f,
        1.0f,
    };
    float textures[3 * 2] = {
        0.0f, 0.0f, // bottom left
        0.5f, 1.0f, // top
        1.0f, 0.0f, // bottom right
    };

    auto vb = render::VertexBuffer(sizeof(pos) + sizeof(colors) + sizeof(textures))
                  .add_positions(pos, sizeof(pos))
                  .add_colors(colors, sizeof(colors))
                  .add_texture_coordinates(textures, sizeof(textures));
    VAO.bind();
    VAO.bind_vertex_buffer(vb)
        .add_layout({"position",
                     0,
                     render::Quantity::Float3, 3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"color",
                     1,
                     render::Quantity::Float3, 3,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"texture",
                     2,
                     render::Quantity::Float2, 2,
                     render::Type::Float,
                     render::Normalized::FALSE})
        // .bind_index_buffer({index, sizeof(unsigned int) * 3 * 1})
        .add_texture({"/home/rt7/Desktop/glsl_learning/assets/container.png"})
        .build_batch();

    data3 = new float[3 * 8]{
        // positions         // colors       // texture
        // First Triangle
        0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f, 1.0f, // top
        1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
    };

    VAO3.bind();
    VAO3.bind_vertex_buffer({data3, sizeof(float) * 3 * 8})
        .add_layout({"position",
                     0,
                     render::Quantity::Float3, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"color",
                     1,
                     render::Quantity::Float3, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"texture",
                     2,
                     render::Quantity::Float2, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_texture({"/home/rt7/Desktop/glsl_learning/assets/container_specular.png"})
        .build();

    data2 = new float[3 * 8]{

        -1.0f, 1.0f, 0.0f, .2f, 1.0f, 1.0f, 1.0f, 1.0f, // bottom
        -1.0f, 0.0f, 0.0f, .2f, 1.0f, 1.0f, 1.0f, 1.0f, // left
        -0.5f, 0.5f, 0.0f, .2f, 1.0f, 1.0f, 1.0f, 1.0f  // right
    };

    VAO2.bind();
    VAO2.bind_vertex_buffer({data2, sizeof(float) * 3 * 8})
        .add_layout({"position",
                     0,
                     render::Quantity::Float3, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"color",
                     1,
                     render::Quantity::Float3, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .add_layout({"texture",
                     2,
                     render::Quantity::Float2, 1,
                     render::Type::Float,
                     render::Normalized::FALSE})
        .build();

    float vertices[] = {
        // Positions (x, y)
        0.5f, 0.5f, -0.0f, 1, 1, 1, 10, 10, // Top right
        0.5f, -0.5f, -0.0f, 1, 1, 1, 10, 0, // Bottom right
        -0.5f, -0.5f, -0.0f, 1, 1, 1, 0, 0, // Bottom left
        -0.5f, 0.5f, -0.0f, 1, 1, 1, 0, 10, // Top left
    };

    uint32_t indices[] = {
        0, 3, 2, // First triangle
        0, 1, 2  // Second triangle
    };

    container.set_drawable_object(opengl_scene::OpenGLShapes::triangle2D({1, 1, 0}, "/home/rt7/Desktop/glsl_learning/assets/container.png",1,10).release());
    container.get_component<scene::TransformComponent>().set_translation({0, -15, 0});
    tile_map.set_drawable_object(opengl_scene::OpenGLShapes::tilemap2D({10, 10, -0.9f}, 1, 10).release());
}
Proj1::~Proj1()
{
    delete[] data;
    delete[] data2;
    delete[] data3;
}
void Proj1::application(float delta_time, events::Event &event)
{
    renderer.begin_scene(cam.on_event(event).update(delta_time));
    sh.set_uniformMatrix4fv("u_view_projection", GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));
    sh.set_uniformMatrix4fv("u_model", GL_FALSE, glm::value_ptr(glm::scale(glm::mat4{1}, glm::vec3(10, 10, 1))));

    renderer.submit(VAO);
    renderer.submit(VAO2);
    renderer.submit(VAO3);
    renderer.submit(tile_map);
    renderer.submit(container);

    renderer.draw_scene();
    renderer.end_scene();
}