#include <recursion.hh>
#include <utils.hh>
namespace Recursion::core
{
    Engine::Engine()
    {
        Recursion::utils::BaseLogger::init();
        window = new core::window::LinuxWindow{};
        is_running = true;
        REC_CORE_INFO("Engine Created!");
    }

    Engine::~Engine()
    {
        REC_CORE_INFO("Engine Terminated!");
    }

    void Engine::start()
    {
        REC_CORE_INFO("Engine Started!");
        this->application();
        while (is_running)
        {
            glClearColor(.6f, 0.2f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            window->on_update();
        }
    }

} // namespace Recursion::core
