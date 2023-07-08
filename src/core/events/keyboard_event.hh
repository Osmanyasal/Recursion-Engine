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
    inline std::ostream &operator<<(std::ostream &out, const KeyPressEvent &event)
    {
        out << (KeyEvent &)event << "KeyPressEvent("
            << "is_repeat=" << event.is_repeat << "))";
        return out;
    }

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::KeyReleased)
        KeyReleasedEvent(short key) : KeyEvent{key}
        {
        }
        virtual ~KeyReleasedEvent() {}

        friend inline std::ostream &operator<<(std::ostream &out, const KeyReleasedEvent &event);
    };
    inline std::ostream &operator<<(std::ostream &out, const KeyReleasedEvent &event)
    {
        out << (KeyEvent &)event << "KeyReleasedEvent())";
        return out;
    }
    class KeyTypedEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::KeyTyped)
        KeyTypedEvent(short key) : KeyEvent{key}
        {
        }
        virtual ~KeyTypedEvent() {}

        friend inline std::ostream &operator<<(std::ostream &out, const KeyTypedEvent &event);
    };
    inline std::ostream &operator<<(std::ostream &out, const KeyTypedEvent &event)
    {
        out << (KeyEvent &)event << "KeyTypedEvent())";
        return out;
    }
}

#endif