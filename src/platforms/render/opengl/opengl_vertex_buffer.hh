#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH

#include <buffer.hh>
#include <GL/glew.h>
#include <logger.hh>

namespace Recursion::opengl::render
{
    class VertexBuffer : public core::render::Buffer
    {
    public:
        VertexBuffer(); 
        VertexBuffer(float *data, unsigned int size_in_bytes, unsigned int draw_method = GL_STATIC_DRAW);
        virtual ~VertexBuffer();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;


        unsigned int VBO;
        unsigned int vertex_count;
    };

} // namespace Recursion::core::render

#endif