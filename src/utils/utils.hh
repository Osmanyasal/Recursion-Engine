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

// CUSTOM HEADERS
#include <config.hh>
#include <logger.hh>
#include <type.hh>

// OPTIMIZATION HEADERS
#include <cpu_opt>


// MACRO DEFINITIONS
#define BIT(x) (1 << x)
//#define REC_BIND_EVENT_FUNC(x) std::bind(&x,this,std::placeholders::_1)

// FUNCTION DECLERATIONS
std::string generateGUID();

#endif