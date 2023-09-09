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

        inline Component() : id{generateGUID()}, name{"Component"} {}
        inline virtual ~Component() {}

        inline virtual const std::string &get_name() const final { return name; }
        inline virtual std::string to_string()
        {
            std::stringstream res;
            res << "Component("
                << "id=" << id.substr(0, CONF__LOG__PRINT_GUID_LENGTH) << ", "
                << "name=" << name << ")";
            return res.str();
        }

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

        inline TransformComponent()
        {
            name = "TransformComponent";
            translation = {0.0f, 0.0f, 0.0f};
            rotation = {1.0f, 0.0f, 0.0f};
            scale = {1.0f, 1.0f, 1.0f};
            rotation_degree = 0;
        }
        inline TransformComponent(const glm::vec3 &translation,
                                  const glm::vec3 &rotation, float rotation_degree,
                                  const glm::vec3 &scale)
            : translation{translation}, rotation{rotation}, rotation_degree{rotation_degree}, scale{scale}
        {
            name = "TransformComponent";
        }
        inline virtual ~TransformComponent() {}

        TransformComponent& set_translation(const glm::vec3 &translation)
        {
            this->translation = translation;
            return *this;
        }
        TransformComponent& set_rotation(const glm::vec3 &rotation)
        {
            if (OPT_UNLIKELY(rotation == glm::vec3{0}))
                this->rotation = glm::vec3{1, 0, 0};
            else
                this->rotation = rotation;

            return *this;
        }
        TransformComponent& set_scale(const glm::vec3 &scale)
        {
            this->scale = scale;
            return *this;
        }

        glm::vec3 &get_translation()
        {
            return this->translation;
        }
        glm::vec3 &get_rotation()
        {
            return this->rotation;
        }
        glm::vec3 &get_scale()
        {
            return this->scale;
        }

        inline glm::mat4 get_transform()
        {
            glm::mat4 transform{1.0f};
            transform = glm::translate(transform, translation);
            transform = glm::rotate(transform, glm::radians(rotation_degree), rotation);
            transform = glm::scale(transform, scale);
            return transform;
        }
        inline virtual std::string to_string() override
        {
            std::stringstream res;
            res << "TransformComponent(" << Component::to_string() << ", "
                << "transform=" << glm::to_string(get_transform()) << ")";
            return res.str();
        }

    protected:
        glm::vec3 translation;
        glm::vec3 rotation;
        float rotation_degree;
        glm::vec3 scale;
    };
}

#endif
