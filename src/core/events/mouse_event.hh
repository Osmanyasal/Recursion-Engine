
#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__MOUSE_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__MOUSE_EVENT_HH

#include <event.hh>
#include <mouse_mapping.hh>
namespace Recursion::core::events
{
    class MouseMovedEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int32_t)EventCategory::EventCategoryMouse | (int32_t)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseMoved)
        MouseMovedEvent(const double posX, const double posY) : pos_x{posX}, pos_y{posY}
        {
        }
        virtual ~MouseMovedEvent() {}

        inline double get_posx() { return pos_x; }
        inline double get_posy() { return pos_y; }

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "MouseMovedEvent(" << Event::to_string() << ", "
                << "pos_x=" << pos_x << ", "
                << "pos_y=" << pos_y << ")";
            return res.str();
        }

    private:
        double pos_x;
        double pos_y;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int32_t)EventCategory::EventCategoryMouse | (int32_t)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseScrolled)
        MouseScrolledEvent(const double offsetX, const double offsetY) : offset_x{offsetX}, offset_y{offsetY}
        {
        }
        virtual ~MouseScrolledEvent() {}

        inline double get_offset_x() { return offset_x; }
        inline double get_offset_y() { return offset_y; }

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "MouseScrolledEvent(" << Event::to_string() << ", "
                << "offset_x=" << offset_x << ", "
                << "offset_y=" << offset_y << ")";
            return res.str();
        }

    private:
        double offset_x;
        double offset_y;
    };

    class MouseButtonPressed : public Event
    {
    public:
        SET_EVENT_CATEGORY((int32_t)EventCategory::EventCategoryMouse | (int32_t)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseButtonPressed)

        MouseButtonPressed(const int16_t mouse_button) : mouse_button{mouse_button}
        {
        }
        virtual ~MouseButtonPressed() {}

        inline int16_t get_mouse_button() { return mouse_button; }

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "MouseButtonPressed(" << Event::to_string() << ", "
                << "mouse_button=" << mouse_button << ")";
            return res.str();
        }

    private:
        int16_t mouse_button;
    };

    class MouseButtonReleased : public Event
    {
    public:
        SET_EVENT_CATEGORY((int32_t)EventCategory::EventCategoryMouse | (int32_t)EventCategory::EventCategoryInput)
        SET_EVENT_TYPE(EventType::MouseButtonReleased)

        MouseButtonReleased(const int16_t mouse_button) : mouse_button{mouse_button}
        {
        }
        virtual ~MouseButtonReleased() {}

        inline int16_t get_mouse_button() { return mouse_button; }

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "MouseButtonReleased(" << Event::to_string() << ", "
                << "mouse_button=" << mouse_button << ")";
            return res.str();
        }

    private:
        int16_t mouse_button;
    };
}

#endif