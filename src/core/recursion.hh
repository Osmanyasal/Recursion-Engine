#ifndef RECURSION_ENGINE__SRC__CORE__RECURSION_HH
#define RECURSION_ENGINE__SRC__CORE__RECURSION_HH

#include <iostream>
#include <utils.hh>
#include <window.hh>
#include <event_core.hh> 
#include <linux_window.hh>

namespace Recursion::core
{
    class Engine
    { 
    public:
        Engine();
        virtual ~Engine();

        virtual void start() final;
        virtual void application() = 0;

		bool on_event(Recursion::core::events::Event& e) const;

    private:
        bool is_running;
        window::Window* window;
    };


    // global on_event function
    bool core_on_event(Recursion::core::events::Event& e);
} // namespace Recursion

#endif
