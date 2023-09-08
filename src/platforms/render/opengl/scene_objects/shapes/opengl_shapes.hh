#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__SHAPES_HH

#include <memory>
#include <square.hh>
#include <opengl_vertex_array.hh>

namespace Recursion::opengl::scene
{
    class OpenGLShapes
    {
    public:
        static std::unique_ptr<opengl::render::VertexArray> rectangle2D(const glm::vec3 &size, float color = 1, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> triangle2D(const glm::vec3 &size, float color = 1, float tile_factor = 1);
        static std::unique_ptr<opengl::render::VertexArray> circle2D(const glm::vec3 &size, float color = 1, float tile_factor = 1);

    private:
        OpenGLShapes();
        ~OpenGLShapes();
    };
} // namespace Recursion::opengl::scene

#endif