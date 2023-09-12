#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_FRAME_BUFFER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_FRAME_BUFFER_HH

#include <GL/glew.h>
#include <buffer.hh>
#include <opengl_texture.hh>
#include <shader.hh>
namespace Recursion::platforms::opengl::render
{
    class OpenGLFrameBuffer : core::render::Drawable
    {
    public:
        OpenGLFrameBuffer(float width, float height);
        OpenGLFrameBuffer(float width, float height, const OpenGLTexture &texture);
        ~OpenGLFrameBuffer();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;

        virtual void draw(core::render::Shader &shader) override;
        virtual bool is_transparent() { return false; }

        // and we rescale the buffer, so we're able to resize the window
        void rescale_framebuffer(float width, float height);

    public:
        const OpenGLTexture texture;
        uint32_t FBO;
        uint32_t RBO;
    };
}

#endif