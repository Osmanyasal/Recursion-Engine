#include <opengl_vertex_array.hh>

#include <iostream>
namespace Recursion::opengl::render
{

    VertexArray::VertexArray() : stride{0}
    {
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
    }

    VertexArray::~VertexArray()
    {
        VBO.destroy();
        IBO.destroy();
        destroy();
    }
    void VertexArray::bind()
    {
        glBindVertexArray(VAO);
    }
    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }
    void VertexArray::destroy()
    {
        glDeleteVertexArrays(1, &VAO);
    }
    VertexArray &VertexArray::bind_vertex_buffer(const VertexBuffer &VBO)
    {
        this->VBO = VBO; // copy or move assign
        return *this;
    }
    VertexArray &VertexArray::bind_index_buffer(const IndexBuffer &IBO)
    {
        this->IBO = IBO; // copy or move assign
        return *this;
    }

    VertexArray &VertexArray::add_layout(const OpenGLBufferLayout &layout)
    {
        stride += ((int)layout.buffer_info.quantity * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        buffer_layouts.push_back(layout);
        return *this;
    }

    void VertexArray::build()
    {
        // calculate offset and stride

        unsigned int offset = 0;
        for (auto &layout : buffer_layouts)
        {
            glEnableVertexAttribArray(layout.buffer_info.attrib_array);
            glVertexAttribPointer(layout.buffer_info.attrib_array,
                                  (int)layout.buffer_info.quantity,
                                  (int)layout.buffer_info.type,
                                  (bool)layout.buffer_info.normalized,
                                  stride,
                                  (void *)offset);

            offset += (((int)layout.buffer_info.quantity) * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        }
    }

} // namespace Recursion::core::render
