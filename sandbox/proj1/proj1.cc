#include <proj1.hh>

Proj1::Proj1() : Application{"Project1"}
{ 
    container.set_drawable_object(platforms::opengl::scene::OpenGLShapes::rectangle2D({1, 1, 0}, "/home/rt7/Desktop/texture.png", core::render::SubTexture{2048, 548, 32, 1628, 0}, glm::vec4{1.0f}, 1).release()); //
    container_specular.set_drawable_object(platforms::opengl::scene::OpenGLShapes::triangle2D({1, 1, 0}, "", {}, glm::vec4{1.0f}, 1).release());

    container.scale() = glm::vec3{.5, .5, 1};
    container_specular.scale() = glm::vec3{1, 1, 1};
    container_specular.translation() = glm::vec3{1, 0, 1};

    tile_map.set_drawable_object(platforms::opengl::scene::OpenGLShapes::tilemap2D({10, 10, -0.9f}, glm::vec4{1.0f}, 10).release());

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
Proj1::~Proj1() {}

void Proj1::application(float delta_time, core::events::Event &event)
{ 

    // if (INSTANCEOF(core::events::KeyPressEvent, event))
    // {
    //     REC_WARN("KEY {} PRESSED!!!", ((core::events::KeyPressEvent &)event).get_keycode());
    //     exit(0);
    // }
 
    renderer.submit(tile_map);
    renderer.submit(container);
    // renderer.submit(container_specular);
 
}