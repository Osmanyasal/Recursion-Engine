#include <proj1.hh>

Proj1::Proj1() : Application{"Project1"}
{
    sh.bind(); // bind shader !
    renderer = Renderer2D::init((core::render::Shader &)sh);
    container.set_drawable_object(platforms::opengl::scene::OpenGLShapes::circle2D(1, 0, "/home/rt7/Desktop/glsl_learning/assets/container.png",1,1,10).release()); // 
    container_specular.set_drawable_object(platforms::opengl::scene::OpenGLShapes::triangle2D({1, 1, 0}, "/home/rt7/Desktop/glsl_learning/assets/container.png", 1, 1).release());
    container.get_component<core::scene::TransformComponent>().set_scale({1, 1, 1});
    container_specular.get_component<core::scene::TransformComponent>().set_translation({5, 0, 0}).set_scale({1, 1, 1});
    tile_map.set_drawable_object(platforms::opengl::scene::OpenGLShapes::tilemap2D({10, 10, -0.9f}, 1, 10).release());

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
Proj1::~Proj1() {}

void Proj1::application(float delta_time, core::events::Event &event)
{
    renderer.begin_scene(cam.on_event(event).update(delta_time));
    sh.set_uniformMatrix4fv("u_view_projection", GL_FALSE, glm::value_ptr(cam.get_view_projection_matrix()));
    sh.set_uniformMatrix4fv("u_model", GL_FALSE, glm::value_ptr(glm::scale(glm::mat4{1}, glm::vec3(10, 10, 1))));

    renderer.submit(tile_map);
    renderer.submit(container);
    renderer.submit(container_specular);

    renderer.draw_scene();
    renderer.end_scene();
}