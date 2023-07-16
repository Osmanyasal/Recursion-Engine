#ifndef RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_HH

#include <window.hh>
#include <layer.hh>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Recursion::core::window
{
    namespace layer = Recursion::core::layer;

    class ImguiLayer : public layer::Layer
    {
    public:
        ImguiLayer(GLFWwindow *gl_window)
            : layer::Layer{"imgui_layer"}, m_window{gl_window}
        {
            on_attach();
        }
        ~ImguiLayer() { on_detach(); }

        void on_attach() override;
        void on_detach() override;
        void on_update(double delta_time) override;
        void on_event(events::Event &event) override;

        void begin_loop();
        void end_loop();

    private:
        GLFWwindow *m_window;
    };

} // namespace Recursion::core::window

#endif