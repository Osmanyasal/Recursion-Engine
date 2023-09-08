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
        OpenGLTexture(const std::string &path, float tile_factor = 1, bool is_transparent = false, uint32_t wrap_s = GL_REPEAT,
                      uint32_t wrap_t = GL_REPEAT,
                      uint32_t min_filter = GL_LINEAR_MIPMAP_LINEAR,
                      uint32_t mag_filter = GL_LINEAR);

        OpenGLTexture(uint32_t width = 1, bool is_transparent = false, uint32_t height = 1, uint32_t value = 0xFFFFFF, uint32_t wrap_s = GL_REPEAT,
                      uint32_t wrap_t = GL_REPEAT,
                      uint32_t min_filter = GL_LINEAR_MIPMAP_LINEAR,
                      uint32_t mag_filter = GL_LINEAR);

        virtual ~OpenGLTexture();

        void bind() override;
        void unbind() override;
        void destroy() override;

        inline uint32_t get_unit() { return texture_unit; }

    public:
        static uint32_t TEXTURE_UNIT_LIMIT;
        static uint32_t AVAILABLE_TEXTURE_UNIT;
        bool is_transparent;
        float tile_factor;

    protected:
        int32_t width;
        int32_t height;
        int32_t nrChannels;

    private:
        uint32_t texture_unit;
    };

} // namespace Recursion::opengl::render

#endif
