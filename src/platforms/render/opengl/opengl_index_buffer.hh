#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_IBO_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_IBO_HH

#include <buffer.hh>
#include <GL/glew.h>

namespace Recursion::opengl::render
{
    class IndexBuffer : public core::render::Buffer
    {
    public:
        IndexBuffer();
        IndexBuffer(const uint32_t *data, uint32_t size_in_bytes,uint32_t draw_method = GL_STATIC_DRAW);
        virtual ~IndexBuffer();

        virtual void bind() override;
        virtual void unbind() override; 
        virtual void destroy() override;

        uint32_t IBO;
    };

} // namespace Recursion::core::render

#endif