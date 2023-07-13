#ifndef RECURSION_ENGINE__SRC__UTILS__CONFIG_HH
#define RECURSION_ENGINE__SRC__UTILS__CONFIG_HH

// format is like CONF__[SECTION]__[YOUR CONTENT]
/**
 * @brief Porting enviroment
 *
 */
#define CONF__PORTING__IS_PRODUCTION 0

/**
 * @brief GLFW version
 *
 *  REC : Recursive Engine section
 */
#define CONF__REC__GLFW_CONTEXT_VERSION_MAJOR 3
#define CONF__REC__GLFW_CONTEXT_VERSION_MINOR 3

/**
 * @brief LOGGING
 *
 */

#define CONF__LOG__ENABLE_CORE_LOGGING 1
#define CONF__LOG__ENABLE_SANDBOX_LOGGING 1

#endif