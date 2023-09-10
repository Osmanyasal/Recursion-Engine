#include <opengl_shapes.hh>

namespace Recursion::platforms::opengl::scene
{
    std::unique_ptr<opengl::render::VertexArray> OpenGLShapes::tilemap2D(const glm::vec3 &size, float color, float tile_factor)
    {
        return OpenGLShapes::rectangle2D(size, "../src/core/scene_objects/tile_maps/brick.png", color, tile_factor);
    }

    std::unique_ptr<opengl::render::VertexArray> OpenGLShapes::rectangle2D(const glm::vec3 &size, const std::string &texture, float color, float tile_factor)
    {
        std::unique_ptr<opengl::render::VertexArray> result;
        auto indices = core::scene::Rectangle2D::get_index_buffer();
        auto position = core::scene::Rectangle2D::get_positions(size);
        auto colors = core::scene::Rectangle2D::get_colors(color);
        auto normals = core::scene::Rectangle2D::get_normals();
        auto texture_position = core::scene::Rectangle2D::get_texture_coordinates(tile_factor);

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
                         render::Quantity::Float3, position.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3, colors.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"texture",
                         2,
                         render::Quantity::Float2, texture.size() / (int)render::Quantity::Float2,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"normals",
                         3,
                         render::Quantity::Float3, normals.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE});
        if (OPT_LIKELY(texture.size() != 0))
            VAO->add_texture({texture, tile_factor, false, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST});
        VAO->build_batch();

        result.reset(VAO);
        return result;
    }

    std::unique_ptr<opengl::render::VertexArray> OpenGLShapes::triangle2D(const glm::vec3 &size, const std::string &texture, float color, float tile_factor)
    {
        std::unique_ptr<opengl::render::VertexArray> result;
        auto indices = core::scene::Triangle2D::get_index_buffer();
        auto position = core::scene::Triangle2D::get_positions(size);
        auto colors = core::scene::Triangle2D::get_colors(color);
        auto normals = core::scene::Triangle2D::get_normals();
        auto texture_position = core::scene::Triangle2D::get_texture_coordinates(tile_factor);

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
                         render::Quantity::Float3, position.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3, colors.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"texture",
                         2,
                         render::Quantity::Float2, texture.size() / (int)render::Quantity::Float2,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"normals",
                         3,
                         render::Quantity::Float3, normals.size() / (int)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE});
        if (OPT_LIKELY(texture.size() != 0))
            VAO->add_texture({texture, tile_factor, false, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST});
        VAO->build_batch();

        result.reset(VAO);
        return result;
    }

    std::unique_ptr<opengl::render::VertexArray> OpenGLShapes::circle2D(float radius, float z, const std::string &texture, float unit_angle, float color, float tile_factor)
    {
        std::unique_ptr<opengl::render::VertexArray> result;
        auto indices = core::scene::Circle2D::get_index_buffer(unit_angle);
        auto position = core::scene::Circle2D::get_positions(radius, z, unit_angle);
        auto colors = core::scene::Circle2D::get_colors(color, unit_angle);
        auto normals = core::scene::Circle2D::get_normals(unit_angle);
        auto texture_position = core::scene::Circle2D::get_texture_coordinates(tile_factor, unit_angle);

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
                         render::Quantity::Float3, position.size() / (uint32_t)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3, colors.size() / (uint32_t)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"texture",
                         2,
                         render::Quantity::Float2, texture.size() / (uint32_t)render::Quantity::Float2,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"normals",
                         3,
                         render::Quantity::Float3, normals.size() / (uint32_t)render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE});
        if (OPT_LIKELY(texture.size() != 0))
            VAO->add_texture({texture, tile_factor, false, GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST});
        VAO->build_batch();

        result.reset(VAO);
        return result;
    }

} // namespace Recursion::opengl::scene
