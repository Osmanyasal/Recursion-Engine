#ifndef RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_WINDOW_HH

#include <window.hh>

namespace Recursion::core::window
{
    class LinuxWindow //: public Window
    {
    public:
        LinuxWindow(const WindowProps &default_props = WindowProps()) : default_props{default_props}
        {
            REC_CORE_INFO("Linux Window Started");
        }
        virtual ~LinuxWindow() {}

    private:
        const WindowProps default_props;
    };
}
#endif