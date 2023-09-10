#ifndef RECURSION_ENGINE__SRC__CORE__WINDOW__WINDOW_HH
#define RECURSION_ENGINE__SRC__CORE__WINDOW__WINDOW_HH

#include <window_config.hh>
#include <string>
#include <memory>
#include <core_events.hh>
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
        int32_t win_width;
        int32_t win_height;
        int32_t win_posx;
        int32_t win_posy;
        WindowProps(std::string title = "Recursion Engine",
                    int32_t width = CONF__REC__WINDOW_WIDTH,
                    int32_t height = CONF__REC__WINDOW_HEIGHT,
                    int32_t posx = CONF__REC__WINDOW_POSX,
                    int32_t posy = CONF__REC__WINDOW_POSY)
            : guid{generateGUID()}, win_title{title}, win_width{width}, win_height{height}, win_posx{posx}, win_posy{posy}
        {
        }
        // global event callback function
        bool (*engine_callback_func)(Recursion::core::events::Event &event);
    };

    // interface representing a window system based Linux
    class Window
    {
    public:
        // map all events here!
        virtual void on_update() = 0;

        // inits class Input that inquires if an input is pressed or not _see Input.hh
        virtual void init_Input() = 0;

        Window(const WindowProps *default_props) : win_props{*default_props}
        {
        }
        virtual ~Window()
        {
        }

        virtual std::string get_title() const final
        {
            return win_props.win_title;
        };

        virtual int32_t get_width() const final
        {
            return win_props.win_width;
        };
        virtual int32_t get_height() const final
        {
            return win_props.win_height;
        };

        virtual int32_t get_posx() const final
        {
            return win_props.win_posy;
        };
        virtual int32_t get_posy() const final
        {
            return win_props.win_posy;
        };

    public:
        core::input::BaseInput* input;

    protected:
        virtual void set_event_callback() const = 0;
        const WindowProps &win_props;
    };

} // namespace Recursion::core::window

#endif