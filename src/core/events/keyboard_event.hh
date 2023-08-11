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

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "KeyEvent(" << Event::to_string() << "key_code=" << key_code << ")";
            return res.str();
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
        virtual ~KeyPressEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "KeyPressEvent(" << KeyEvent::to_string() << "is_repeat=" << is_repeat << ")";
            return res.str();
        }

    private:
        bool is_repeat;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::KeyReleased)
        KeyReleasedEvent(short key) : KeyEvent{key}
        {
        }
        virtual ~KeyReleasedEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "KeyReleasedEvent(" << KeyEvent::to_string() << ")";
            return res.str();
        }
    };
    class CharTypedEvent : public KeyEvent
    {
    public:
        SET_EVENT_TYPE(EventType::CharEvent)
        CharTypedEvent(short key) : KeyEvent{key}
        {
        }
        virtual ~CharTypedEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "CharTypedEvent(" << KeyEvent::to_string() << ")";
            return res.str();
        }
    };
}

#endif