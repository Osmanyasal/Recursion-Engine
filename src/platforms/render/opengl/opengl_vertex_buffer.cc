#include <opengl_vertex_buffer.hh>

namespace Recursion::opengl::render
{
    VertexBuffer::VertexBuffer()
    {
        VBO = 0;
    }
    
    VertexBuffer::VertexBuffer(float *data, unsigned int size_in_bytes, unsigned int draw_method) 
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size_in_bytes, data, draw_method);
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
