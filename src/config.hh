#ifndef RECURSION_ENGINE__SRC__UTILS__CONFIG_HH
#define RECURSION_ENGINE__SRC__UTILS__CONFIG_HH
// CONF FILE FOR  THE APPLICATION
// EVERYTHING CAN BE ADJUSTED ONLY HERE, THE REST WILL CHANGE ON EACH COMPILATION ACCORDINGLY
// FORMAT: CONF__[SECTION]__[YOUR CONTENT]

// MATH LIBRARY
#define CONF_MATH_LIB glm

// PHYSICS LIBRARY
#define CONF_PHYSICS_LIB

// DETECT PLATFORM AND CREATE A WINDOW BASED ON IT
#if defined(_WIN32)
#define CONF__OS_NAME "Windows"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME)
#elif defined(__linux__)
#define CONF__OS_NAME "Linux"
#define CREATE_WINDOW()                                  \
    Recursion::core::window::WindowProps default_props;  \
    default_props.engine_callback_func = &core_on_event; \
    window = new Recursion::core::window::LinuxWindow{new Recursion::opengl::render::OpenGLRenderContext{default_props}};
#elif defined(__APPLE__) && defined(__MACH__)
#define CONF__OS_NAME "macOS"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME) 
#else
#define CONF__OS_NAME "Unknown"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME)
#endif

/**
 * @brief Porting enviroment
 * when is enabled, it removes trace logs.
 *
 */
#define CONF__PORTING__IS_PRODUCTION 0

/**
 * @brief GLFW Window specs.
 *
 *
 */
#define CONF__REC__GLFW_CONTEXT_VERSION_MAJOR 3
#define CONF__REC__GLFW_CONTEXT_VERSION_MINOR 3
#define CONF__REC__GLFW_GL_VERSION "#version 330"

#define CONF__REC__WINDOW_POSX 0
#define CONF__REC__WINDOW_POSY 0

#define CONF__REC__WINDOW_WIDTH 2560.0
#define CONF__REC__WINDOW_HEIGHT 1440.0

/**
 * @brief LOGGING
 *
 */

#define CONF__LOG__PRINT_GUID_LENGTH 5
#define CONF__LOG__ENABLE_CORE_LOGGING 1
#define CONF__LOG__ENABLE_SANDBOX_LOGGING 1

#define CONF__LOG__ENABLE_DEBUG 0
#define CONF__LOG__ENABLE_TRACE 1
#define CONF__LOG__ENABLE_INFO  1
#define CONF__LOG__ENABLE_WARN  1
#define CONF__LOG__ENABLE_ERROR 1


/**
 * @brief Graphics
*/




/**
 * @brief IDE Features
 * 
*/
#define CONF__IDE__TEXT_SIZE 18
#define CONF__IDE__ZOOM_STEP 0.25
#define CONF__IDE__MIN_DISTANCE 0.10
#define CONF__IDE__MAX_DISTANCE 20.0

#endif




/**
 * @brief GANTT INSTRUMENTATION
*/

#define REC_CORE_PROFILE 0
#define REC_PROFILE 1