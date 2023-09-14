#include <proj1.hh>

Proj1::Proj1() : Application{"Project1"}
{
    container.set_drawable_object(platforms::opengl::scene::OpenGLShapes::rectangle2D({1, 1, 0}, "/home/rt7/Desktop/texture.png", core::render::SubTexture{2048, 548, 32, 1628, 0}, glm::vec4{1.0f}, 1).release()); //
    container_specular.set_drawable_object(platforms::opengl::scene::OpenGLShapes::triangle2D({1, 1, 0}, "", {}, glm::vec4{1.0f}, 1).release());

    container.scale() = glm::vec3{.2, .2, 1};
    container_specular.scale() = glm::vec3{1, 1, 1};
    container_specular.translation() = glm::vec3{1, 0, 1};

    tile_map.set_drawable_object(platforms::opengl::scene::OpenGLShapes::tilemap2D({10, 10, -0.9f}, glm::vec4{1.0f}, 10).release());

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
Proj1::~Proj1() {}

void Proj1::application(float delta_time)
{
    if (Input->is_key_pressed(REC_KEY_A))
    {
        container.translation().x -= 1 * delta_time;
    }
    if (Input->is_key_pressed(REC_KEY_D))
    {
        container.translation().x += 1 * delta_time;
    }
    if (Input->is_key_pressed(REC_KEY_W))
    {
        container.translation().y += 1 * delta_time;
    }
    if (Input->is_key_pressed(REC_KEY_S))
    {
        container.translation().y -= 1 * delta_time;
    }
    renderer.submit(tile_map);
    renderer.submit(container);
    // renderer.submit(container_specular);
}