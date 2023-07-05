#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__EVENT_HH

#include <utils.hh>
namespace Recursion::core::events
{
    enum class EventType
	{
		None = 0,
		WindowClose = 100, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick = 200, AppUpdate, AppRender,
		KeyPressed = 300, KeyReleased, KeyTyped,
		MouseButtonPressed = 400, MouseButtonReleased, MouseMoved, MouseScrolled
	};

    class Event
    {

    public:
        bool is_handled;
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

    protected:
        Event() : is_handled{false} {}
        virtual ~Event() {}
    };

} // namespace Recursion::core::events

#endif