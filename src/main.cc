#include <recursion.hh>
#include <proj1.hh>

int32_t main(int32_t argc, char **argv)
{
    Recursion::core::Engine engine;
    engine.add_application(new Proj1);
    engine.start();
    return 0;
}
