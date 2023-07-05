#ifndef RECURSION_ENGINE__SRC__CORE__RECURSION_HH
#define RECURSION_ENGINE__SRC__CORE__RECURSION_HH

#include <iostream>

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
