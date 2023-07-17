#include <recursion.hh>
#include <proj1.hh>
#include <utils.hh>
#include <Input.hh>

void Proj1::application()
{
    REC_INFO("hello from sandbox::proj1 ");
    if (Recursion::core::input::Input::is_key_pressed(REC_KEY_LEFT_CONTROL))
    {
        REC_CORE_ERROR("key CTRL is pressed !!");
    }
    if (Recursion::core::input::Input::is_mouse_button_pressed(REC_MOUSE_BUTTON_LEFT))
    {
        REC_CORE_ERROR("mouse button left is pressed !!");
    }
}