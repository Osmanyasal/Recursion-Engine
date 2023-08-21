#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_TEXTURE_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_TEXTURE_HH

#include <utils.hh>
#include <texture.hh>
#include <GL/glew.h>
#include <stb_image.h>

namespace Recursion::opengl::render
{
    class OpenGLTexture : public core::render::Texture
    {
    public:
        OpenGLTexture(const std::string &path, uint32_t wrap_s = GL_REPEAT,
                      uint32_t wrap_t = GL_REPEAT,
                      uint32_t min_filter = GL_LINEAR_MIPMAP_LINEAR,
                      uint32_t mag_filter = GL_LINEAR);
        virtual ~OpenGLTexture();

        void bind() override;
        void unbind() override;
        void destroy() override;
    
    protected:
        int width;
        int height;
        int nrChannels;

    private:
        static uint32_t TEXTURE_UNIT_LIMIT;
        static uint32_t AVAILABLE_TEXTURE_UNIT;
        uint32_t texture_unit;        
    };

} // namespace Recursion::opengl::render

#endif
