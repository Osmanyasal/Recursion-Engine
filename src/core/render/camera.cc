#include <camera.hh>

namespace Recursion::core::render
{
    ////////// CAMERA ///////////

    Camera::Camera() {}
    Camera::~Camera() {}

    const glm::mat4 &Camera::get_view_projection_matrix() const { return view_projection_matrix; }
    const glm::mat4 &Camera::get_projection_matrix() const { return projection_matrix; }
    const glm::mat4 &Camera::get_view_matrix() const { return view_matrix; }
    const glm::vec3 &Camera::get_position() const { return position; }
    const float Camera::get_rotation() const { return rotation; }

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
    OrthographicCamera::OrthographicCamera() : OrthographicCamera(-1.0f, 1.0f, -1.0f, 1.0f) {}
    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
    {
        projection_matrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        view_matrix = glm::mat4{1.0f};
        position = glm::vec3(0.1f);
        rotation = 0.0f;
        update_camera();

        REC_TRACE("projection: {}", to_string(projection_matrix));
        REC_TRACE("view: {}", to_string(view_matrix));
        REC_TRACE("posisiton: {}", to_string(position));
        REC_TRACE("rotation: {}", rotation);
        REC_TRACE("view_projection: {}", to_string(view_projection_matrix));
    }
    OrthographicCamera::~OrthographicCamera(){}

    ////////// PERSPECTIVE CAMERA ///////////
    PerspectiveCamera::PerspectiveCamera() { update_camera(); }
    PerspectiveCamera::~PerspectiveCamera() {}

} // namespace Recursion::core::render
