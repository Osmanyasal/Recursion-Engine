#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH

#include <string>
#include <unordered_map>
#include <components.hh>
#include <logger.hh>
#include <buffer.hh>
#include <memory>
namespace Recursion::core::scene
{
    // TODO: Fix VertexArray thing, get buffer instead
    class GameObject : public core::render::Drawable
    {
    public:
        GameObject(const std::string name = "") : id{generateGUID()}, name{name} {}
        GameObject(std::shared_ptr<core::render::Drawable> drawable_obj, const std::string name = "") : id{generateGUID()}, name{name}, drawable_obj{drawable_obj} {}
        virtual ~GameObject() {}

        void set_drawable_object(std::shared_ptr<core::render::Drawable> drawable_object)
        {
            this->drawable_obj = drawable_object;
        }

        virtual void bind() override{};
        virtual void unbind() override{};
        virtual void destroy() override{};
        virtual void draw(core::render::Shader &shader) override{};

        template <typename T>
        T &get_component()
        {
            const std::string &component_name = T::get_class_name();
            auto it = component_list.find(component_name);

            if (it != component_list.end())
            {
                T &component = dynamic_cast<T &>(*it->second);
                return component;
            }

            REC_CORE_ERROR("Component {} not found or type mismatch", component_name);
            throw std::runtime_error("Component not found or type mismatch");
        }

        void add_component(const std::shared_ptr<Component> &component)
        {
            component_list[component->get_name()] = component;
        }

    private:
        std::unordered_map<std::string, std::shared_ptr<Component>> component_list;
        std::string id;
        std::string name;
        std::shared_ptr<core::render::Drawable> drawable_obj;
    };
}

#endif