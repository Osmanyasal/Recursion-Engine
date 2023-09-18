#ifndef RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH

#define IMGUI_DEFINE_MATH_OPERATORS

#include <utils.hh>
#include <gui_config.hh>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <window.hh>
#include <core_layers.hh>
#include <rec_imgui_key_mapping.hh>
#include <opengl_frame_buffer.hh>
#include <opengl_texture.hh>

namespace Recursion::platforms::imgui::window
{

    class ImguiLayer_glfw_opengl_impl : public core::layer::Layer
    {
    public:
        ImguiLayer_glfw_opengl_impl(GLFWwindow *gl_window, opengl::render::OpenGLFrameBuffer *fb)
            : core::layer::Layer{"imgui_layer"}, m_window{gl_window}, fb{fb}
        {
            on_attach();
        }
        ~ImguiLayer_glfw_opengl_impl() { on_detach(); }

        void on_attach() override;
        void on_detach() override;
        void on_update(float delta_time) override;
        void on_event(core::events::Event &event) override;

        void begin_loop();
        void end_loop();
        void set_dark_theme_colors();
        void set_white_theme_colors();

    private:
        // GLFW _call_backs (individual _call_backs to call yourself if you didn't install _call_backs)
        bool on_window_focus_call_back(core::events::WindowFocusEvent &event);
        bool on_window_lost_focus_call_back(core::events::WindowLostFocusEvent &event);
        bool on_cursor_pos_call_back(core::events::MouseMovedEvent &event);
        bool on_mouse_button_pressed_call_back(core::events::MouseButtonPressed &event);
        bool on_mouse_button_released_call_back(core::events::MouseButtonReleased &event);
        bool on_scroll_call_back(core::events::MouseScrolledEvent &event);
        bool on_key_pressed_call_back(core::events::KeyPressEvent &event);
        bool on_key_released_call_back(core::events::KeyReleasedEvent &event);
        bool on_key_char_call_back(core::events::CharTypedEvent &event);
        bool on_monitor_close_call_back(core::events::WindowCloseEvent &event);
        bool on_monitor_resized_call_back(core::events::WindowResizedEvent &event);
        bool on_monitor_moved_call_back(core::events::WindowMovedEvent &event);

        void create_default_layout(uint32_t layout_id = 0);
        uint32_t create_dockspace();
        void create_menu();
        void create_menu_icon();
        void create_menu_file();
        void create_menu_edit();
        void create_menu_window();
        void create_menu_tools();
        void create_menu_build();
        void create_menu_select();
        void create_menu_actor();
        void create_menu_help();

    private:
        GLFWwindow *m_window;
        opengl::render::OpenGLFrameBuffer *fb;
    };

    struct ExampleAppLog
    {
        ImGuiTextBuffer Buf;
        ImGuiTextFilter Filter;
        ImVector<int> LineOffsets; // Index to lines offset
        bool ScrollToBottom;

        void Clear() { Buf.clear(); }

        void AddLog(const char *fmt, ...) IM_FMTARGS(2)
        {
            int old_size = Buf.size();
            va_list args;
            va_start(args, fmt);
            Buf.appendfv(fmt, args);
            va_end(args);
            for (int new_size = Buf.size(); old_size < new_size; old_size++)
                if (Buf[old_size] == '\n')
                    LineOffsets.push_back(old_size);
            ScrollToBottom = true;
        }

        void Draw()
        {
            if (ImGui::Button("Clear"))
                Clear();
            ImGui::SameLine();
            bool copy = ImGui::Button("Copy");
            ImGui::SameLine();
            Filter.Draw("Filter", -100.0f);
            ImGui::Separator();
            ImGui::BeginChild("scrolling");
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 1));
            if (copy)
                ImGui::LogToClipboard();

            if (Filter.IsActive())
            {
                const char *buf_begin = Buf.begin();
                const char *line = buf_begin;
                for (int line_no = 0; line != NULL; line_no++)
                {
                    const char *line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
                    if (Filter.PassFilter(line, line_end))
                        ImGui::TextUnformatted(line, line_end);
                    line = line_end && line_end[1] ? line_end + 1 : NULL;
                }
            }
            else
            {
                ImGui::TextUnformatted(Buf.begin());
            }

            if (ScrollToBottom)
                ImGui::SetScrollHereY(1.0f);
            ScrollToBottom = false;
            ImGui::PopStyleVar();
            ImGui::EndChild();
        }
    };
} // namespace Recursion::core::window

#endif