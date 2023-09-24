#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__COMPONENTS__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__COMPONENTS__HH

#include <utils.hh>
#include <core_events.hh>
namespace Recursion::core::scene
{
    /**
     * @brief Components are things that can be attached to a @see Recursion::core::scene::GameObject
     * Transform component, script component, rigid_body component etc. are common components
     *
     */

    // Component //
    class Component
    {
    public:
        static const std::string get_class_name();

        Component();
        virtual ~Component();

        virtual const std::string &get_name() const final;
        virtual std::string to_string();

    protected:
        std::string name;

    private:
        std::uint32_t id;
    };

    // TransformComponent //
    class TransformComponent : public Component
    {
    public:
        static const std::string get_class_name();
        TransformComponent();
        TransformComponent(const glm::vec3 &translation,
                           const glm::vec3 &rotation, float rotation_degree,
                           const glm::vec3 &scale);
        virtual ~TransformComponent();

        TransformComponent &set_translation(const glm::vec3 &translation);
        TransformComponent &set_rotation(const glm::vec3 &rotation);
        TransformComponent &set_scale(const glm::vec3 &scale);
        glm::vec3 &get_translation();
        glm::vec3 &get_rotation();
        glm::vec3 &get_scale();

        float get_rotation_degree();

        void set_rotation_degree(float degree);

        glm::mat4 get_transform();
        virtual std::string to_string() override;

    protected:
        glm::vec3 translation;
        glm::vec3 rotation;
        float rotation_degree;
        glm::vec3 scale;
    };

    class ScriptComponent : public Component
    {
    public:
        ScriptComponent(const std::string &script_name);
        virtual ~ScriptComponent();

        virtual void begin() = 0;
        virtual void on_update(float delta_time) = 0;
        virtual void on_event(core::events::Event &event) = 0;
    };
}

#endif
