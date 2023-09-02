#include <renderer.hh>
namespace Recursion::core::render
{

    ////////// RENDERER //////////
    void Renderer::set_shader_program(Shader *shader)
    {
        _shader.reset((Shader *)shader);
    }

    ////////// RENDERER 2D //////////
    const Renderer2D &Renderer2D::init(Shader &shader)
    {
        REC_CORE_PROFILE_FUNCTION();
        static Renderer2D renderer2d;
        renderer2d.set_shader_program(&shader);
        shader.bind();
        return renderer2d;
    }
    // set up your scene
    Renderer &Renderer2D::begin_scene(core::scene::Camera &camera)
    {
        REC_CORE_PROFILE_FUNCTION();
        this->camera = &camera;
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer2D::submit(Drawable &drawable_item)
    {
        REC_CORE_PROFILE_FUNCTION();
        if (OPT_LIKELY(drawable_item.is_transparent()))
        {
            /*TODO: implement transparent drawing according to
                Draw all opaque objects first.
                Sort all the transparent objects.
                Draw all the transparent objects in sorted order.
            */
           
        }
        else
        {
            opaque.push_back(&drawable_item);
        }
        return *this;
    }

    Renderer &Renderer2D::draw_scene()
    {

        // DRAW OPAQUE
        for (Drawable *iter : opaque)
        {
            iter->bind();
            iter->draw(*_shader);
        }

        // DRAW TRANSPARENT
        for (const auto &entry : transparent)
        {
            float transparency = entry.first;
            Drawable *drawable = entry.second;

            drawable->bind();
            drawable->draw(*_shader);
        }

        opaque.clear();
        transparent.clear();

        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer2D::end_scene()
    {
        REC_CORE_PROFILE_FUNCTION();
    }

    ////////// RENDERER 3D //////////
    const Renderer3D &Renderer3D::init(Shader &shader)
    {
        static Renderer3D renderer3d;
        renderer3d.set_shader_program(&shader);
        return renderer3d;
    }
    // set up your scene
    Renderer &Renderer3D::begin_scene(core::scene::Camera &camera)
    {
        REC_CORE_PROFILE_FUNCTION();
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer3D::submit(Drawable &drawable_item)
    {
        REC_CORE_PROFILE_FUNCTION();
        return *this;
    }

    Renderer &Renderer3D::draw_scene()
    {
        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer3D::end_scene()
    {
        REC_CORE_PROFILE_FUNCTION();
    }

}