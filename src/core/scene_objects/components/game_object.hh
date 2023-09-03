#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__COMPONENTS__GAME_OBJECT__HH

#include <string>
#include <unordered_map>
#include <components.hh>
#include <logger.hh>
namespace Recursion::core::scene
{
    class GameObject
    {
    public:
        GameObject(const std::string name, const std::string &tag = "") id{generateGUID()}, name{name}, tag{tag} {}
        virtual ~GameObject() {}

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

            std::cerr << "Component " << component_name << " not found or type mismatch" << std::endl;
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
        std::string tag;
    };
}

#endif