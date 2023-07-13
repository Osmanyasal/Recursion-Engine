#include <recursion.hh>
#include <proj1.hh>
#include <linux_window.hh>

using namespace Recursion::core::events;

bool handle_key_press(Event& event){
    REC_CORE_INFO("handle_key_press is executed");
    REC_CORE_INFO("event is {}",EVENT_TO_STRING((KeyPressEvent&)event));
    return true;
}
int main(int argc, char **argv)
{
    Proj1 proj;
    KeyPressEvent keypress{REC_KEY_A};

    EventDispatcher dispatcher{keypress};
    dispatcher.dispatch<KeyPressEvent>(&handle_key_press);    
    proj.start();
    return 0;
}
