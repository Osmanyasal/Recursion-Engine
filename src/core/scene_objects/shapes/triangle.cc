
#include <triangle.hh>

namespace Recursion::core::scene
{

    std::vector<float> Triangle2D::get_positions(const glm::vec3 &size) // x,y,z
    {
        std::vector<float> positions = {
            0, size.y, size.z,  // top
            -size.x, 0, size.z, // left
            size.x, 0, size.z}; // right
        return positions;
    }

    std::vector<uint32_t> Triangle2D::get_index_buffer()
    {
        std::vector<uint32_t> indices{0, 1, 2};
        return indices;
    }
    std::vector<float> Triangle2D::get_colors(float color)
    {
        std::vector<float> colors = {
            color, color, color,0.5f, // Top
            color, color, color,0.5f, // Left
            color, color, color,0.5f, // Right
        };
        return colors;
    }
    std::vector<float> Triangle2D::get_normals()
    {
        std::vector<float> normals = {
            0, 0, 1, // Top
            0, 0, 1, // Left
            0, 0, 1, // Right
        };
        return normals;
    }
    std::vector<float> Triangle2D::get_texture_coordinates(float tile_factor)
    {
        std::vector<float> texture_coordinates{
            tile_factor / 2, tile_factor, // Top
            0, 0,                         // Left
            tile_factor, 0                // Right
        };
        return texture_coordinates;
    }
}