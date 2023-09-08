#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH

#include <string>
#include <unordered_map>
#include <components.hh>
#include <buffer.hh>
namespace Recursion::core::scene
{
    // TODO: Fix VertexArray thing, get buffer instead
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

    private:
        std::unordered_map<std::string, std::shared_ptr<Component>> component_list;
        std::string id;
        std::string name;
        std::unique_ptr<core::render::Drawable> drawable_obj;
    };
}

#endif