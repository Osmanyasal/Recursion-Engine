#include <recursion>
#include <utils>
namespace Recursion::core
{
    Engine::Engine()
    {
        Recursion::utils::BaseLogger::init();
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
        while (true)
            ;
    }

} // namespace Recursion
