#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__COMPONENTS__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__COMPONENTS__HH

#include <utils.hh>
namespace Recursion::core::scene
{
    /////////// Component ///////////
    class Component
    {
    public:
        static const std::string get_class_name() { return "Component"; }

        Component() : id{generateGUID()}, name{"Component"} {}
        virtual ~Component() {}

        virtual std::string to_string()
        {
            std::stringstream res;
            res << "Component("
                << "id=" << id.substr(0, CONF__LOG__PRINT_GUID_LENGTH) << ", "
                << "name=" << name << ")";
            return res.str();
        }
        virtual const std::string &get_name() const final { return name; }

    private:
        std::string id;

    protected:
        std::string name;
    };

    /////////// TransformComponent ///////////
    class TransformComponent : public Component
    {
    public:
        static const std::string get_class_name() { return "TransformComponent"; }

        TransformComponent()
        {
            name = "TransformComponent";
            translation = {0.0f, 0.0f, 0.0f};
            rotation = {0.0f, 0.0f, 0.0f};
            scale = {1.0f, 1.0f, 1.0f};
        }
        TransformComponent(const glm::vec3 &translation,
                           const glm::vec3 &rotation,
                           const glm::vec3 &scale)
            : translation{translation}, rotation{rotation}, scale{scale}
        {
            name = "TransformComponent";
        }
        virtual ~TransformComponent() {}

        glm::mat4 get_transform()
        {
            return glm::translate(glm::mat4(1.0f), translation) * glm::toMat4(glm::quat(rotation)) * glm::scale(glm::mat4(1.0f), scale);
        }
        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "TransformComponent(" << Component::to_string() << ", "
                << "transform=" << glm::to_string(get_transform()) << ")";
            return res.str();
        }

    protected:
        glm::vec3 translation;
        glm::vec3 rotation;
        glm::vec3 scale;
    };
}

#endif
