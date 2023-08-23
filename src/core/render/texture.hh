#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__TEXTURE_HH

#include <iostream>
#include <string>
#include <bindable.hh>

namespace Recursion::core::render
{
    class Texture : public Bindable
    {
    public:
        inline Texture(const std::string &texture_path) : path{texture_path} {}
        inline virtual ~Texture() {}

        const std::string &get_path() const { return this->path; }
        inline const uint32_t get_textureid() const { return texture_id; } 

    protected:
        const std::string path;
        uint32_t texture_id;
    };
}

#endif