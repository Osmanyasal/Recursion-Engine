#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH
#include <texture.hh>

namespace Recursion::core::render
{
    std::unordered_map<std::string, TextureMetaData> CACHE_TEXTURE_METADATA;

    AtlasReader::AtlasReader(const std::string &atlas_json)
    {
        std::ifstream f(atlas_json);
        if (OPT_UNLIKELY(!f.is_open()))
        {
            REC_CORE_ERROR("{} atlas_json is not opened", atlas_json);
            throw std::invalid_argument{atlas_json + " atlas_json is not opened"};
        }
        else
        {
            data = json::parse(f);
        }
    }
    std::string AtlasReader::get_texture_path() const
    {
        return data["meta"]["image"];
    }

    SubTexture AtlasReader::get_subtexture(const std::string &name)
    {
        if (OPT_LIKELY(data["frames"].contains(name)))
        {
            uint32_t atlas_width = data["meta"]["size"]["w"];
            uint32_t atlas_height = data["meta"]["size"]["h"];
            json subtexture = data["frames"][name];

            float texture_size = std::min(subtexture["sourceSize"]["w"],subtexture["sourceSize"]["h"]);

            uint32_t xloc = subtexture["frame"]["x"];
            uint32_t yloc = subtexture["frame"]["y"];

            return SubTexture{atlas_width, atlas_height, texture_size, xloc, yloc};
        }
        else
        {
            REC_CORE_WARN("subtexture:{} not found", name);
        }
        return SubTexture{};
    }

}

#endif