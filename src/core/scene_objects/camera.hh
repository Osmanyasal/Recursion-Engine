#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CAMERA_HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CAMERA_HH

#include <utils.hh>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <Input.hh>
#include <event_core.hh>

namespace Recursion::core::scene
{
    class CameraController
    {
    public:
        CameraController(float step = 1.0f) : step{step} {}
        virtual ~CameraController() {}
        virtual void update(float delta_time);
        virtual const glm::vec3 &get_position() const = 0;
        virtual const float get_rotation() const = 0;
        virtual void set_position(const glm::vec3 &position) = 0;
        virtual void set_rotation(float rotation) = 0;

    private:
        virtual void update_camera() = 0; 
        float step;
    };
    class Camera : public CameraController
    {
    public:
        virtual const glm::mat4 &get_view_projection_matrix() const final;
        virtual const glm::mat4 &get_projection_matrix() const final;
        virtual const glm::mat4 &get_view_matrix() const final;

        virtual const glm::vec3 &get_position() const final override;
        virtual const float get_rotation() const final override;

        virtual void update_camera() override;
        virtual void set_position(const glm::vec3 &position) override;
        virtual void set_rotation(float rotation) override;

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