#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH

#include <utils.hh>
#include <sstream>

// put your event reference, it returns the operator<< string to you regarding class hierarchy.
#define EVENT_LOG(expression)   \
    [&]() -> std::string {      \
        std::ostringstream oss; \
        oss << expression;      \
        return oss.str();       \
    }()

namespace Recursion::core::events
{
    enum class EventType : int
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
        KeyTyped,

        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum class EventCategory : int
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define SET_EVENT_TYPE(type)                                           \
    virtual EventType get_event_type() const override { return type; } \
    virtual std::string get_name() const override { return #type; }

#define SET_EVENT_CATEGORY(event_category) \
    virtual int get_category_flags() const override { return event_category; }

    class Event
    {
    public:
        bool is_handled;
        virtual EventType get_event_type() const = 0;
        virtual std::string get_name() const = 0;
        virtual int get_category_flags() const = 0;

        inline virtual bool in_category(EventCategory category) final
        {
            return get_category_flags() & (int)category;
        }
        friend inline std::ostream &operator<<(std::ostream &out, const Event &event);

    protected:
        Event() : is_handled{false} {}
        virtual ~Event() {}
    };

    inline std::ostream &operator<<(std::ostream &out, const Event &event)
    {
        out << "Event("
            << "is_handled=" << event.is_handled << ", ";
        return out;
    }

} // namespace Recursion::core::events

#endif