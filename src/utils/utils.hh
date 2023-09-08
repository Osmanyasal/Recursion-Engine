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
#include <memory>

// CUSTOM HEADERS
#include <base_config.hh>
#include <logger.hh>
#include <type.hh>

//TODO: Migrate this to a math wrapper.
// INCLUDE GLM 
#include <glm_utils.hh>

// OPTIMIZATION HEADERS
#include <cpu_opt.hh>

// PROFILING HEADERS
#include <block_timer.hh>
#include <gantt_instrumentor.hh>


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
 
#define GET_FPS() 1.0f / delta_time

#define BLOCK_TIMER(block_name) Recursion::utils::BlockTimer block_timer{block_name}


// FUNCTION DECLERATIONS
std::string generateGUID();

std::string read_file(std::string location);

#endif