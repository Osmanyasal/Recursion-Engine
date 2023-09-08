#include <game_object.hh>

namespace Recursion::core::scene
{
    GameObject::GameObject(const std::string name) : id{generateGUID()}, name{name}, drawable_obj{nullptr}
    {
        add_component(std::make_shared<scene::TransformComponent>(glm::vec3{0}, glm::vec3{1,0,0}, 0, glm::vec3{100,100,1}));
    }
    GameObject::GameObject(core::render::Drawable *drawable_obj, const std::string name) : id{generateGUID()}, name{name}, drawable_obj{drawable_obj}
    {
        add_component(std::make_shared<scene::TransformComponent>(glm::vec3{0}, glm::vec3{1,0,0}, 0, glm::vec3{100,100,1}));
    }
    void GameObject::set_drawable_object(core::render::Drawable *drawable_object)
    {
        this->drawable_obj.reset(drawable_object);
    }

    void GameObject::bind() { drawable_obj.get()->bind(); }
    void GameObject::unbind() { drawable_obj.get()->unbind(); }
    void GameObject::destroy() { drawable_obj.get()->destroy(); }
    void GameObject::draw(core::render::Shader &shader)
    {
        scene::TransformComponent &transform_component = get_component<scene::TransformComponent>();
        auto transform_matrix = transform_component.get_transform();
        shader.set_uniformMatrix4fv("u_model", false, glm::value_ptr(transform_matrix));  
        drawable_obj.get()->draw(shader);
    }

    template <typename T>
    T &GameObject::get_component()
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

    void GameObject::add_component(const std::shared_ptr<Component> &component)
    {
        component_list[component->get_name()] = component;
    }
}