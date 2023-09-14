#include <opengl_vertex_array.hh>

#include <logger.hh>
#include <iostream>
namespace Recursion::platforms::opengl::render
{

    VertexArray::VertexArray() : stride{0}, transparent{false}
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
        stride += ((int32_t)layout.buffer_info.quantity * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        buffer_layouts.push_back(layout);
        REC_CORE_TRACE("Layout added stride {}", stride);
        return *this;
    }

    VertexArray &VertexArray::add_texture(const OpenGLTexture &texture)
    {
        this->transparent = texture.meta.is_transparent;
        texture_list.push_back(texture);
        REC_CORE_TRACE("Texture added {}", texture.meta.path);
        return *this;
    }

    bool VertexArray::is_transparent()
    {
        return this->transparent;
    }

    void VertexArray::build()
    {
        if (OPT_UNLIKELY(texture_list.size() == 0))
        {
            OpenGLTexture blank_texture{1, 1, "blank_texture"};
            texture_list.push_back(blank_texture);
        }
        OpenGLTexture::AVAILABLE_TEXTURE_UNIT = 0; // reset texture_units for next VertexArray's textures.

        // calculate offset and stride
        uint32_t offset = 0;
        for (auto &layout : buffer_layouts)
        {
            glVertexAttribPointer(layout.buffer_info.attrib_array,
                                  (int32_t)layout.buffer_info.quantity,
                                  (int32_t)layout.buffer_info.type,
                                  (int32_t)layout.buffer_info.normalized,
                                  stride,
                                  reinterpret_cast<const void *>(offset));

            glEnableVertexAttribArray(layout.buffer_info.attrib_array);
            REC_CORE_TRACE("glVertexAttribPointer({},{},{},{},{},{})", layout.buffer_info.attrib_array,
                           (int32_t)layout.buffer_info.quantity,
                           (int32_t)layout.buffer_info.type,
                           (int32_t)layout.buffer_info.normalized,
                           stride,
                           reinterpret_cast<const void *>(offset));

            offset += (((int32_t)layout.buffer_info.quantity) * layout.buffer_info.repeat * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        }

        // add index buffer if it doesn't exists
        // by default add all vertices 0 to N.
        if (this->IBO.IBO == 0)
        {
            REC_CORE_TRACE("THERE'S NO INDEX BUFFER ASSIGNED !!!!\n");
            uint32_t index_size = VBO.vertex_count;
            uint32_t arr[index_size];
            for (uint32_t i = 0; i < index_size; i++)
                arr[i] = i;

            bind_index_buffer({arr, (uint32_t)(sizeof(uint32_t) * index_size)});
        }
    }

    void VertexArray::build_batch()
    {
        if (OPT_UNLIKELY(texture_list.size() == 0))
        {
            OpenGLTexture blank_texture{1, 1, "blank_texture"};
            texture_list.push_back(blank_texture);
        }
        OpenGLTexture::AVAILABLE_TEXTURE_UNIT = 0; // reset texture_units for next VertexArray's textures.

        // calculate offset and stride
        uint32_t offset = 0;
        for (auto &layout : buffer_layouts)
        {
            glVertexAttribPointer(layout.buffer_info.attrib_array,
                                  (int32_t)layout.buffer_info.quantity,
                                  (int32_t)layout.buffer_info.type,
                                  (int32_t)layout.buffer_info.normalized,
                                  (((int32_t)layout.buffer_info.quantity) * OpenGLBufferLayout::get_type_size(layout.buffer_info.type)),
                                  reinterpret_cast<const void *>(offset));

            glEnableVertexAttribArray(layout.buffer_info.attrib_array);
            REC_CORE_TRACE("glVertexAttribPointer({},{},{},{},{},{})", layout.buffer_info.attrib_array,
                           (int32_t)layout.buffer_info.quantity,
                           (int32_t)layout.buffer_info.type,
                           (int32_t)layout.buffer_info.normalized,
                           (((int32_t)layout.buffer_info.quantity) * OpenGLBufferLayout::get_type_size(layout.buffer_info.type)),
                           reinterpret_cast<const void *>(offset));

            offset += (((int32_t)layout.buffer_info.quantity) * layout.buffer_info.repeat * OpenGLBufferLayout::get_type_size(layout.buffer_info.type));
        }

        // add index buffer if it doesn't exists
        // by default add all vertices 0 to N.
        if (this->IBO.IBO == 0)
        {
            REC_CORE_TRACE("THERE'S NO INDEX BUFFER ASSIGNED !!!!\n");
            uint32_t index_size = VBO.vertex_count;
            uint32_t arr[index_size];
            for (uint32_t i = 0; i < index_size; i++)
                arr[i] = i;
            bind_index_buffer({arr, (uint32_t)(sizeof(uint32_t) * index_size)});
        }
    }

    void VertexArray::draw(core::render::Shader &shader)
    {
        for (auto iter = texture_list.begin(); iter != texture_list.end(); iter++)
        {
            // TODO:Add support for multiple textures and mixing.
            iter->bind();                                                  // bind the texture
            shader.set_uniform1i("u_ourTexture", iter->meta.texture_unit); // set texture unit.
        }
        glDrawElements(GL_TRIANGLES, this->VBO.vertex_count, GL_UNSIGNED_INT, 0);
        // glDisable(GL_TEXTURE_2D);
    }

} // namespace Recursion::core::render
