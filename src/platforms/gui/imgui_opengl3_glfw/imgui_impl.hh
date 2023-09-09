#ifndef RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH

#include <utils.hh>
#include <base_config.hh>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <window.hh>
#include <core_layers.hh>
#include <rec_imgui_key_mapping.hh>

namespace Recursion::core::window
{
    namespace layer = Recursion::core::layer;

    class ImguiLayer_glfw_opengl_impl : public layer::Layer
    {
    public:
        ImguiLayer_glfw_opengl_impl(GLFWwindow *gl_window)
            : layer::Layer{"imgui_layer"}, m_window{gl_window}
        {
            on_attach();
        }
        ~ImguiLayer_glfw_opengl_impl() { on_detach(); }

        void on_attach() override;
        void on_detach() override;
        void on_update(float delta_time) override;
        void on_event(events::Event &event) override;

        void begin_loop();
        void end_loop();
        void set_dark_theme_colors();
        void set_white_theme_colors();

        // GLFW _call_backs (individual _call_backs to call yourself if you didn't install _call_backs)
        bool on_window_focus_call_back(events::WindowFocusEvent &event);
        bool on_window_lost_focus_call_back(events::WindowLostFocusEvent &event);
        bool on_cursor_pos_call_back(events::MouseMovedEvent &event);
        bool on_mouse_button_pressed_call_back(events::MouseButtonPressed &event);
        bool on_mouse_button_released_call_back(events::MouseButtonReleased &event);
        bool on_scroll_call_back(events::MouseScrolledEvent &event);
        bool on_key_pressed_call_back(events::KeyPressEvent &event);
        bool on_key_released_call_back(events::KeyReleasedEvent &event);
        bool on_key_char_call_back(events::CharTypedEvent &event);
        bool on_monitor_close_call_back(events::WindowCloseEvent &event);
        bool on_monitor_resized_call_back(events::WindowResizedEvent &event);
        bool on_monitor_moved_call_back(events::WindowMovedEvent &event);

    private:
        void create_default_layout(uint32_t layout_id = 0);
        uint32_t create_dockspace();
        void create_menu();
        void create_menu_file();
        void create_menu_edit();
        void create_menu_window();
        void create_menu_tools();
        void create_menu_build();
        void create_menu_select();
        void create_menu_actor();
        void create_menu_help();

        void create_submenu(); // where, play, start,stop goes

        void create_log_window();
        void create_env_window();

    private:
        GLFWwindow *m_window;
    };
} // namespace Recursion::core::window

#endif