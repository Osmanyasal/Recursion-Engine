#include <opengl_shapes.hh>

namespace Recursion::opengl::scene
{
    std::unique_ptr<opengl::render::VertexArray> OpenGLShapes::rectangle2D(float x, float y, float z, float color, float tile_factor)
    {
        std::unique_ptr<opengl::render::VertexArray> result;
        auto indices = core_scene::Rectangle2D::get_index_buffer();
        auto position = core_scene::Rectangle2D::get_positions(x, y, z);
        auto colors = core_scene::Rectangle2D::get_colors(color);
        auto normals = core_scene::Rectangle2D::get_normals();
        auto texture_position = core_scene::Rectangle2D::get_texture_coordinates(tile_factor);

        render::VertexBuffer VBO{sizeof(float) * position.size() + sizeof(float) * colors.size() + sizeof(float) * normals.size() + sizeof(float) * texture_position.size()};
        VBO.add_positions(position.data(), position.size() * sizeof(float));
        VBO.add_colors(colors.data(), colors.size() * sizeof(float));
        VBO.add_texture_coordinates(texture_position.data(), texture_position.size() * sizeof(float));
        VBO.add_normals(normals.data(), normals.size() * sizeof(float));

        render::VertexArray *VAO = new render::VertexArray;
        VAO->bind_index_buffer({indices.data(), indices.size() * sizeof(uint32_t)});
        VAO->bind_vertex_buffer(VBO)
            .add_layout({"position",
                         0,
                         render::Quantity::Float3, 4,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3, 4,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"texture",
                         2,
                         render::Quantity::Float2, 4,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"normals",
                         3,
                         render::Quantity::Float3, 4,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_texture({"/home/rt7/Desktop/Recursion-Engine/src/core/scene_objects/tile_maps/brick.png", tile_factor, false, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST})
            .build_batch();

        result.reset(VAO);
        return result;
    }

} // namespace Recursion::opengl::scene
