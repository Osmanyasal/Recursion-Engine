#ifndef RECURSION_ENGINE__SRC__CORE__RECURSION_HH
#define RECURSION_ENGINE__SRC__CORE__RECURSION_HH

#include <iostream>
#include <utils.hh>
#include <window.hh>
#include <event_core.hh> 

namespace Recursion::core
{
    class Engine
    {
    public:
        Engine();
        virtual ~Engine();

        virtual void start() final;
        virtual void application() = 0;
    };
} // namespace Recursion

#endif
