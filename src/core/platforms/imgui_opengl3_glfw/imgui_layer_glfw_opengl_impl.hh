#ifndef RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <window.hh>
#include <layer.hh>

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
        void on_update(double delta_time) override;
        void on_event(events::Event &event) override;

        void begin_loop();
        void end_loop();
        void set_dark_theme_colors();

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
        GLFWwindow *m_window;
    };
} // namespace Recursion::core::window


// conversion from Recursion engine key codes (essantialy glfw) to imgui keycodes
static ImGuiKey ImGui_ImplREC_KeyToImGuiKey(int key)
{
    switch (key)
    {
    case REC_KEY_TAB:
        return ImGuiKey_Tab;
    case REC_KEY_LEFT:
        return ImGuiKey_LeftArrow;
    case REC_KEY_RIGHT:
        return ImGuiKey_RightArrow;
    case REC_KEY_UP:
        return ImGuiKey_UpArrow;
    case REC_KEY_DOWN:
        return ImGuiKey_DownArrow;
    case REC_KEY_PAGE_UP:
        return ImGuiKey_PageUp;
    case REC_KEY_PAGE_DOWN:
        return ImGuiKey_PageDown;
    case REC_KEY_HOME:
        return ImGuiKey_Home;
    case REC_KEY_END:
        return ImGuiKey_End;
    case REC_KEY_INSERT:
        return ImGuiKey_Insert;
    case REC_KEY_DELETE:
        return ImGuiKey_Delete;
    case REC_KEY_BACKSPACE:
        return ImGuiKey_Backspace;
    case REC_KEY_SPACE:
        return ImGuiKey_Space;
    case REC_KEY_ENTER:
        return ImGuiKey_Enter;
    case REC_KEY_ESCAPE:
        return ImGuiKey_Escape;
    case REC_KEY_APOSTROPHE:
        return ImGuiKey_Apostrophe;
    case REC_KEY_COMMA:
        return ImGuiKey_Comma;
    case REC_KEY_MINUS:
        return ImGuiKey_Minus;
    case REC_KEY_PERIOD:
        return ImGuiKey_Period;
    case REC_KEY_SLASH:
        return ImGuiKey_Slash;
    case REC_KEY_SEMICOLON:
        return ImGuiKey_Semicolon;
    case REC_KEY_EQUAL:
        return ImGuiKey_Equal;
    case REC_KEY_LEFT_BRACKET:
        return ImGuiKey_LeftBracket;
    case REC_KEY_BACKSLASH:
        return ImGuiKey_Backslash;
    case REC_KEY_RIGHT_BRACKET:
        return ImGuiKey_RightBracket;
    case REC_KEY_GRAVE_ACCENT:
        return ImGuiKey_GraveAccent;
    case REC_KEY_CAPS_LOCK:
        return ImGuiKey_CapsLock;
    case REC_KEY_SCROLL_LOCK:
        return ImGuiKey_ScrollLock;
    case REC_KEY_NUM_LOCK:
        return ImGuiKey_NumLock;
    case REC_KEY_PRINT_SCREEN:
        return ImGuiKey_PrintScreen;
    case REC_KEY_PAUSE:
        return ImGuiKey_Pause;
    case REC_KEY_KP_0:
        return ImGuiKey_Keypad0;
    case REC_KEY_KP_1:
        return ImGuiKey_Keypad1;
    case REC_KEY_KP_2:
        return ImGuiKey_Keypad2;
    case REC_KEY_KP_3:
        return ImGuiKey_Keypad3;
    case REC_KEY_KP_4:
        return ImGuiKey_Keypad4;
    case REC_KEY_KP_5:
        return ImGuiKey_Keypad5;
    case REC_KEY_KP_6:
        return ImGuiKey_Keypad6;
    case REC_KEY_KP_7:
        return ImGuiKey_Keypad7;
    case REC_KEY_KP_8:
        return ImGuiKey_Keypad8;
    case REC_KEY_KP_9:
        return ImGuiKey_Keypad9;
    case REC_KEY_KP_DECIMAL:
        return ImGuiKey_KeypadDecimal;
    case REC_KEY_KP_DIVIDE:
        return ImGuiKey_KeypadDivide;
    case REC_KEY_KP_MULTIPLY:
        return ImGuiKey_KeypadMultiply;
    case REC_KEY_KP_SUBTRACT:
        return ImGuiKey_KeypadSubtract;
    case REC_KEY_KP_ADD:
        return ImGuiKey_KeypadAdd;
    case REC_KEY_KP_ENTER:
        return ImGuiKey_KeypadEnter;
    case REC_KEY_KP_EQUAL:
        return ImGuiKey_KeypadEqual;
    case REC_KEY_LEFT_SHIFT:
        return ImGuiKey_LeftShift;
    case REC_KEY_LEFT_CONTROL:
        return ImGuiKey_LeftCtrl;
    case REC_KEY_LEFT_ALT:
        return ImGuiKey_LeftAlt;
    case REC_KEY_LEFT_SUPER:
        return ImGuiKey_LeftSuper;
    case REC_KEY_RIGHT_SHIFT:
        return ImGuiKey_RightShift;
    case REC_KEY_RIGHT_CONTROL:
        return ImGuiKey_RightCtrl;
    case REC_KEY_RIGHT_ALT:
        return ImGuiKey_RightAlt;
    case REC_KEY_RIGHT_SUPER:
        return ImGuiKey_RightSuper;
    case REC_KEY_MENU:
        return ImGuiKey_Menu;
    case REC_KEY_0:
        return ImGuiKey_0;
    case REC_KEY_1:
        return ImGuiKey_1;
    case REC_KEY_2:
        return ImGuiKey_2;
    case REC_KEY_3:
        return ImGuiKey_3;
    case REC_KEY_4:
        return ImGuiKey_4;
    case REC_KEY_5:
        return ImGuiKey_5;
    case REC_KEY_6:
        return ImGuiKey_6;
    case REC_KEY_7:
        return ImGuiKey_7;
    case REC_KEY_8:
        return ImGuiKey_8;
    case REC_KEY_9:
        return ImGuiKey_9;
    case REC_KEY_A:
        return ImGuiKey_A;
    case REC_KEY_B:
        return ImGuiKey_B;
    case REC_KEY_C:
        return ImGuiKey_C;
    case REC_KEY_D:
        return ImGuiKey_D;
    case REC_KEY_E:
        return ImGuiKey_E;
    case REC_KEY_F:
        return ImGuiKey_F;
    case REC_KEY_G:
        return ImGuiKey_G;
    case REC_KEY_H:
        return ImGuiKey_H;
    case REC_KEY_I:
        return ImGuiKey_I;
    case REC_KEY_J:
        return ImGuiKey_J;
    case REC_KEY_K:
        return ImGuiKey_K;
    case REC_KEY_L:
        return ImGuiKey_L;
    case REC_KEY_M:
        return ImGuiKey_M;
    case REC_KEY_N:
        return ImGuiKey_N;
    case REC_KEY_O:
        return ImGuiKey_O;
    case REC_KEY_P:
        return ImGuiKey_P;
    case REC_KEY_Q:
        return ImGuiKey_Q;
    case REC_KEY_R:
        return ImGuiKey_R;
    case REC_KEY_S:
        return ImGuiKey_S;
    case REC_KEY_T:
        return ImGuiKey_T;
    case REC_KEY_U:
        return ImGuiKey_U;
    case REC_KEY_V:
        return ImGuiKey_V;
    case REC_KEY_W:
        return ImGuiKey_W;
    case REC_KEY_X:
        return ImGuiKey_X;
    case REC_KEY_Y:
        return ImGuiKey_Y;
    case REC_KEY_Z:
        return ImGuiKey_Z;
    case REC_KEY_F1:
        return ImGuiKey_F1;
    case REC_KEY_F2:
        return ImGuiKey_F2;
    case REC_KEY_F3:
        return ImGuiKey_F3;
    case REC_KEY_F4:
        return ImGuiKey_F4;
    case REC_KEY_F5:
        return ImGuiKey_F5;
    case REC_KEY_F6:
        return ImGuiKey_F6;
    case REC_KEY_F7:
        return ImGuiKey_F7;
    case REC_KEY_F8:
        return ImGuiKey_F8;
    case REC_KEY_F9:
        return ImGuiKey_F9;
    case REC_KEY_F10:
        return ImGuiKey_F10;
    case REC_KEY_F11:
        return ImGuiKey_F11;
    case REC_KEY_F12:
        return ImGuiKey_F12;
    default:
        return ImGuiKey_None;
    }
}
#endif