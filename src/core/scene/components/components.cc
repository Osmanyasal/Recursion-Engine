
#include <components.hh>
namespace Recursion::core::scene
{
    // Component //
    const std::string Component::get_class_name() { return "Component"; }

    Component::Component() : name{"Component"}
    {
        static uint32_t next_id = 1;
        id = next_id++;
    }
    Component::~Component() {}

    const std::string &Component::get_name() const final { return name; }
    std::string Component::to_string()
    {
        std::stringstream res;
        res << "Component("
            << "id=" << id << ", "
            << "name=" << name << ")";
        return res.str();
    }

    // TransformComponent //
    const std::string TransformComponent::get_class_name() { return "TransformComponent"; }

    TransformComponent::TransformComponent()
    {
        name = "TransformComponent";
        translation = {0.0f, 0.0f, 0.0f};
        rotation = {1.0f, 0.0f, 0.0f};
        scale = {1.0f, 1.0f, 1.0f};
        rotation_degree = 0;
    }
    TransformComponent::TransformComponent(const glm::vec3 &translation,
                                           const glm::vec3 &rotation, float rotation_degree,
                                           const glm::vec3 &scale)
        : translation{translation}, rotation{rotation}, rotation_degree{rotation_degree}, scale{scale}
    {
        name = "TransformComponent";
    }
    TransformComponent::~TransformComponent() {}

    TransformComponent &TransformComponent::set_translation(const glm::vec3 &translation)
    {
        this->translation = translation;
        return *this;
    }
    TransformComponent &TransformComponent::set_rotation(const glm::vec3 &rotation)
    {
        if (OPT_UNLIKELY(rotation == glm::vec3{0}))
            this->rotation = glm::vec3{0, 0, 1};
        else
            this->rotation = rotation;

        return *this;
    }
    TransformComponent &TransformComponent::set_scale(const glm::vec3 &scale)
    {
        this->scale = scale;
        return *this;
    }

    glm::vec3 &TransformComponent::get_translation()
    {
        return this->translation;
    }
    glm::vec3 &TransformComponent::get_rotation()
    {
        return this->rotation;
    }
    glm::vec3 &TransformComponent::get_scale()
    {
        return this->scale;
    }

    float TransformComponent::get_rotation_degree()
    {
        return rotation_degree;
    }

    void TransformComponent::set_rotation_degree(float degree)
    {
        this->rotation_degree = degree;
    }

    glm::mat4 TransformComponent::get_transform()
    {
        glm::mat4 transform{1.0f};
        transform = glm::translate(transform, translation);
        transform = glm::rotate(transform, glm::radians(rotation_degree), rotation);
        transform = glm::scale(transform, scale);
        return transform;
    }
    std::string TransformComponent::to_string() override
    {
        std::stringstream res;
        res << "TransformComponent(" << Component::to_string() << ", "
            << "transform=" << glm::to_string(get_transform()) << ")";
        return res.str();
    }

    // Script Component //
    const std::string TransformComponent::get_class_name() { return "ScriptComponent"; }
    ScriptComponent::ScriptComponent(const std::string &script_name) : Component{script_name} {}
    ScriptComponent::~ScriptComponent() {}
}

#endif
