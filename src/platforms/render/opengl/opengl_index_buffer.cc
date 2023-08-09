#include <opengl_index_buffer.hh>

namespace Recursion::opengl::render
{
    IndexBuffer::IndexBuffer(){
        IBO = 0;
    }
    IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int size_in_bytes, unsigned int draw_method)
    {
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_in_bytes, data, draw_method);
    }

    IndexBuffer::~IndexBuffer()
    {
    }

    void IndexBuffer::destroy()
    {
        glDeleteBuffers(1, &IBO);
    }

    void IndexBuffer::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    }

    void IndexBuffer::unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // namespace renders
