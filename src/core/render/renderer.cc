#include <renderer.hh>
namespace Recursion::core::render
{

    ////////// RENDERER //////////
    void Renderer::set_shader_program(Shader *shader){
        _shader.reset((Shader*)shader);
    }

    ////////// RENDERER 2D //////////
    const Renderer2D &Renderer2D::init(Shader &shader)
    {
        static Renderer2D renderer2d;
        renderer2d.set_shader_program(&shader);
        shader.bind();
        return renderer2d;
    }
    // set up your scene
    Renderer &Renderer2D::begin_scene(core::scene::Camera &camera)
    {
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer2D::submit(Drawable &drawable_item)
    {   
        drawable_item.bind();
        drawable_item.draw(*_shader);
        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer2D::end_scene() {}

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
        return *this;
    }

    // submit items to your scene
    Renderer &Renderer3D::submit(Drawable &drawable_item)
    {
        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer3D::end_scene() {}

}