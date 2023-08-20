#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH

namespace Recursion::core::render
{
    class Renderer
    {
    public:
        inline Renderer() {}
        inline virtual ~Renderer() {}

        // set up your scene
        virtual void begin_scene() = 0; 

        // submit items to your scene
        virtual void submit() = 0;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() = 0;
    };

    class Renderer2D : public Renderer
    {
    public:
        inline Renderer2D() {}
        inline virtual ~Renderer2D() {}
    };

    class Renderer3D : public Renderer
    {
    public:
        inline Renderer3D() {}
        inline virtual ~Renderer3D() {}
    };

}

#endif