
#include <opengl_texture.hh>

namespace Recursion::platforms::opengl::render
{
    uint32_t OpenGLTexture::TEXTURE_UNIT_LIMIT = []()
    {
        return (uint32_t)(GL_ACTIVE_TEXTURE - GL_TEXTURE0);
    }(); // Immediately invoked lambda to set the limit

    uint32_t OpenGLTexture::AVAILABLE_TEXTURE_UNIT = 0;

    OpenGLTexture::OpenGLTexture(const std::string &path, float tile_factor, bool is_transparent, uint32_t wrap_s,
                                 uint32_t wrap_t,
                                 uint32_t min_filter,
                                 uint32_t mag_filter) : Texture{path}, is_transparent{is_transparent}, tile_factor{tile_factor}
    {
        REC_CORE_PROFILE_FUNCTION();

        REC_CORE_TRACE("Texture {} is being initialized", meta.path);
        texture_unit = AVAILABLE_TEXTURE_UNIT;
        if (OPT_UNLIKELY(AVAILABLE_TEXTURE_UNIT == TEXTURE_UNIT_LIMIT))
        {
            REC_CORE_WARN("All texture slots are occupied, returning texture 0 as next location");
            AVAILABLE_TEXTURE_UNIT = -1;
        }
        AVAILABLE_TEXTURE_UNIT += 1;

        glGenTextures(1, &meta.texture_id);
        glBindTexture(GL_TEXTURE_2D, meta.texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

        stbi_set_flip_vertically_on_load(true);
        uint8_t *data = stbi_load(meta.path.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            if (nrChannels == 4)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            }
            else if (nrChannels == 3)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            }
            else
            {
                REC_CORE_ERROR("Unknown format image {}", meta.path);
                exit(-1);
            }
            glGenerateMipmap(GL_TEXTURE_2D);
            REC_CORE_TRACE("Texture {} is initialized", meta.path);
        }
        else
        {
            REC_CORE_ERROR("Failed to load texture {}", meta.path);
        }
        stbi_image_free(data);
    }

    OpenGLTexture::OpenGLTexture(uint32_t width, uint32_t height, bool is_transparent, uint32_t value, uint32_t wrap_s,
                                 uint32_t wrap_t,
                                 uint32_t min_filter,
                                 uint32_t mag_filter) : Texture{""}, is_transparent{is_transparent}
    {
        REC_CORE_PROFILE_FUNCTION();

        texture_unit = AVAILABLE_TEXTURE_UNIT;
        if (OPT_UNLIKELY(AVAILABLE_TEXTURE_UNIT == TEXTURE_UNIT_LIMIT))
        {
            REC_CORE_WARN("All texture slots are occupied, returning texture 0 as next location");
            AVAILABLE_TEXTURE_UNIT = -1;
        }
        AVAILABLE_TEXTURE_UNIT += 1;

        glGenTextures(1, &meta.texture_id);
        glBindTexture(GL_TEXTURE_2D, meta.texture_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);

        uint32_t *data = new uint32_t[width * height];
        for (uint32_t i = 0; i < height * width; i++)
        {
            data[i] = value;
        }
        // Allocate storage for the texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
        delete[] data;
    }

    OpenGLTexture::~OpenGLTexture()
    {
    }

    void OpenGLTexture::bind()
    {
        REC_CORE_PROFILE_FUNCTION();

        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(GL_TEXTURE_2D, meta.texture_id);
    }

    void OpenGLTexture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void OpenGLTexture::destroy()
    {
        glDeleteTextures(1, &meta.texture_id);
        REC_CORE_TRACE("Texture {} is destroyed", meta.path);
    }

} // namespace Recursion::opengl::core
