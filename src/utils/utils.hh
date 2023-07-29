#ifndef RECURSION_ENGINE__SRC__UTILS__UTILS
#define RECURSION_ENGINE__SRC__UTILS__UTILS
/*
    All header files that's defined in utils.
    to access utils include this file
*/

// C++ LEVEL HEADERS
#include <iomanip>
#include <random>
#include <sstream>
#include <algorithm>
#include <fstream>

// CUSTOM HEADERS
#include <config.hh>
#include <logger.hh>
#include <type.hh>

//TODO: Migrate this to a math wrapper.
// INCLUDE GLM
#include <glm/vec3.hpp>                  // glm::vec3
#include <glm/vec4.hpp>                  // glm::vec4
#include <glm/mat4x4.hpp>                // glm::mat4
#include <glm/ext/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp>  // glm::pi
#include <glm/gtx/string_cast.hpp>

// OPTIMIZATION HEADERS
#include <cpu_opt>


// MACRO DEFINITIONS
#define BIT(x) (1 << x)
//#define REC_BIND_EVENT_FUNC(x) std::bind(&x,this,std::placeholders::_1)

#define DELTA_TIME_INIT()                       \
    double previous_time = glfwGetTime();       \
    double current_time = 0;                    \
    double delta_time = 0;                      

#define DELTA_TIME_UPDATE()                     \
    current_time = glfwGetTime();               \
    delta_time = current_time - previous_time;  \
    previous_time = current_time;               \

#define FPS_INIT()                              \
    double fps_previous_time = glfwGetTime();   \
    double fps_current_time = 0;                \
    short frame_count = 0;                      \

#define FPS_UPDATE()                                                        \
    fps_current_time = glfwGetTime();                                       \
    frame_count++;                                                          \
    if (OPT_UNLIKELY(fps_current_time - fps_previous_time >= 1.0))          \
    {                                                                       \
        REC_CORE_INFO("FPS: {}", frame_count);                              \
        frame_count = 0;                                                    \
        fps_previous_time = fps_current_time;                               \
    }



// FUNCTION DECLERATIONS
std::string generateGUID();

std::string read_file(std::string location);

#endif