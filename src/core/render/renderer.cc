
#include <renderer.hh>

namespace Recursion::core::render
{

    ////////// RENDERER //////////
    void Renderer::set_shader_program(Shader *shader)
    {
        _shader.reset((Shader *)shader);
    }

    ////////// RENDERER 2D //////////
    const Renderer2D &Renderer2D::init(Shader &shader,uint32_t object_treshold)
    {
        REC_CORE_PROFILE_FUNCTION();
        static Renderer2D renderer2d;
        renderer2d.object_treshold = object_treshold;
        renderer2d.set_shader_program(&shader);
        shader.bind();
        return renderer2d;
    }
    // set up your scene
    Renderer &Renderer2D::begin_render(core::scene::Camera &camera)
    {
        REC_CORE_PROFILE_FUNCTION();
        this->camera = &camera;
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer2D::submit(core::scene::GameObject &drawable_item)
    {
        REC_CORE_PROFILE_FUNCTION();
        if (OPT_LIKELY(drawable_item.is_transparent()))
        {
            float distance_from_camera = glm::distance(this->camera->get_position(), drawable_item.translation());
            transparent[distance_from_camera] = &drawable_item;
        }
        else
        {
            opaque.push_back(&drawable_item);
        }

        if (OPT_UNLIKELY(++submitted_objects > object_treshold))
        {
            render();
            submitted_objects = 0;
        }
        return *this;
    }

    Renderer &Renderer2D::render()
    {
        // DRAW OPAQUE
        for (core::scene::GameObject *iter : opaque)
        {
            iter->bind();
            iter->draw(*_shader);
        }

        // DRAW TRANSPARENT
        for (const auto &entry : transparent)
        {
            // float transparency = entry.first;
            core::scene::GameObject *drawable = entry.second;

            drawable->bind();
            drawable->draw(*_shader);
        }

        opaque.clear();
        transparent.clear();

        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer2D::end_render()
    {
        REC_CORE_PROFILE_FUNCTION();
    }

    ////////// RENDERER 3D //////////
    const Renderer3D &Renderer3D::init(Shader &shader,uint32_t object_treshold)
    {
        static Renderer3D renderer3d;
        renderer3d.object_treshold = object_treshold;
        renderer3d.set_shader_program(&shader);
        return renderer3d;
    }
    // set up your scene
    Renderer &Renderer3D::begin_render(core::scene::Camera &camera)
    {
        REC_CORE_PROFILE_FUNCTION();
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer3D::submit(core::scene::GameObject &drawable_item)
    {
        REC_CORE_PROFILE_FUNCTION();
        return *this;
    }

    Renderer &Renderer3D::render()
    {
        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer3D::end_render()
    {
        REC_CORE_PROFILE_FUNCTION();
    }

}