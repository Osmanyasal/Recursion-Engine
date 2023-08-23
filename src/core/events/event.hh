#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH

#include <utils.hh>
#include <sstream>

namespace Recursion::core::events
{
    enum class EventType : int32_t
    {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,

        AppTick,
        AppUpdate,
        AppRender,

        KeyPressed,
        KeyReleased,
        CharEvent,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum class EventCategory : int32_t
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define SET_EVENT_TYPE(type)                                           \
    static EventType get_static_event_type() { return type; }          \
    virtual EventType get_event_type() const override { return type; } \
    virtual std::string get_name() const override { return #type; }

#define SET_EVENT_CATEGORY(event_category) \
    virtual int32_t get_category_flags() const override { return event_category; }

    class Event
    {
    public:
        void* additional_data;
        bool is_handled;
        virtual EventType get_event_type() const = 0;
        virtual std::string get_name() const = 0;
        virtual int32_t get_category_flags() const = 0;

        virtual bool in_category(EventCategory category) final
        {
            return get_category_flags() & (int32_t)category;
        }
        virtual std::string to_string()
        {
            std::stringstream res;
            res << "Event("
                << "is_handled=" << is_handled << ")";
            return res.str();
        }

    protected:
        Event() : is_handled{false} {}
        virtual ~Event() {}
    };

    // Blank event indicates no-event
    class EmptyEvent : public Event{
        public:
            SET_EVENT_CATEGORY((int32_t)EventCategory::None)
            SET_EVENT_TYPE(EventType::None)
    };

    /**
     * @brief Binds event to a function that takes an event parameter T and returns boolean
     *
     */
    class EventBinder
    {
        template <typename T>
        using EventFunc = std::function<bool(T &)>;

    public:
        EventBinder(Event &event)
            : m_event{event}
        {
        }

        template <typename T>
        inline bool bind(EventFunc<T> func)
        {
            if (OPT_LIKELY(m_event.get_event_type() == T::get_static_event_type()))
            {
                m_event.is_handled = func(*(T *)&m_event);
                return true;
            }
            else
            {
                REC_CORE_WARN("Event Type and Function doesn't match !");
            }
            return false;
        }

    private:
        Event &m_event;
    };

} // namespace Recursion::core::events

#endif