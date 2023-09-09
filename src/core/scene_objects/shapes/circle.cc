#include <circle.hh>

namespace Recursion::core::scene
{
    std::vector<float> Circle2D::get_positions(float radius, float z, float unit_angle)
    {
        float steps = 360.0f / unit_angle;
        std::vector<float> positions;

        positions.push_back(0);
        positions.push_back(0);
        positions.push_back(0);
        // Calculate the positions for the circle based on the given radius and number of unit_angle (segments).
        for (int32_t i = 0; i < steps; i += 1)
        {
            float radians = glm::radians(i * unit_angle);
            float x = radius * std::cos(radians);
            float y = radius * std::sin(radians);

            positions.push_back(x);
            positions.push_back(y);
            positions.push_back(z);
        }
        return positions;
    }

    std::vector<uint32_t> Circle2D::get_index_buffer(float unit_angle)
    {
        uint32_t vcount = (360.0f / unit_angle) + 1;
        std::vector<uint32_t> indices;

        for (uint32_t i = 0; i < vcount -2; i++)
        {
            indices.push_back(0);
            indices.push_back(i + 1);
            indices.push_back(i + 2);
        }
        indices.push_back(0);
        indices.push_back(vcount - 1);
        indices.push_back(1);
        return indices;
    }

    std::vector<float> Circle2D::get_colors(float color, float unit_angle)
    {
        uint32_t vcount = 360.0f / unit_angle + 1;
        std::vector<float> colors;
        // Assign the same color to all vertices of the circle.
        for (uint32_t i = 0; i < vcount; i += 1)
        {
            colors.push_back(color);
            colors.push_back(color);
            colors.push_back(color);
        }
        return colors;
    }

    std::vector<float> Circle2D::get_normals(float unit_angle)
    {
        uint32_t vcount = 360.0f / unit_angle + 1;
        std::vector<float> normals;
        // In 2D, all normals point in the same direction (usually [0, 0, 1]).
        for (uint32_t i = 0; i < vcount; i += 1)
        {
            normals.push_back(0.0f);
            normals.push_back(0.0f);
            normals.push_back(1.0f);
        }
        return normals;
    }

    std::vector<float> Circle2D::get_texture_coordinates(float tile_factor, float unit_angle)
    {
        uint32_t vcount = (360.0f / unit_angle) + 1;
        std::vector<float> texture_coordinates;
        // Calculate texture coordinates based on the unit_angle.
        for (uint32_t i = 0; i < vcount; i += 1)
        {
            float s = static_cast<float>(i) / 360.0f;
            texture_coordinates.push_back(s * tile_factor);
            texture_coordinates.push_back(0.0f);
        }
        return texture_coordinates;
    }
}
