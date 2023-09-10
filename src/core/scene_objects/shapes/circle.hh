#ifndef RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CIRCLE_HH
#define RECURSION_ENGINE__SRC__CORE__SCENE_OBJECTS__CIRCLE_HH

#include <inttypes.h>
#include <vector>
#include <glm_utils.hh>

namespace Recursion::core::scene
{
    class Circle2D
    {
    public:
        static std::vector<float> get_positions(float raius = 1.0f, float z = 0.0f, float unit_angle = 1.0f);
        static std::vector<float> get_colors(float color = 1, float unit_angle = 1.0f);
        static std::vector<float> get_normals(float unit_angle = 1.0f);
        static std::vector<float> get_texture_coordinates(float tile_factor = 1.0f, float unit_angle = 1.0f);
        static std::vector<uint32_t> get_index_buffer(float unit_angle = 1.0f);

    private:
        Circle2D(/* args */);
        ~Circle2D();
    };
} // namespace Recursion::core::scene

#endif