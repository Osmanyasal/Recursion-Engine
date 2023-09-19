
#include <opengl_index_buffer.hh>

namespace Recursion::platforms::opengl::render
{
    IndexBuffer::IndexBuffer(){
        IBO = 0;
    }
    IndexBuffer::IndexBuffer(const uint32_t *data, uint32_t size_in_bytes, uint32_t draw_method)
    {
        glGenBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_in_bytes, data, draw_method);

        REC_CORE_TRACE("IndexBuffer Created {} in bytes {} draw methods",size_in_bytes,draw_method);
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
