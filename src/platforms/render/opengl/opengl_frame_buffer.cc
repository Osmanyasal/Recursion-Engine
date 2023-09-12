
#include <opengl_frame_buffer.hh>

namespace Recursion::platforms::opengl::render
{
    OpenGLFrameBuffer::OpenGLFrameBuffer(float width, float height) : OpenGLFrameBuffer{width, height, OpenGLTexture{}}
    {
    }

    OpenGLFrameBuffer::OpenGLFrameBuffer(float width, float height, const OpenGLTexture &texture) : texture{texture}
    {
        glGenFramebuffers(1, &FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.meta.texture_id, 0);

        glGenRenderbuffers(1, &RBO);
        glBindRenderbuffer(GL_RENDERBUFFER, RBO);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        {
            REC_CORE_ERROR("ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n");
            exit(-1);
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindRenderbuffer(GL_RENDERBUFFER, 0);

        REC_CORE_INFO("Framebuffer Created!\n");
    }

    void OpenGLFrameBuffer::rescale_framebuffer(float width, float height)
    {
        glBindTexture(GL_TEXTURE_2D, texture.meta.texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.meta.texture_id, 0);

        glBindRenderbuffer(GL_RENDERBUFFER, RBO);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);
    }

    OpenGLFrameBuffer::~OpenGLFrameBuffer()
    {
    }

    void OpenGLFrameBuffer::bind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    }
    void OpenGLFrameBuffer::draw(core::render::Shader &shader)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    }

    void OpenGLFrameBuffer::unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    void OpenGLFrameBuffer::destroy()
    {
        glDeleteFramebuffers(1, &FBO);
    }
}