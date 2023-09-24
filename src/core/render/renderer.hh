#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERER_HH

#include <memory>
#include <map>

#include <utils.hh>
#include <camera.hh>
#include <shader.hh>
#include <game_object.hh>

// TODO: Remove this, make vertex-array and buffer objects generic!
namespace Recursion::core::render
{
    class Renderer
    {
    public:
        inline Renderer() : submitted_objects{0}, object_treshold{1} {}
        inline virtual ~Renderer() {}

        // set up your scene
        virtual Renderer &begin_scene(core::scene::Camera &) = 0;

        // submit items to your scene
        virtual Renderer &submit(core::scene::GameObject &) = 0;

        // draw scene
        /*  implement transparent drawing according to
            Draw all opaque objects first.
            Sort all the transparent objects.
            Draw all the transparent objects in sorted order.
        */
        virtual Renderer &draw_scene() = 0;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() = 0;

        void set_shader_program(Shader *shader);

    protected:
        uint16_t submitted_objects;
        uint32_t object_treshold;
        std::shared_ptr<Shader> _shader;
        core::scene::Camera *camera;
        std::vector<core::scene::GameObject *> opaque;
        std::map<float, core::scene::GameObject *> transparent;
    };

    class Renderer2D : public Renderer
    {
    public:
        inline Renderer2D(){}
        inline virtual ~Renderer2D() {}

        const static Renderer2D &init(Shader &shader,uint32_t object_treshold);

        // set up your scene
        virtual Renderer &begin_scene(core::scene::Camera &) override;

        // submit items to your scene
        virtual Renderer &submit(core::scene::GameObject &) override;

        // draw scene
        virtual Renderer &draw_scene() override;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() override;
    };

    class Renderer3D : public Renderer
    {
    public:
        inline Renderer3D() {}
        inline virtual ~Renderer3D() {}

        const static Renderer3D &init(Shader &shader,uint32_t object_treshold);

        // set up your scene
        virtual Renderer &begin_scene(core::scene::Camera &) override;

        // submit items to your scene
        virtual Renderer &submit(core::scene::GameObject &) override;

        // draw scene
        virtual Renderer &draw_scene() override;

        // wrap up the scene (remember all these are in a loop)
        virtual void end_scene() override;
    };

}

#endif