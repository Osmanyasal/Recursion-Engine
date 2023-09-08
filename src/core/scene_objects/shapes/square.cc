
#include <square.hh>

namespace Recursion::core::scene
{

    std::vector<float> Rectangle2D::get_positions(float x, float y, float z)
    {
        std::vector<float> positions = {
            x, y, z,   // Top right     0
            x, -y, z,  // Bottom right  1
            -x, -y, z, // Bottom left   2
            -x, y, z,  // Top left      3
        };
        return positions;
    }

    std::vector<uint32_t> Rectangle2D::get_index_buffer()
    {
        std::vector<uint32_t> indices{
            0, 3, 2, // First triangle   upper left half
            // 0, 1, 2  // Second triangle  bottom right half
        };
        return indices;
    }
    std::vector<float> Rectangle2D::get_colors(float color)
    {
        std::vector<float> colors = {
            color, color, color, // Top right
            color, color, color, // Bottom right
            color, color, color, // Bottom left
            color, color, color, // Top left
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

}