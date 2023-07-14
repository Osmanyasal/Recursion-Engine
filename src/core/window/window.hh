#ifndef RECURSION_ENGINE__SRC__UTILS__WINDOW_HH
#define RECURSION_ENGINE__SRC__UTILS__WINDOW_HH

#include <config.hh>
#include <utils.hh>
#include <event_core.hh>
#include <memory>

namespace Recursion::core
{
    class Engine;
}
namespace Recursion::core::window
{
    struct WindowProps
    {
        std::string guid;
        std::string win_title;
        int win_width;
        int win_height;

        WindowProps(std::string title = "Recursion Engine", int width = 1600, int height = 900) : guid{generateGUID()}, win_title{title}, win_width{width}, win_height{height}
        {
        }
        // global callback function
        bool (*engine_callback_func)(Recursion::core::events::Event &event);
    };

    // interface representing a window system based Linux
    class Window
    {
    public:
        // map all events here!
        virtual void on_update() = 0;

        Window(const WindowProps &default_props = WindowProps())
        {
            this->win_props = default_props;
        }
        virtual ~Window()
        {
        }

        inline virtual std::string get_title() const final
        {
            return win_props.win_title;
        };

        inline virtual int get_width() const final
        {
            return win_props.win_width;
        };
        inline virtual int get_height() const final
        {
            return win_props.win_height;
        };

    protected:
        virtual void set_event_callback() const = 0;
        WindowProps win_props;
    };

} // namespace Recursion::core::window

#endif