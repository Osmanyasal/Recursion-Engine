#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_HH

#include <logger.hh>
#include <stdint.h>
namespace Recursion::core::input
{
    class BaseInput
    {
    public:
        BaseInput() {}
        virtual ~BaseInput() {}
        virtual bool is_key_pressed(int32_t key_code)
        {
            REC_CORE_WARN("Raw BaseInput is being used!");
            return false;
        }
        virtual bool is_mouse_button_pressed(int32_t mouse_button_code)
        {
            REC_CORE_WARN("Raw BaseInput is being used!");
            return false;
        }
        virtual void get_cursor_pos(double *xpos, double *ypos)
        {
            REC_CORE_WARN("Raw BaseInput is being used!");
        }
    };

    // global variable for platform Inputs.
    // will be set on window creatin @see platform/../linux_config.hh
    extern BaseInput* Input;

} // namespace Recursion::core::input

#endif