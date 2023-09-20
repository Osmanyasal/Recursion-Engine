#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH

#include <string>
#include <sstream>
#include <bindable.hh>
#include <unordered_map>
#include <json.hh>
#include <fstream>
#include <cpu_opt.hh>
#include <logger.hh>
#include <stdexcept>

namespace Recursion::core::render
{

    using json = nlohmann::json;
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

        /**
         * @brief Construct a new Sub Texture object \n
         * used with @see Texture to fetch subtexture
         *
         * it will get from-to: (xloc,yloc -> xloc+subtext_size, yloc+subtext_size)
         *
         * @param atlas_width
         * @param altas_height
         * @param subtext_size size of the subtexture
         * @param xloc starting point of the sub texture X axis
         * @param yloc starting point of the sub texture Y axis
         */
        SubTexture(uint32_t atlas_width, uint32_t altas_height, float subtext_size, float xloc, float yloc) : is_active{true},
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

    class AtlasReader
    {
    public:
        AtlasReader(const std::string &atlas_json);
        std::string get_texture_path() const;
        SubTexture get_subtexture(const std::string &name);
 
    private:
        json data;

    };

    extern std::unordered_map<std::string, TextureMetaData> CACHE_TEXTURE_METADATA;

}

#endif