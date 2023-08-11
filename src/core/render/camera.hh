#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__CAMERA_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__CAMERA_HH

#include <utils.hh>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

namespace Recursion::core::render
{

    class Camera
    {
    public:
        virtual const glm::mat4 &get_view_projection_matrix() const final;
        virtual const glm::mat4 &get_projection_matrix() const final;
        virtual const glm::mat4 &get_view_matrix() const final;
        virtual const glm::vec3 &get_position() const final;
        virtual const float get_rotation() const final;

        virtual void update_camera();
        virtual void set_position(const glm::vec3 &position) final;
        virtual void set_rotation(float rotation) final;

    protected:
        Camera();
        virtual ~Camera();

    protected:
        glm::mat4 projection_matrix;
        glm::mat4 view_matrix;
        glm::mat4 view_projection_matrix;
        glm::vec3 position;
        float rotation;
    };

    class OrthographicCamera : public Camera
    {
    public:
        OrthographicCamera();
        OrthographicCamera(float left, float right, float bottom, float top);
        virtual ~OrthographicCamera();
    };

    // TODO: impelemnt perspective camera
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera();
        virtual ~PerspectiveCamera();
    };

} // namespace Recursion::core::render

#endif