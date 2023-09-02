#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH

#include <buffer.hh>
#include <GL/glew.h>
#include <logger.hh>

namespace Recursion::opengl::render
{
    class VertexBuffer : public core::render::Buffer
    {
    public:
        VertexBuffer() // empty caller.
        {
            VBO = 0;
            vertex_count = 0;
        }
        VertexBuffer(uint32_t size_in_bytes, uint32_t draw_method = GL_STATIC_DRAW);
        VertexBuffer(float *data, uint32_t size_in_bytes, uint32_t draw_method = GL_STATIC_DRAW);
        virtual ~VertexBuffer();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;

        VertexBuffer &add_positions(float *data, uint32_t size_in_bytes);
        VertexBuffer &add_normals(float *data, uint32_t size_in_bytes);
        VertexBuffer &add_colors(float *data, uint32_t size_in_bytes);
        VertexBuffer &add_texture_coordinates(float *data, uint32_t size_in_bytes);

        uint32_t VBO;
        uint32_t vertex_count;

    private:
        uint32_t offset;
    };

} // namespace Recursion::core::render

#endif
