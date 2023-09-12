#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_FRAME_BUFFER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_FRAME_BUFFER_HH

#include <GL/glew.h>
#include <buffer.hh>
#include <opengl_texture.hh>
namespace Recursion::platforms::opengl::render
{
    class OpenGLFrameBuffer : core::render::Buffer
    {
    public:
        OpenGLFrameBuffer(const OpenGLTexture &texture);
        ~OpenGLFrameBuffer();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;

    public:
        const OpenGLTexture &texture;
        uint32_t FBO;
    };
}

#endif