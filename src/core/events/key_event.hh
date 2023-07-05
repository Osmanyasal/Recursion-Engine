#include <event.hh>

#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH

namespace Recursion::core::events
{
    class KeyEvent : public Event
    {
    public:
        KeyEvent()
        {
        }
    };
}

#endif