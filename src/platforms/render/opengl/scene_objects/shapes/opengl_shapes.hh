#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH

#include <memory>
#include <core_shapes.hh>
#include <opengl_vertex_array.hh>

namespace Recursion::platforms::opengl::scene
{
    class OpenGLShapes
    {
    public:
        static std::unique_ptr<opengl::render::VertexArray> tilemap2D(const glm::vec3 &size, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> rectangle2D(const glm::vec3 &size, const std::string &texture = "", const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> triangle2D(const glm::vec3 &size, const std::string &texture = "", const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> circle2D(float radius, float z = 0.0f, const std::string &texture = "", float unit_angle = 1.0f, const glm::vec4 &color = glm::vec4{1.0f}, float tile_factor = 1.0f);

    private:
        OpenGLShapes();
        ~OpenGLShapes();
    };
} // namespace Recursion::opengl::scene

#endif