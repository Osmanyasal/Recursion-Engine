#ifndef RECURSION_ENGINE__SRC__CORE__RECURSION_HH
#define RECURSION_ENGINE__SRC__CORE__RECURSION_HH

#include <iostream>
#include <utils.hh>
#include <window.hh>
#include <event_core.hh>
#include <linux_window.hh>
#include <layer_stack.hh> 
#include <imgui_layer_glfw_opengl_impl.hh>
#include <Input.hh>

namespace Recursion::core
{

    // global on_event function
    extern Engine* engine_ptr;
    template <typename T>
    bool core_on_event(T &e);

    class Engine
    {
    public:
        Engine();
        virtual ~Engine();

        virtual void start() final;
        virtual void application() = 0;

        bool on_event(Recursion::core::events::Event &e);

    private:
        bool is_running;
        window::Window *window; 
        window::ImguiLayer_glfw_opengl_impl* imgui_layer;
        layer::LayerStack* layer_stack;
    }; 

} // namespace Recursion

#endif