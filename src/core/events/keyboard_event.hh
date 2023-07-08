#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__KEYBOARD_EVENT_HH

#include <event.hh>
#include <keyboard_mapping.hh>

namespace Recursion::core::events
{

    class KeyEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryKeyboard | (int)EventCategory::EventCategoryInput)

        KeyEvent(short key) : key_code{key}
        {
        }
        virtual ~KeyEvent() {}

        inline short get_keycode()
        {
            return key_code;
        }

        friend inline std::ostream &operator<<(std::ostream &out, const KeyEvent &event);

    private:
        short key_code;
    };

    inline std::ostream &operator<<(std::ostream &out, const KeyEvent &event)
    {
        out << (Event &)event << "KeyEvent("
            << "key_code=" << event.key_code << ", ";
        return out;
    }

    class KeyPressEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::KeyPressed)
        KeyPressEvent(short key, bool repeat = false) : KeyEvent{key}, is_repeat{repeat}
        {
        }
        virtual ~KeyPressEvent() {}

        friend inline std::ostream &operator<<(std::ostream &out, const KeyPressEvent &event);

    private:
        bool is_repeat;
    };
    inline  std::ostream &operator<<(std::ostream &out, const KeyPressEvent &event)
    {
        out << (KeyEvent &)event << "KeyPressEvent("
            << "is_repeat=" << event.is_repeat << "))";
        return out;
    }
}

#endif