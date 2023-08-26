#include <renderer.hh>
namespace Recursion::core::render
{
    ////////// RENDERER 2D //////////
    const Renderer2D &Renderer2D::Get()
    {
        static Renderer2D renderer2d;
        return renderer2d;
    }
    // set up your scene
    Renderer& Renderer2D::begin_scene(core::scene::Camera& camera) {
        return *this;
    }

    // submit items to your scene
    Renderer& Renderer2D::submit(const Bindable& vao) {
        return *this;
    }
 
    // wrap up the scene (remember all these are in a loop)
    void Renderer2D::end_scene() {}





    ////////// RENDERER 3D //////////
    const Renderer3D &Renderer3D::Get()
    {
        static Renderer3D renderer3d;
        return renderer3d;
    }
    // set up your scene
    Renderer& Renderer3D::begin_scene(core::scene::Camera& camera) {
        return *this;
    }

    // submit items to your scene
    Renderer& Renderer3D::submit(const Bindable&) {
        return *this;
    }

    // wrap up the scene (remember all these are in a loop)
    void Renderer3D::end_scene() {}

}