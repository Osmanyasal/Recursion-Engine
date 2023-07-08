#include <recursion.hh>
#include <utils.hh>
#include <proj1.hh>
#include <event_core.hh>

using namespace Recursion::core::events;

int main(int argc, char **argv)
{
    Proj1 proj;
    KeyReleasedEvent key1{65};
    KeyPressEvent key2{65};
    KeyTypedEvent key3{69};
    key3.is_handled = true;

    REC_CORE_INFO(EVENT_LOG(key1));
    REC_CORE_INFO(EVENT_LOG(key2));
    REC_CORE_INFO(EVENT_LOG(key3));

    std::cout << "\n\n******\n"
              << std::endl;

    MouseMovedEvent mouse_moved{3.3312f, 12.03f};
    REC_CORE_INFO(EVENT_LOG(mouse_moved));

    MouseScrolledEvent scroll_event{3.33f, 2.22f};
    REC_CORE_INFO(EVENT_LOG(scroll_event));

    MouseButtonPressed mouse_button_press{REC_MOUSE_BUTTON_LEFT};
    REC_CORE_INFO(EVENT_LOG(mouse_button_press));

    MouseButtonReleased mouse_button_released{REC_MOUSE_BUTTON_LEFT};
    REC_CORE_INFO(EVENT_LOG(mouse_button_released));

    // proj.start();
    return 0;
}
