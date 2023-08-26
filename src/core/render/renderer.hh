#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH

#include <utils.hh>
#include <camera.hh>
#include <bindable.hh>
// TODO: Remove this, make vertex-array and buffer objects generic!
namespace Recursion::core::render
{
    class Renderer
    {
    public:
        inline Renderer() {}
        inline virtual ~Renderer() {}

        // set up your scene
        virtual Renderer& begin_scene(core::scene::Camera&) = 0;

        // submit items to your scene
        virtual Renderer& submit(const Bindable&) = 0;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() = 0;
    };

    class Renderer2D : public Renderer
    {
    public:
        inline Renderer2D() {}
        inline virtual ~Renderer2D() {}

        const static Renderer2D &Get();

        // set up your scene
        virtual Renderer& begin_scene(core::scene::Camera&) override;

        // submit items to your scene
        virtual Renderer& submit(const Bindable&) override;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() override; 
    };

    class Renderer3D : public Renderer
    {
    public:
        inline Renderer3D() {}
        inline virtual ~Renderer3D() {}

        const static Renderer3D &Get();

        // set up your scene
        virtual Renderer& begin_scene(core::scene::Camera&) override;

        // submit items to your scene
        virtual Renderer& submit(const Bindable&) override;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() override;
    };

}

#endif