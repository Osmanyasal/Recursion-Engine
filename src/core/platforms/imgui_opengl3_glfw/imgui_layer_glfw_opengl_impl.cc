
#include <imgui_layer_glfw_opengl_impl.hh>

namespace Recursion::core::window
{
    void ImguiLayer_glfw_opengl_impl::on_attach()
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO &io = ImGui::GetIO();

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows
        io.ConfigFlags |= ImGuiWindowFlags_AlwaysAutoResize;
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;
        //  Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_window, false); // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
        ImGui_ImplOpenGL3_Init(CONF__REC__GLFW_GL_VERSION);

        float xscale, yscale;
        glfwGetWindowContentScale(m_window, &xscale, &yscale);
        io.Fonts->Clear();
        io.Fonts->AddFontFromFileTTF("lib/fonts/font_opensans/fonts/ttf/OpenSans-Regular.ttf", xscale * 16.0f);
        io.Fonts->Build();
        ImGui_ImplOpenGL3_DestroyFontsTexture();
        ImGui_ImplOpenGL3_CreateFontsTexture();
        ImGui::GetStyle().ScaleAllSizes(xscale);

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        set_dark_theme_colors();
    }

    void ImguiLayer_glfw_opengl_impl::on_detach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImguiLayer_glfw_opengl_impl::begin_loop()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
    }
    void ImguiLayer_glfw_opengl_impl::end_loop()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ImGuiIO &io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void ImguiLayer_glfw_opengl_impl::on_update(double delta_time) {}

    void ImguiLayer_glfw_opengl_impl::on_event(events::Event &event)
    {
        REC_CORE_INFO("imgui::on_event executed for {}", event.to_string());
        switch (event.get_event_type())
        {
        case events::EventType::WindowFocus:
            on_window_focus_call_back((events::WindowFocusEvent &)event);
            break;

        case events::EventType::WindowLostFocus:
            on_window_lost_focus_call_back((events::WindowLostFocusEvent &)event);
            break;

        case events::EventType::MouseMoved:
            on_cursor_pos_call_back((events::MouseMovedEvent &)event);
            break;

        case events::EventType::MouseButtonPressed:
            on_mouse_button_pressed_call_back((events::MouseButtonPressed &)event);
            break;

        case events::EventType::MouseButtonReleased:
            on_mouse_button_released_call_back((events::MouseButtonReleased &)event);
            break;

        case events::EventType::MouseScrolled:
            on_scroll_call_back((events::MouseScrolledEvent &)event);
            break;

        case events::EventType::KeyPressed:
            on_key_pressed_call_back((events::KeyPressEvent &)event);
            break;

        case events::EventType::KeyReleased:
            on_key_released_call_back((events::KeyReleasedEvent &)event);
            break;

        case events::EventType::CharEvent:
            on_key_char_call_back((events::CharTypedEvent &)event);
            break;

        case events::EventType::WindowClose:
            on_monitor_close_call_back((events::WindowCloseEvent &)event);
            break;

        case events::EventType::WindowResize:
            on_monitor_resized_call_back((events::WindowResizedEvent &)event);
            break;

        case events::EventType::WindowMoved:
            on_monitor_moved_call_back((events::WindowMovedEvent &)event);
            break;

        default:
            break;
        }
    }

    // GLFW _call_backs (individual _call_backs to call yourself if you didn't install _call_backs)
    bool ImguiLayer_glfw_opengl_impl::on_window_focus_call_back(events::WindowFocusEvent &event)
    {
        REC_CORE_ERROR("on_window_focus_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.AddFocusEvent(true);
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_window_lost_focus_call_back(events::WindowLostFocusEvent &event)
    {
        REC_CORE_ERROR("on_window_focus_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.AddFocusEvent(false);
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_cursor_pos_call_back(events::MouseMovedEvent &event)
    {
        REC_CORE_ERROR("on_cursor_pos_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = ImVec2((float)event.get_posx(), (float)event.get_posy());
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_mouse_button_pressed_call_back(events::MouseButtonPressed &event)
    {
        REC_CORE_ERROR("on_mouse_button_pressed_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[((events::MouseButtonPressed &)event).get_mouse_button()] = true;
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_mouse_button_released_call_back(events::MouseButtonReleased &event)
    {
        REC_CORE_ERROR("on_mouse_button_released_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[((events::MouseButtonPressed &)event).get_mouse_button()] = false;
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_scroll_call_back(events::MouseScrolledEvent &event)
    {
        REC_CORE_ERROR("on_scroll_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheelH += event.get_offset_x();
        io.MouseWheel += event.get_offset_y();
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_key_pressed_call_back(events::KeyPressEvent &event)
    {
        REC_CORE_ERROR("on_key_pressed_call_back");
        ImGuiIO &io = ImGui::GetIO();
        ImGuiKey imgui_key = ImGui_ImplREC_KeyToImGuiKey(event.get_keycode());
        io.AddKeyEvent(imgui_key, 1);

        // unsigned int key_code = event.get_keycode();
        // if (key_code > 0 && key_code < 0x10000)
        //     io.AddInputCharacter(key_code);

        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_key_released_call_back(events::KeyReleasedEvent &event)
    {
        REC_CORE_ERROR("on_key_released_call_back");
        ImGuiIO &io = ImGui::GetIO();
        ImGuiKey imgui_key = ImGui_ImplREC_KeyToImGuiKey(event.get_keycode());
        io.AddKeyEvent(imgui_key, 0);

        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_key_char_call_back(events::CharTypedEvent &event)
    {
        REC_CORE_ERROR(" !!!!!!!!!!!!!!!!!!!!!!!!!!!!! on_key_char_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.AddInputCharacter(event.get_keycode());
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_close_call_back(events::WindowCloseEvent &event)
    {
        REC_CORE_ERROR("on_monitor_close_call_back");
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_resized_call_back(events::WindowResizedEvent &event)
    {
        REC_CORE_ERROR("on_monitor_resized_call_back");
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.get_width(), event.get_height());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, event.get_width(), event.get_height());
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_moved_call_back(events::WindowMovedEvent &event)
    {
        REC_CORE_ERROR("on_monitor_moved_call_back");
        return false;
    }

    void ImguiLayer_glfw_opengl_impl::set_dark_theme_colors()
    {
        auto &colors = ImGui::GetStyle().Colors;
        colors[ImGuiCol_WindowBg] = ImVec4{0.1f, 0.105f, 0.11f, 1.0f};

        // Headers
        colors[ImGuiCol_Header] = ImVec4{0.2f, 0.205f, 0.21f, 1.0f};
        colors[ImGuiCol_HeaderHovered] = ImVec4{0.3f, 0.305f, 0.31f, 1.0f};
        colors[ImGuiCol_HeaderActive] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};

        // Buttons
        colors[ImGuiCol_Button] = ImVec4{0.2f, 0.205f, 0.21f, 1.0f};
        colors[ImGuiCol_ButtonHovered] = ImVec4{0.3f, 0.305f, 0.31f, 1.0f};
        colors[ImGuiCol_ButtonActive] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};

        // Frame BG
        colors[ImGuiCol_FrameBg] = ImVec4{0.2f, 0.205f, 0.21f, 1.0f};
        colors[ImGuiCol_FrameBgHovered] = ImVec4{0.3f, 0.305f, 0.31f, 1.0f};
        colors[ImGuiCol_FrameBgActive] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};

        // Tabs
        colors[ImGuiCol_Tab] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};
        colors[ImGuiCol_TabHovered] = ImVec4{0.38f, 0.3805f, 0.381f, 1.0f};
        colors[ImGuiCol_TabActive] = ImVec4{0.28f, 0.2805f, 0.281f, 1.0f};
        colors[ImGuiCol_TabUnfocused] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4{0.2f, 0.205f, 0.21f, 1.0f};

        // Title
        colors[ImGuiCol_TitleBg] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};
        colors[ImGuiCol_TitleBgActive] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4{0.15f, 0.1505f, 0.151f, 1.0f};
    }
}
