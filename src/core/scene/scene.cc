#include <scene.hh>

namespace Recursion::core::scene
{
    Scene::Scene(std::shared_ptr<Recursion::core::render::Renderer> renderer) scene_renderer{renderer}
    {
    }

    Scene::~Scene()
    {
    }

    Renderer &Scene::begin_scene(core::scene::Camera & scene_camera)
    {
        scene_renderer->begin_render(scene_camera);
    }

    Renderer &Scene::submit(core::scene::GameObject & game_object)
    {
        scene_renderer->submit(game_object);
    }

    Renderer &Scene::draw_scene()
    {
        scene_renderer->render();
    }

    void Scene::end_scene()
    {
        scene_renderer->end_scene();
    }

    GameObject &Scene::create_game_object(const std::string &object_name = "")
    {
    }

    GameObject &Scene::get_game_object(const entt::id_type entity_id)
    {
    }

    bool Scene::remove(const entt::id_type entity_id)
    {
    }

    bool Scene::clean()
    {
    }
}
