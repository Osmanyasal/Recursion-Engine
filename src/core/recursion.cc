#include <recursion>

namespace Recursion
{
    Engine::Engine()
    {
        std::cout << "Engine Created!\n";
    }

    Engine::~Engine()
    {
        std::cout << "Engine Destroyed!\n";
    }

    void Engine::start()
    {
        std::cout << "Engine Started\n";
        this->application();
        while (true);
    }

} // namespace Recursion
