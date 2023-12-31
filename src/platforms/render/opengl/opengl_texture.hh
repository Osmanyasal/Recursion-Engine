#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_TEXTURE_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_TEXTURE_HH

#include <utils.hh>
#include <GL/glew.h>
#include <texture.hh>
#include <stb_image.h>
#include <unordered_map>

namespace Recursion::platforms::opengl::render
{
    class OpenGLTexture : public core::render::Texture
    {
    public:
        /**
         * @brief Construct a new OpenGL Texture object from path
         *
         * @param path
         * @param tile_factor
         * @param is_transparent
         * @param wrap_s
         * @param wrap_t
         * @param min_filter
         * @param mag_filter
         */
        OpenGLTexture(const std::string &path, float tile_factor = 1, bool is_transparent = false, uint32_t wrap_s = GL_REPEAT,
                      uint32_t wrap_t = GL_REPEAT,
                      uint32_t min_filter = GL_LINEAR_MIPMAP_LINEAR,
                      uint32_t mag_filter = GL_LINEAR);

        /**
         * @brief Construct a new OpenGL Texture to be filled with a data later (used for non-texture elements and framebuffers.)
         *
         * @param path
         * @param tile_factor
         * @param is_transparent
         * @param wrap_s
         * @param wrap_t
         * @param min_filter
         * @param mag_filter
         */
        OpenGLTexture(uint32_t width, uint32_t height, const std::string &tag, bool is_transparent = false, uint32_t value = 0xFFFFFF, uint32_t wrap_s = GL_REPEAT,
                      uint32_t wrap_t = GL_REPEAT,
                      uint32_t min_filter = GL_LINEAR_MIPMAP_LINEAR,
                      uint32_t mag_filter = GL_LINEAR);

        virtual ~OpenGLTexture();

        void bind() override;
        void unbind() override;
        void destroy() override;

    public:
        static uint32_t TEXTURE_UNIT_LIMIT;
        static uint32_t AVAILABLE_TEXTURE_UNIT;
    };

} // namespace Recursion::opengl::render

#endif
