#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VAO_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VAO_HH

#include <opengl_index_buffer.hh>
#include <opengl_vertex_buffer.hh>
#include <opengl_buffer_layout.hh>
#include <opengl_texture.hh>
#include <opengl_shader.hh>
#include <GL/glew.h>
#include <vector>

namespace Recursion::opengl::render
{
    class VertexArray : public core::render::Drawable
    {
    public:
        VertexArray();
        virtual ~VertexArray();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;

        virtual VertexArray &bind_vertex_buffer(const VertexBuffer &VBO);
        virtual VertexArray &bind_index_buffer(const IndexBuffer &IBO);
        virtual VertexArray &add_layout(const OpenGLBufferLayout &layout);
        virtual VertexArray &add_texture(const OpenGLTexture &texture);
        virtual void build();

        virtual void draw(core::render::Shader &shader) override;

    protected:
        uint32_t VAO;
        VertexBuffer VBO;
        IndexBuffer IBO;
        std::vector<OpenGLTexture> texture_list;
        std::vector<OpenGLBufferLayout> buffer_layouts;

    private:
        int32_t stride;
    };

} // namespace Recursion::core::render

#endif