
#include <opengl_texture.hh>

namespace Recursion::opengl::render
{
    uint32_t OpenGLTexture::TEXTURE_UNIT_LIMIT = []()
    {
        return (uint32_t)(GL_ACTIVE_TEXTURE - GL_TEXTURE0);
    }(); // Immediately invoked lambda to set the limit

    uint32_t OpenGLTexture::AVAILABLE_TEXTURE_UNIT = 0;

    OpenGLTexture::OpenGLTexture(const std::string &path, uint32_t tile_factor, uint32_t wrap_s,
                                 uint32_t wrap_t,
                                 uint32_t min_filter,
                                 uint32_t mag_filter) : Texture{path}, tile_factor{tile_factor}
    {
        REC_CORE_PROFILE_FUNCTION();

        REC_CORE_TRACE("Texture {} is being initialized", get_path());
        texture_unit = AVAILABLE_TEXTURE_UNIT;
        if (OPT_UNLIKELY(AVAILABLE_TEXTURE_UNIT == TEXTURE_UNIT_LIMIT))
        {
            REC_CORE_WARN("All texture slots are occupied, returning texture 0 as next location");
            AVAILABLE_TEXTURE_UNIT = -1;
        }
        AVAILABLE_TEXTURE_UNIT += 1;

        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

        stbi_set_flip_vertically_on_load(true);
        uint8_t *data = stbi_load(get_path().c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            REC_CORE_TRACE("Texture {} is initialized", get_path());
        }
        else
        {
            REC_CORE_ERROR("Failed to load texture {}", get_path());
        }
        stbi_image_free(data);
    }

    OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height, uint32_t value, uint32_t wrap_s,
                                 uint32_t wrap_t,
                                 uint32_t min_filter,
                                 uint32_t mag_filter) : Texture{""}
    {
        REC_CORE_PROFILE_FUNCTION();

        texture_unit = AVAILABLE_TEXTURE_UNIT;
        if (OPT_UNLIKELY(AVAILABLE_TEXTURE_UNIT == TEXTURE_UNIT_LIMIT))
        {
            REC_CORE_WARN("All texture slots are occupied, returning texture 0 as next location");
            AVAILABLE_TEXTURE_UNIT = -1;
        }
        AVAILABLE_TEXTURE_UNIT += 1;

        glGenTextures(1, &texture_id);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

        uint32_t data[width][height];
        for (uint32_t i = 0; i < width; i++)
            for (uint32_t j = 0; j < height; j++)
            {
                data[i][j] = value;
            }

        // Allocate storage for the texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);
    }

    OpenGLTexture::~OpenGLTexture()
    {
    }

    void OpenGLTexture::bind()
    {
        REC_CORE_PROFILE_FUNCTION();

        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(GL_TEXTURE_2D, texture_id);
    }

    void OpenGLTexture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void OpenGLTexture::destroy()
    {
        glDeleteTextures(1, &texture_id);
        REC_CORE_TRACE("Texture {} is destroyed", get_path());
    }

} // namespace Recursion::opengl::core