#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__WINDOW_EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__WINDOW_EVENT_HH

#include <event.hh>

namespace Recursion::core::events
{
    class WindowEvent : public Event
    {
    public:
        SET_EVENT_CATEGORY((int)EventCategory::EventCategoryApplication);

        WindowEvent() {}
        virtual ~WindowEvent() {}

        inline virtual std::string to_string() override
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
        WindowResizedEvent(int width, int height)
            : m_width{width}, m_height{m_height}
        {
        }
        virtual ~WindowResizedEvent() {}

        inline int get_width() { return m_width; }
        inline int get_height() { return m_height; }

        inline virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowResizedEvent(" << WindowEvent::to_string() << ", "
                << "width=" << m_width << ", "
                << "height=" << m_height << ")";
            return res.str();
        }

    private:
        int m_width;
        int m_height;
    };

    class WindowCloseEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowClose)
        WindowCloseEvent() {}
        virtual ~WindowCloseEvent() {}

        inline virtual std::string to_string() override
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

        inline virtual std::string to_string() override
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

        inline virtual std::string to_string() override
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
        WindowMovedEvent(int x, int y) : posx{x}, posy{y} {}
        virtual ~WindowMovedEvent() {}

        inline virtual std::string to_string() override
        {
            std::stringstream res;
            res << "WindowMovedEvent(" << WindowEvent::to_string() << ","
                << "posx=" << posx << ", "
                << "posy=" << posy << ")";
            return res.str();
        }

    private:
        int posx, posy;
    };

    class AppTickEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppTick)
        AppTickEvent() {}
        virtual ~AppTickEvent() {}

        inline virtual std::string to_string() override
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

        inline virtual std::string to_string() override
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

        inline virtual std::string to_string() override
        {
            std::stringstream res;
            res << "AppRenderEvent(" << Event::to_string() << ")";
            return res.str();
        }
    };

} // namespace Recursion::core::events
#endif