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
        container.translation().x -= press_left_count * delta_time;
    }
    if (Input->is_key_pressed(REC_KEY_D))
    {
        container.translation().x += press_right_count * delta_time;
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

void Proj1::application_event(core::events::Event &event)
{
    // REC_INFO("{}",((core::events::KeyPressEvent &)event).to_string());

    if ((event.get_event_type() == core::events::EventType::KeyPressed) && !((core::events::KeyPressEvent &)event).is_repeat )
    {
        if (((core::events::KeyPressEvent &)event).get_keycode() == REC_KEY_A)
        {
            press_right_count = 0;
            press_left_count = (press_left_count == 2) ? 2 : ++press_left_count;
            REC_ERROR("Left clicked is here val is -> {}",press_left_count);
        }
        if (((core::events::KeyPressEvent &)event).get_keycode() == REC_KEY_D)
        {
            press_left_count = 0;
            press_right_count = (press_right_count == 2) ? 2 : ++press_right_count;
            REC_ERROR("Right clicked is here val is -> {}",press_right_count);
        }
    }
    // if (event.get_event_type() == core::events::EventType::KeyReleased)
    // {
    //         REC_INFO("Released !!!!!!!!!!!");
    //         press_left_count = 0;
    //         press_right_count = 0;
    // }
}