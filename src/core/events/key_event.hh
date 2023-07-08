#include <event.hh>
#include <keyboard_mapping.hh>

#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH

namespace Recursion::core::events
{
    class KeyEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY(EventCategory::EventCategoryKeyboard | EventCategory::EventCategoryInput)

        KeyEvent(short key) : key_code{key}
        {
        }
        virtual ~KeyEvent() {}

        inline short get_keycode()
        {
            return key_code;
        }

    private:
        short key_code;
    };

    class KeyPressEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::KeyPressed)
        KeyPressEvent(short key, bool repeat = false) : KeyEvent{key}, is_repeat{repeat}
        {
        }
    } private : bool is_repeat;


}

#endif