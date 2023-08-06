#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_VBO_HH

#include <buffer.hh>
#include <GL/glew.h>

namespace Recursion::opengl::render
{
    class VertexBuffer : public core::render::Buffer
    {
    public:
        VertexBuffer(float *data, unsigned int size_in_bytes);
        virtual ~VertexBuffer();

        virtual void bind() override;
        virtual void unbind() override;

    protected:
        unsigned int VBO;
    };

} // namespace Recursion::core::render

#endif