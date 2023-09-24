#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CORE_SCENE_HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CORE_SCENE_HH

#include <string>
#include <unordered_map>
#include <renderer.hh>
#include <memory>
#include <core_components.hh>
#include <entt.hpp>

namespace Recursion::core::scene
{
    class Scene
    {
    public:
        Scene(std::shared_ptr<Recursion::core::render::Renderer> renderer);
        ~Scene();

        // set up your scene
        Renderer &begin_scene(core::scene::Camera &);

        // submit items to your scene
        Renderer &submit(core::scene::GameObject &);

        // draw scene
        Renderer &draw_scene();

        // wrap up the scene (remember all these are in a loop)
        void end_scene() override;

        /**
         * @brief Create & Register a game object
         * 
         * @param object_name 
         * @return GameObject& 
         */
        GameObject& create_game_object(const std::string& object_name = "");

        GameObject& get_game_object(const entt::id_type entity_id);

        /**
         * @brief Remove Entity(Game Object) by entity_id
         * 
         * @param entity_id 
         * @return true 
         * @return false 
         */
        bool remove(const entt::id_type entity_id);

        /**
         * @brief Remove all entities(game objects) from the scene
         * 
         * @return true 
         * @return false 
         */
        bool clean();
    private:
        // Each GameObject is gonna get an Entity ID
        entt::registry scene_registry;
        std::unordered_map<entt::id_type ,GameObject> scene_objects;
        std::shared_ptr<Recursion::core::render::Renderer> scene_renderer
    };

} // namespace Recursion::core::scene

#endif