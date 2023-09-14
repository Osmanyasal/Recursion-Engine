
#include <rectangle.hh>

namespace Recursion::core::scene
{

    std::vector<float> Rectangle2D::get_positions(const glm::vec3 &size)
    {
        std::vector<float> positions = {
            size.x, size.y, size.z,   // Top right     0
            size.x, -size.y, size.z,  // Bottom right  1
            -size.x, -size.y, size.z, // Bottom left   2
            -size.x, size.y, size.z,  // Top left      3
        };
        return positions;
    }

    std::vector<uint32_t> Rectangle2D::get_index_buffer()
    {
        std::vector<uint32_t> indices{
            0, 3, 2, // First triangle   upper left half
            0, 1, 2  // Second triangle  bottom right half
        };
        return indices;
    }
    std::vector<float> Rectangle2D::get_colors(const glm::vec4 &color)
    {
        std::vector<float> colors = {
            color.r, color.g, color.b, color.a, // Top right
            color.r, color.g, color.b, color.a, // Bottom right
            color.r, color.g, color.b, color.a, // Bottom left
            color.r, color.g, color.b, color.a  // Top left
        };
        return colors;
    }
    std::vector<float> Rectangle2D::get_normals()
    {
        std::vector<float> normals = {
            0, 0, 1, // Top right
            0, 0, 1, // Bottom right
            0, 0, 1, // Bottom left
            0, 0, 1, // Top left
        };
        return normals;
    }
    std::vector<float> Rectangle2D::get_texture_coordinates(float tile_factor)
    {
        std::vector<float> texture_coordinates{
            tile_factor, tile_factor, // Top right
            tile_factor, 0,           // Bottom right
            0, 0,                     // Bottom left
            0, tile_factor,           // Top left
        };
        return texture_coordinates;
    }

    std::vector<float> Rectangle2D::get_texture_coordinates(const render::SubTexture &subtexture)
    {
        std::vector<float> texture_coordinates{
            (subtexture.xloc + subtexture.subtext_size) / subtexture.atlas_width, (subtexture.altas_height - subtexture.yloc) / subtexture.altas_height,                           // Top right
            (subtexture.xloc + subtexture.subtext_size) / subtexture.atlas_width, (subtexture.altas_height - subtexture.yloc - subtexture.subtext_size) / subtexture.altas_height, // Bottom right
            (subtexture.xloc) / subtexture.atlas_width, (subtexture.altas_height - subtexture.yloc - subtexture.subtext_size) / subtexture.altas_height,                           // Bottom left
            (subtexture.xloc) / subtexture.atlas_width, (subtexture.altas_height - subtexture.yloc) / subtexture.altas_height,                                                     // Top left
        };
        return texture_coordinates;
    }

}