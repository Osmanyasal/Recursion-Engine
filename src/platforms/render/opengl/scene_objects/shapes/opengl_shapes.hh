#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH

#include <memory>
#include <core_shapes.hh>
#include <opengl_vertex_array.hh>

namespace Recursion::platforms::opengl::scene
{
    struct SubTexture
    {
        SubTexture() : is_active{false}
        {
        }
        SubTexture(uint32_t subtext_size, uint32_t x, uint32_t y) : is_active{true}, subtext_size{subtext_size}, x{x}, y{y}
        {
        }
        bool is_active;
        uint32_t subtext_size;
        uint32_t x;
        uint32_t y;
    };

    // TODO: get texture parameter as a texture? maybe not idk
    class OpenGLShapes
    {
    public:
        static std::unique_ptr<opengl::render::VertexArray> tilemap2D(const glm::vec3 &size, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> rectangle2D(const glm::vec3 &size, const std::string &texture = "", const SubTexture &subtexture = SubTexture{}, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> triangle2D(const glm::vec3 &size, const std::string &texture = "", const SubTexture &subtexture = SubTexture{}, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> circle2D(float radius, float z = 0.0f, const std::string &texture = "", float unit_angle = 1.0f, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1.0f);

    private:
        OpenGLShapes();
        ~OpenGLShapes();
    };
} // namespace Recursion::opengl::scene

#endif