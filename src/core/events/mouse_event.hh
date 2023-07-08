
#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__MOUSE_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__MOUSE_EVENT_HH

#include <event.hh>
#include <mouse_mapping.hh>
namespace Recursion::core::events
{
    class MouseMovedEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseMoved)
        MouseMovedEvent(const float posX, const float posY) : pos_x{posX}, pos_y{posY}
        {
        }
        virtual ~MouseMovedEvent() {}

        inline float get_posx() { return pos_x; }
        inline float get_posy() { return pos_y; }

        friend std::ostream &operator<<(std::ostream &out, const MouseMovedEvent &event);

    private:
        float pos_x;
        float pos_y;
    };

    inline std::ostream &operator<<(std::ostream &out, const MouseMovedEvent &event)
    {
        out << (Event &)event << "MouseMovedEvent("
            << "pos_x=" << event.pos_x << ", "
            << "pos_y=" << event.pos_y << "))";
        return out;
    }

    class MouseScrolledEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseScrolled)
        MouseScrolledEvent(const float offsetX, const float offsetY) : offset_x{offsetX}, offset_y{offsetY}
        {
        }
        virtual ~MouseScrolledEvent() {}

        inline float get_offset_x() { return offset_x; }
        inline float get_offset_y() { return offset_y; }

        friend std::ostream &operator<<(std::ostream &out, const MouseScrolledEvent &event);

    private:
        float offset_x;
        float offset_y;
    };

    inline std::ostream &operator<<(std::ostream &out, const MouseScrolledEvent &event)
    {
        out << (Event &)event << "MouseScrolledEvent("
            << "offset_x=" << event.offset_x << ", "
            << "offset_y=" << event.offset_y << "))";
        return out;
    }

    class MouseButtonPressed : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseButtonPressed)

        MouseButtonPressed(const short mouse_button) : mouse_button{mouse_button}
        {
        }
        virtual ~MouseButtonPressed() {}

        inline short get_mouse_button() { return mouse_button; }

        friend std::ostream &operator<<(std::ostream &out, const MouseButtonPressed &event);

    private:
        short mouse_button;
    };

    inline std::ostream &operator<<(std::ostream &out, const MouseButtonPressed &event)
    {
        out << (Event &)event << "MouseButtonPressed("
            << "mouse_button=" << event.mouse_button << "))";
        return out;
    }

    class MouseButtonReleased : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryMouse | (int)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseButtonReleased)

        MouseButtonReleased(const short mouse_button) : mouse_button{mouse_button}
        {
        }
        virtual ~MouseButtonReleased() {}

        inline short get_mouse_button() { return mouse_button; }

        friend std::ostream &operator<<(std::ostream &out, const MouseButtonReleased &event);

    private:
        short mouse_button;
    };

    inline std::ostream &operator<<(std::ostream &out, const MouseButtonReleased &event)
    {
        out << (Event &)event << "MouseButtonReleased("
            << "mouse_button=" << event.mouse_button << "))";
        return out;
    }
}

#endif