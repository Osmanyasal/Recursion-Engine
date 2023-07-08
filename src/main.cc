#include <recursion.hh>
#include <utils.hh>
#include <proj1.hh>
#include <event.hh>
#include <keyboard_event.hh>

using namespace Recursion::core::events;

int main(int argc, char **argv)
{
    Proj1 proj;
    KeyPressEvent key{65};
    std::cout << EVENT_LOG(key) << std::endl;
    REC_CORE_WARN(EVENT_LOG(key));

    //proj.start();
    return 0;
}
