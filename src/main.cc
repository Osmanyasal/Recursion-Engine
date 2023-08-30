#include <recursion.hh>
#include <proj1.hh>

int32_t main(int32_t argc, char **argv)
{
    REC_PROFILE_BEGIN_SESSION("Recursion Engine", "gantt_instrumentation.json");

    Recursion::core::Engine engine;
    engine.add_application(new Proj1);
    engine.start();

    REC_PROFILE_END_SESSION();
    return 0;
}
