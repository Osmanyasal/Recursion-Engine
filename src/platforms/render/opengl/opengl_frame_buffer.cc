
#include <opengl_frame_buffer.hh>

namespace Recursion::platforms::opengl::render
{
    OpenGLFrameBuffer::OpenGLFrameBuffer(const OpenGLTexture &texture): texture{texture}
    {
    }

    OpenGLFrameBuffer::~OpenGLFrameBuffer()
    {
        glDeleteFramebuffers(1, &FBO);
    }

    void OpenGLFrameBuffer::bind()
    {
    }
    void OpenGLFrameBuffer::unbind()
    {
    }
    void OpenGLFrameBuffer::destroy()
    {
    }
}