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
    };

    class WindowFocusEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowFocus)
        WindowFocusEvent() {}
        virtual ~WindowFocusEvent() {}
    };

    class WindowLostFocusEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowLostFocus)
        WindowLostFocusEvent() {}
        virtual ~WindowLostFocusEvent() {}
    };

    class WindowMovedEvent : public WindowEvent
    {
    public:
        SET_EVENT_TYPE(EventType::WindowMoved)
        WindowMovedEvent() {}
        virtual ~WindowMovedEvent() {}
    };

    class AppTickEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppTick)
        AppTickEvent() {}
        virtual ~AppTickEvent() {}
    };

    class AppUpdateEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppUpdate)
        AppUpdateEvent() {}
        virtual ~AppUpdateEvent() {}
    };

    class AppRenderEvent : public Event
    {
    public:
        SET_EVENT_TYPE(EventType::AppRender)
        AppRenderEvent() {}
        virtual ~AppRenderEvent() {}
    };

} // namespace Recursion::core::events
#endif