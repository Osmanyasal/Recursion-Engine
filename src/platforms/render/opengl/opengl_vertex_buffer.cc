#include <opengl_vertex_buffer.hh>
namespace Recursion::opengl::render
{
    VertexBuffer::VertexBuffer()
    {
        VBO = 0;
        vertex_count = 0;
    }

    VertexBuffer::VertexBuffer(float *data, uint32_t size_in_bytes, uint32_t draw_method): vertex_count{size_in_bytes / sizeof(float)}
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size_in_bytes, data, draw_method);
        REC_TRACE("vertex buffer created writh {} in bytes, {} draw method", size_in_bytes, draw_method);
    }

    VertexBuffer::~VertexBuffer()
    {
    }

    void VertexBuffer::destroy()
    {
        glDeleteBuffers(1, &VBO);
    }

    void VertexBuffer::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
    }

    void VertexBuffer::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // namespace renders
