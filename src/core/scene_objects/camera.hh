#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CAMERA_HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CAMERA_HH

#include <utils.hh>
#include <core_events.hh>

namespace Recursion::core::scene
{
    class CameraController
    {
    public:
        CameraController(float step = CONF__CAMERA_CONTROLLER__STEP) : step{step} {}
        virtual ~CameraController() {} 
        virtual const glm::vec3 &get_position() const = 0;
        virtual float get_rotation() const = 0;
        virtual float get_aspect_ratio() const = 0;
        virtual void set_position(const glm::vec3 &position) = 0;
        virtual void set_rotation(float rotation) = 0;

    protected:
        virtual void update_camera() = 0;
        float step;
    };
    class Camera : public CameraController
    {
    public:
        Camera& on_event(events::Event &event); 
        Camera&  update(float delta_time);

        virtual const glm::mat4 &get_view_projection_matrix() const final;
        virtual const glm::mat4 &get_projection_matrix() const final;
        virtual const glm::mat4 &get_view_matrix() const final;

        virtual const glm::vec3 &get_position() const final override;
        virtual float get_rotation() const final override;
        virtual float get_aspect_ratio() const final override;

        virtual void update_camera() override;
        virtual void set_position(const glm::vec3 &position) override;
        virtual void set_rotation(float rotation) override;

    protected:
        Camera();
        virtual ~Camera();

        virtual bool on_scroll_call_back(events::MouseScrolledEvent &event) = 0;
        virtual bool on_monitor_resized_call_back(events::WindowResizedEvent &event) = 0;

    protected:
        glm::mat4 projection_matrix;
        glm::mat4 view_matrix;
        glm::mat4 view_projection_matrix;
        glm::vec3 position;
        float rotation;
        float aspect_ratio;
		float zoom_level;
    };

    class OrthographicCamera : public Camera
    {
    public:
        OrthographicCamera(float aspect_ratio = 1.0f);
        OrthographicCamera(float left, float right, float bottom, float top);
        virtual ~OrthographicCamera();

    protected:
        virtual bool on_scroll_call_back(events::MouseScrolledEvent &event) override;
        virtual bool on_monitor_resized_call_back(events::WindowResizedEvent &event) override;
    };

    // TODO: impelemnt perspective camera
    class PerspectiveCamera : public Camera
    {
    public:
        PerspectiveCamera(float aspect_ratio = 1.0f);
        virtual ~PerspectiveCamera();

    protected:
        virtual bool on_scroll_call_back(events::MouseScrolledEvent &event) override;
        virtual bool on_monitor_resized_call_back(events::WindowResizedEvent &event) override;
    };

} // namespace Recursion::core::render

#endif