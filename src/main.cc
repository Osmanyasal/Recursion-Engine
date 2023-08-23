#include <recursion.hh>
#include <proj1.hh>

int32_t main(int32_t argc, char **argv)
{
    Recursion::core::Engine engine;
    Proj1* prj = new Proj1;
    engine.add_application(prj);
    engine.start();
    return 0;
}
