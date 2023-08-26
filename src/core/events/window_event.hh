#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__WINDOW_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__WINDOW_EVENT_HH

#include <event.hh>

namespace Recursion::core::events
{
    class WindowEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int32_t)EventCategory::EventCategoryApplication);

        WindowEvent() {}
        virtual ~WindowEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowEvent(" << Event::to_string() << ")";
            return res.str();
        }
    };

    class WindowResizedEvent : public WindowEvent
    {

    public:
        SET_EVENT_TYPE(EventType::WindowResize)
        WindowResizedEvent(int32_t width, int32_t height)
            : m_width{width}, m_height{height}
        {
        }
        virtual ~WindowResizedEvent() {}

        inline int32_t get_width() { return m_width; }
        inline int32_t get_height() { return m_height; }

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowResizedEvent(" << WindowEvent::to_string() << ", "
                << "width=" << m_width << ", "
                << "height=" << m_height << ")";
            return res.str();
        }

    private:
        int32_t m_width;
        int32_t m_height;
    };

    class WindowCloseEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowClose)
        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowCloseEvent(" << WindowEvent::to_string() << ")";
            return res.str();
        }
    };

    class WindowFocusEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowFocus)
        WindowFocusEvent() {}
        virtual ~WindowFocusEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowFocusEvent(" << WindowEvent::to_string() << ")";
            return res.str();
        }
    };

    class WindowLostFocusEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowLostFocus)
        WindowLostFocusEvent() {}
        virtual ~WindowLostFocusEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowLostFocusEvent(" << WindowEvent::to_string() << ")";
            return res.str();
        }
    };

    class WindowMovedEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowMoved)
        WindowMovedEvent(int32_t x, int32_t y) : posx{x}, posy{y} {}
        virtual ~WindowMovedEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowMovedEvent(" << WindowEvent::to_string() << ","
                << "posx=" << posx << ", "
                << "posy=" << posy << ")";
            return res.str();
        }

    private:
        int32_t posx, posy;
    };

    class AppTickEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppTick)
        AppTickEvent() {}
        virtual ~AppTickEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "AppTickEvent(" << Event::to_string() << ")";
            return res.str();
        }
    };

    class AppUpdateEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppUpdate)
        AppUpdateEvent() {}
        virtual ~AppUpdateEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "AppUpdateEvent(" << Event::to_string() << ")";
            return res.str();
        }
    };

    class AppRenderEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppRender)
        AppRenderEvent() {}
        virtual ~AppRenderEvent() {}

        virtual std::string to_string() override
        {
            std::stringstream res;
            res << "AppRenderEvent(" << Event::to_string() << ")";
            return res.str();
        }
    };

} // namespace Recursion::core::events
#endif