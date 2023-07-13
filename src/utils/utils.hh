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

// CUSTOM HEADERS
#include <config.hh>
#include <logger.hh>
#include <type.hh>

// OPTIMIZATION HEADERS
#include <cpu_opt>


// MACRO DEFINITIONS
#define BIT(x) (1 << x)

// FUNCTION DECLERATIONS
std::string generateGUID();

#endif