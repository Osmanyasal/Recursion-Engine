#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH

#include <string>
#include <unordered_map>
#include <components.hh>
#include <buffer.hh>
namespace Recursion::core::scene
{
    class GameObject : public core::render::Drawable
    {
    public:
        GameObject(const std::string name = "");
        GameObject(core::render::Drawable *drawable_obj, const std::string name = "");
        virtual ~GameObject() {}

        void set_drawable_object(core::render::Drawable *drawable_object);
        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;
        virtual void draw(core::render::Shader &shader) override;
        void add_component(const std::shared_ptr<Component> &component);

        template <typename T>
        T &get_component();

        inline virtual bool is_transparent() override { return drawable_obj->is_transparent(); }
        
    public:
    
        inline virtual glm::vec3& translation() { return get_component<TransformComponent>().get_translation(); }
        inline virtual glm::vec3& rotation() { return get_component<TransformComponent>().get_rotation(); }
        inline virtual glm::vec3& scale() { return get_component<TransformComponent>().get_scale(); }

    private:
        std::unordered_map<std::string, std::shared_ptr<Component>> component_list;
        std::string id;
        std::string name;
        std::unique_ptr<core::render::Drawable> drawable_obj;
    };
}

#endif