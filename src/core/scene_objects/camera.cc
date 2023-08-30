#include <camera.hh>

namespace Recursion::core::scene
{
    ////////// CAMERA ///////////

    Camera::Camera()
    {
        this->zoom_level = 1.0f;
    }
    Camera::~Camera() {}

    Camera &Camera::on_event(events::Event &event)
    {
        switch (event.get_event_type())
        {
        case events::EventType::MouseScrolled:
            event.is_handled = on_scroll_call_back((events::MouseScrolledEvent &)event);
            break;

        case events::EventType::WindowResize:
            event.is_handled = on_monitor_resized_call_back((events::WindowResizedEvent &)event);
            break;

        default:
            break;
        }

        return *this;
    }
    
    Camera &Camera::update(float delta_time)
    {
        glm::vec3 pos = get_position();
        if (input::Input::is_key_pressed(REC_KEY_A))
            pos.x -= step * delta_time;
        if (input::Input::is_key_pressed(REC_KEY_D))
            pos.x += step * delta_time;
        if (input::Input::is_key_pressed(REC_KEY_S))
            pos.y -= step * delta_time;
        if (input::Input::is_key_pressed(REC_KEY_W))
            pos.y += step * delta_time;
        set_position(pos);

        return *this;
    }

    const glm::mat4 &Camera::get_view_projection_matrix() const { return view_projection_matrix; }
    const glm::mat4 &Camera::get_projection_matrix() const { return projection_matrix; }
    const glm::mat4 &Camera::get_view_matrix() const { return view_matrix; }
    const glm::vec3 &Camera::get_position() const { return position; }
    float Camera::get_rotation() const { return rotation; }
    float Camera::get_aspect_ratio() const { return aspect_ratio; }

    void Camera::update_camera()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
                              glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));
        view_matrix = glm::inverse(transform);
        view_projection_matrix = projection_matrix * view_matrix;
        REC_TRACE("view_projection: {}", to_string(view_projection_matrix));
    }

    void Camera::set_position(const glm::vec3 &position)
    {
        this->position = position;
        update_camera();
        REC_TRACE("posisiton: {}", to_string(position));
    }

    void Camera::set_rotation(float rotation)
    {
        this->rotation = rotation;
        update_camera();
        REC_TRACE("rotation: {}", rotation);
    }

    ////////// ORTHOGRAPHIC CAMERA ///////////
    OrthographicCamera::OrthographicCamera(float aspect_ratio) : OrthographicCamera(-aspect_ratio, aspect_ratio, -aspect_ratio, aspect_ratio)
    {
        this->aspect_ratio = aspect_ratio;
    }

    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
    {
        projection_matrix = glm::ortho(left, right, bottom, top, -1.1f, 1.1f); // depth: -1 to 1 (inclusive).
        view_matrix = glm::mat4{1.0f};
        position = glm::vec3(0, 0, 0.0f);
        rotation = 0.0f;
        update_camera();

        REC_TRACE("projection: {}", to_string(projection_matrix));
        REC_TRACE("view: {}", to_string(view_matrix));
        REC_TRACE("posisiton: {}", to_string(position));
        REC_TRACE("rotation: {}", rotation);
        REC_TRACE("view_projection: {}", to_string(view_projection_matrix));
    }

    bool OrthographicCamera::on_scroll_call_back(events::MouseScrolledEvent &event)
    {
        zoom_level = std::max(zoom_level + event.get_offset_y() * CONF__IDE__ZOOM_STEP, CONF__IDE__MIN_DISTANCE);
        zoom_level = std::min((double)zoom_level, CONF__IDE__MAX_DISTANCE);
        float borders = aspect_ratio * zoom_level;
        this->projection_matrix = glm::ortho(-borders, borders, -borders, borders);

        return true;
    }
    bool OrthographicCamera::on_monitor_resized_call_back(events::WindowResizedEvent &event)
    {
        float _width = event.get_width();
        float _height = event.get_height();
        aspect_ratio = _width / _height;
        float borders = aspect_ratio * zoom_level;
        this->projection_matrix = glm::ortho(-borders, borders, -borders, borders);
        return true;
    }

    OrthographicCamera::~OrthographicCamera() {}

    ////////// PERSPECTIVE CAMERA ///////////
    // TODO:Implement Perspective Camera
    PerspectiveCamera::PerspectiveCamera(float aspect_ratio)
    {
        this->aspect_ratio = aspect_ratio;
        update_camera();
    }
    PerspectiveCamera::~PerspectiveCamera() {}

    bool PerspectiveCamera::on_scroll_call_back(events::MouseScrolledEvent &event)
    {

        return true;
    }
    bool PerspectiveCamera::on_monitor_resized_call_back(events::WindowResizedEvent &event)
    {

        return true;
    }

} // namespace Recursion::core::render
