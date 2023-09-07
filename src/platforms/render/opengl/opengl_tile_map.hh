#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__TILE_MAP_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__TILE_MAP_HH

#include <string>
#include <layer.hh>
#include <opengl_vertex_array.hh>
#include <event_core.hh>

namespace Recursion::opengl::render
{
    class TileMap : public Recursion::core::layer::Layer
    {
    public:
        TileMap(core::render::Shader &shader,
                const std::string &path = "/home/rt7/Desktop/Recursion-Engine/src/core/scene_objects/tile_maps/square.png") : shader{shader}
        {
            float data[4 * 3]{
                0.5f, 0.5f, 0.0f,   // Top right
                0.5f, -0.5f, 0.0f,  // Bottom right
                -0.5f, -0.5f, 0.0f, // Bottom left
                -0.5f, 0.5f, 0.0f   // Top left
            };

            uint32_t indices[] = {
                0, 1, 3, // First triangle
                1, 2, 3  // Second triangle
            };

            VAO.bind();
            VAO.bind_vertex_buffer({data, sizeof(float) * 4 * 3})
                .add_layout({"position",
                             0,
                             render::Quantity::Float3, 1,
                             render::Type::Float,
                             render::Normalized::FALSE})
                .add_texture({path, 5})
                .bind_index_buffer({indices, sizeof(uint32_t) * 3 * 2})
                .build();
        }
        virtual ~TileMap() { VAO.destroy(); }
        virtual void on_attach() override
        {
            VAO.bind();
        };
        virtual void on_detach() override
        {
            VAO.unbind();
        }
        virtual void on_update(float delta_time) override
        {
            VAO.bind();
            VAO.draw(shader);
        };
        virtual void on_event(Recursion::core::events::Event &event) override{};

    protected:
        core::render::Shader &shader;
        render::VertexArray VAO;
    };
}
#endif