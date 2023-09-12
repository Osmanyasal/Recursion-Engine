#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH

#include <string>
#include <bindable.hh>

namespace Recursion::core::render
{

    struct TextureMetaData
    {
        const std::string &path;
        uint32_t texture_id;
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
}

#endif