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
        static std::unique_ptr<opengl::render::VertexArray> rectangle2D(float x = 1, float y = 1, float z = 0, float color = 1, float tile_factor = 1);

    private:
        OpenGLShapes();
        ~OpenGLShapes();
    };
} // namespace Recursion::opengl::scene

#endif