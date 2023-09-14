
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

    std::vector<float> Rectangle2D::get_texture_coordinates(uint32_t subtext_size, uint32_t x, uint32_t y)
    {
        std::vector<float> texture_coordinates{
            (x + subtext_size) / 2048.0f, (548 - y) / 548.0f,                // Top right
            (x + subtext_size) / 2048.0f, (548 - y - subtext_size) / 548.0f, // Bottom right
            (x) / 2048.0f, (548 - y - subtext_size) / 548.0f,                // Bottom left
            (x) / 2048.0f, (548 - y) / 548.0f,                               // Top left
        };
        return texture_coordinates;
    }

}