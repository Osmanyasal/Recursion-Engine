#include <opengl_vertex_buffer.hh>
namespace Recursion::platforms::opengl::render
{
    VertexBuffer::VertexBuffer(uint32_t size_in_bytes, uint32_t draw_method) : vertex_count{(int32_t)((float)size_in_bytes / sizeof(float))}, offset{0}
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size_in_bytes, nullptr, draw_method); // create an empty buffer, will be filled later.
    }

    VertexBuffer::VertexBuffer(float *data, uint32_t size_in_bytes, uint32_t draw_method) : vertex_count{(int32_t)((float)size_in_bytes / sizeof(float))}, offset{0}
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

    VertexBuffer &VertexBuffer::add_positions(float *data, uint32_t size_in_bytes)
    {
        glBufferSubData(GL_ARRAY_BUFFER, offset, size_in_bytes, data);
        REC_CORE_TRACE("glBufferSubData(GL_ARRAY_BUFFER, {}, {}, data);", offset, size_in_bytes);
        offset += size_in_bytes;
        return *this;
    }
    VertexBuffer &VertexBuffer::add_colors(float *data, uint32_t size_in_bytes)
    {
        glBufferSubData(GL_ARRAY_BUFFER, offset, size_in_bytes, data);
        REC_CORE_TRACE("glBufferSubData(GL_ARRAY_BUFFER, {}, {}, data);", offset, size_in_bytes);
        offset += size_in_bytes;
        return *this;
    }
    VertexBuffer &VertexBuffer::add_normals(float *data, uint32_t size_in_bytes)
    {
        glBufferSubData(GL_ARRAY_BUFFER, offset, size_in_bytes, data);
        REC_CORE_TRACE("glBufferSubData(GL_ARRAY_BUFFER, {}, {}, data);", offset, size_in_bytes);
        offset += size_in_bytes;
        return *this;
    }
    VertexBuffer &VertexBuffer::add_texture_coordinates(float *data, uint32_t size_in_bytes)
    {
        glBufferSubData(GL_ARRAY_BUFFER, offset, size_in_bytes, data);
        REC_CORE_TRACE("glBufferSubData(GL_ARRAY_BUFFER, {}, {}, data);", offset, size_in_bytes);
        offset += size_in_bytes;
        return *this;
    }

} // namespace renders
