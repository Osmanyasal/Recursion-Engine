#include <opengl_vertex_array.hh>

#include <logger.hh>
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
        REC_TRACE("Layout added stride:{}", stride);
        return *this;
    }

    void VertexArray::build()
    {
        // calculate offset and stride
        unsigned int offset = 0;
        for (auto &layout : buffer_layouts)
        {
            glVertexAttribPointer(layout.buffer_info.attrib_array,
                                  (int)layout.buffer_info.quantity,
                                  (int)layout.buffer_info.type,
                                  (int)layout.buffer_info.normalized,
                                  stride,
                                  reinterpret_cast<const void *>(offset));

            glEnableVertexAttribArray(layout.buffer_info.attrib_array);
            REC_TRACE("glVertexAttribPointer({},{},{},{},{},{})", layout.buffer_info.attrib_array,
                      (int)layout.buffer_info.quantity,
                      (int)layout.buffer_info.type,
                      (int)layout.buffer_info.normalized,
                      stride,
                      reinterpret_cast<const void *>(offset));

            offset += (((int)layout.buffer_info.quantity) * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        }

        // add index buffer if it doesn't exists
        // by default add all vertices 0 to N.
        if (this->IBO.IBO == 0)
        {
            REC_TRACE("THERE'S NO INDEX BUFFER ASSIGNED !!!!\n");
            unsigned int index_size = VBO.vertex_count;
            unsigned int arr[index_size];
            for (unsigned int i = 0; i < index_size; i++)
                arr[i] = i;

            bind_index_buffer({arr, (unsigned int)(sizeof(unsigned int) * index_size)});
        }
    }

    void VertexArray::draw()
    {
        glDrawElements(GL_TRIANGLES, this->VBO.vertex_count, GL_UNSIGNED_INT, 0);
    }

} // namespace Recursion::core::render