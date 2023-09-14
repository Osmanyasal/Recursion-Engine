#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH

#include <string>
#include <sstream>
#include <bindable.hh>
#include <unordered_map>

namespace Recursion::core::render
{
    struct TextureMetaData
    {
        std::string path;
        uint32_t texture_id;
        uint32_t texture_unit;

        int32_t width;
        int32_t height;
        int32_t nrChannels;

        bool is_transparent;
        float tile_factor;

        std::string to_string()
        {
            std::stringstream res;
            res << "TextureMetaData("
                << "path=" << path
                << ", texture_id=" << texture_id
                << ", texture_unit=" << texture_unit
                << ", width=" << width
                << ", height=" << height
                << ", nrChannels=" << nrChannels
                << ", is_transparent=" << is_transparent
                << ", tile_factor=" << tile_factor << ")";
            return res.str();
        }
    };
    class Texture : public Bindable
    {
    public:
        inline Texture(const std::string &texture_path) : meta{texture_path, 0} {}
        inline Texture(const TextureMetaData &meta) : meta{meta} {}
        inline virtual ~Texture() {}

    public:
        TextureMetaData meta;
    };

    struct SubTexture
    {
        SubTexture() : is_active{false}
        {
        }
        SubTexture(uint32_t atlas_width, uint32_t altas_height, uint32_t subtext_size, uint32_t xloc, uint32_t yloc) : is_active{true},
                                                                                                                       atlas_width{atlas_width},
                                                                                                                       altas_height{altas_height},
                                                                                                                       subtext_size{subtext_size},
                                                                                                                       xloc{xloc},
                                                                                                                       yloc{yloc}
        {
        }
        bool is_active;

        uint32_t atlas_width;
        uint32_t altas_height;

        float subtext_size;
        float xloc;
        float yloc;
    };

    extern std::unordered_map<std::string, TextureMetaData> CACHE_TEXTURE_METADATA;

}

#endif