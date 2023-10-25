
#include <imgui_impl.hh>

namespace Recursion::platforms::imgui::window
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
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows
        // io.ConfigFlags |= ImGuiWindowFlags_AlwaysAutoResize;
        // io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleViewports;
        // io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
        // io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

        //  Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_window, false); // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
        ImGui_ImplOpenGL3_Init(CONF__REC__GLFW_GL_VERSION);

        float xscale, yscale;
        glfwGetWindowContentScale(m_window, &xscale, &yscale);
        io.Fonts->Clear();
        io.Fonts->AddFontFromFileTTF("./fonts/font_opensans/fonts/ttf/OpenSans-Regular.ttf", xscale * CONF__IDE__TEXT_SIZE);
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
        //set_white_theme_colors();
    }

    void ImguiLayer_glfw_opengl_impl::on_detach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImguiLayer_glfw_opengl_impl::begin_loop()
    {
        REC_CORE_PROFILE_FUNCTION();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        create_default_layout();
        // ImGui::ShowDemoWindow();
    }
    void ImguiLayer_glfw_opengl_impl::end_loop()
    {
        REC_CORE_PROFILE_FUNCTION();

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

    void ImguiLayer_glfw_opengl_impl::on_update(float delta_time) {}

    void ImguiLayer_glfw_opengl_impl::on_event(core::events::Event &event)
    {
        // REC_CORE_TRACE("imgui::on_event executed for {}", event.to_string());
        switch (event.get_event_type())
        {
        case core::events::EventType::WindowFocus:
            on_window_focus_call_back((core::events::WindowFocusEvent &)event);
            break;

        case core::events::EventType::WindowLostFocus:
            on_window_lost_focus_call_back((core::events::WindowLostFocusEvent &)event);
            break;

        case core::events::EventType::MouseMoved:
            on_cursor_pos_call_back((core::events::MouseMovedEvent &)event);
            break;

        case core::events::EventType::MouseButtonPressed:
            on_mouse_button_pressed_call_back((core::events::MouseButtonPressed &)event);
            break;

        case core::events::EventType::MouseButtonReleased:
            on_mouse_button_released_call_back((core::events::MouseButtonReleased &)event);
            break;

        case core::events::EventType::MouseScrolled:
            on_scroll_call_back((core::events::MouseScrolledEvent &)event);
            break;

        case core::events::EventType::KeyPressed:
            on_key_pressed_call_back((core::events::KeyPressEvent &)event);
            break;

        case core::events::EventType::KeyReleased:
            on_key_released_call_back((core::events::KeyReleasedEvent &)event);
            break;

        case core::events::EventType::CharEvent:
            on_key_char_call_back((core::events::CharTypedEvent &)event);
            break;

        case core::events::EventType::WindowClose:
            on_monitor_close_call_back((core::events::WindowCloseEvent &)event);
            break;

        case core::events::EventType::WindowResize:
            on_monitor_resized_call_back((core::events::WindowResizedEvent &)event);
            break;

        case core::events::EventType::WindowMoved:
            on_monitor_moved_call_back((core::events::WindowMovedEvent &)event);
            break;

        default:
            break;
        }
    }

    // GLFW _call_backs (individual _call_backs to call yourself if you didn't install _call_backs)
    bool ImguiLayer_glfw_opengl_impl::on_window_focus_call_back(core::events::WindowFocusEvent &event)
    {
        REC_CORE_DEBUG("on_window_focus_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.AddFocusEvent(true);
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_window_lost_focus_call_back(core::events::WindowLostFocusEvent &event)
    {
        REC_CORE_DEBUG("on_window_focus_lost_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.AddFocusEvent(false);
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_cursor_pos_call_back(core::events::MouseMovedEvent &event)
    {
        REC_CORE_DEBUG("on_cursor_pos_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.MousePos = ImVec2((float)event.get_posx(), (float)event.get_posy());
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_mouse_button_pressed_call_back(core::events::MouseButtonPressed &event)
    {
        REC_CORE_DEBUG("on_mouse_button_pressed_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[((core::events::MouseButtonPressed &)event).get_mouse_button()] = true;
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_mouse_button_released_call_back(core::events::MouseButtonReleased &event)
    {
        REC_CORE_DEBUG("on_mouse_button_released_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.MouseDown[((core::events::MouseButtonPressed &)event).get_mouse_button()] = false;
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_scroll_call_back(core::events::MouseScrolledEvent &event)
    {
        REC_CORE_DEBUG("on_scroll_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.MouseWheelH += event.get_offset_x();
        io.MouseWheel += event.get_offset_y();
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_key_pressed_call_back(core::events::KeyPressEvent &event)
    {
        REC_CORE_DEBUG("on_key_pressed_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        ImGuiKey imgui_key = KEYMAP_REC_TO_IMGUI(event.get_keycode());
        io.AddKeyEvent(imgui_key, 1);
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_key_released_call_back(core::events::KeyReleasedEvent &event)
    {
        REC_CORE_DEBUG("on_key_released_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        ImGuiKey imgui_key = KEYMAP_REC_TO_IMGUI(event.get_keycode());
        io.AddKeyEvent(imgui_key, 0);
        return false;
    }
    bool ImguiLayer_glfw_opengl_impl::on_key_char_call_back(core::events::CharTypedEvent &event)
    {
        REC_CORE_DEBUG("on_key_char_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.AddInputCharacter(event.get_keycode());
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_close_call_back(core::events::WindowCloseEvent &event)
    {
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_resized_call_back(core::events::WindowResizedEvent &event)
    {
        REC_CORE_DEBUG("on_monitor_resized_call_back {}", event.to_string());
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(event.get_width(), event.get_height());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, event.get_width(), event.get_height());
        return false;
    }

    bool ImguiLayer_glfw_opengl_impl::on_monitor_moved_call_back(core::events::WindowMovedEvent &event)
    {
        REC_CORE_DEBUG("on_monitor_moved_call_back {}", event.to_string());
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

    void ImguiLayer_glfw_opengl_impl::set_white_theme_colors()
    {
	ImGuiStyle *style = &ImGui::GetStyle();
        ImVec4 *colors = style->Colors; 

        //Headers
        colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);

        // Buttons
        colors[ImGuiCol_Button] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_ButtonActive] = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);

        // Frame BG
        colors[ImGuiCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        colors[ImGuiCol_FrameBgHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
        colors[ImGuiCol_FrameBgActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);

        // Tabs
        colors[ImGuiCol_Tab] = ImLerp(colors[ImGuiCol_Header], colors[ImGuiCol_TitleBgActive], 0.90f);
        colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
        colors[ImGuiCol_TabActive] = ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
        colors[ImGuiCol_TabUnfocused] = ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
        colors[ImGuiCol_TabUnfocusedActive] = ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);

        // Title
        colors[ImGuiCol_TitleBg] = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
        colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);

        // Rest
        colors[ImGuiCol_Text] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
        colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        colors[ImGuiCol_WindowBg] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
        colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.98f);
        colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
        colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
          
        colors[ImGuiCol_MenuBarBg] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.69f, 0.69f, 0.69f, 0.80f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.49f, 0.49f, 0.49f, 0.80f);
        colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
        colors[ImGuiCol_CheckMark] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        colors[ImGuiCol_SliderGrab] = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
        colors[ImGuiCol_SliderGrabActive] = ImVec4(0.46f, 0.54f, 0.80f, 0.60f); 
        
        colors[ImGuiCol_Separator] = ImVec4(0.39f, 0.39f, 0.39f, 0.62f);
        colors[ImGuiCol_SeparatorHovered] = ImVec4(0.14f, 0.44f, 0.80f, 0.78f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(0.14f, 0.44f, 0.80f, 1.00f);
        colors[ImGuiCol_ResizeGrip] = ImVec4(0.35f, 0.35f, 0.35f, 0.17f);
        colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        
        colors[ImGuiCol_DockingPreview] = colors[ImGuiCol_Header] * ImVec4(1.0f, 1.0f, 1.0f, 0.7f);
        colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
        colors[ImGuiCol_PlotLines] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
        colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.45f, 0.00f, 1.00f);
        colors[ImGuiCol_TableHeaderBg] = ImVec4(0.78f, 0.87f, 0.98f, 1.00f);
        colors[ImGuiCol_TableBorderStrong] = ImVec4(0.57f, 0.57f, 0.64f, 1.00f); // Prefer using Alpha=1.0 here
        colors[ImGuiCol_TableBorderLight] = ImVec4(0.68f, 0.68f, 0.74f, 1.00f);  // Prefer using Alpha=1.0 here
        colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        colors[ImGuiCol_TableRowBgAlt] = ImVec4(0.30f, 0.30f, 0.30f, 0.09f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
        colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);
        colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.20f);
        colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
    }

    void ImguiLayer_glfw_opengl_impl::create_default_layout(uint32_t layout_id)
    {
        uint32_t dockspace_id = create_dockspace();
        static ImGuiDockNode *dockspace_node_id = ImGui::DockBuilderGetCentralNode(dockspace_id);
        create_menu();

        static bool sFirstFrame = true;
        if (sFirstFrame)
        {
            sFirstFrame = false;
            ImGuiID toolbar_node_id;
            ImGuiID scene_node_id;
            ImGuiID inspector_node_id;
            ImGuiID game_object_node_id;
            ImGuiID log_node_id;
            ImGui::DockBuilderSplitNode(dockspace_node_id->ID, ImGuiDir_Up, 0.05f, &toolbar_node_id, &scene_node_id);
            ImGui::DockBuilderSplitNode(scene_node_id, ImGuiDir_Right, 0.25f, &inspector_node_id, &scene_node_id);
            ImGui::DockBuilderSplitNode(scene_node_id, ImGuiDir_Down, 0.35f, &log_node_id, &scene_node_id);
            ImGui::DockBuilderSplitNode(scene_node_id, ImGuiDir_Left, 0.25f, &game_object_node_id, &scene_node_id);
            ImGui::DockBuilderDockWindow("##toolbar", toolbar_node_id);
            ImGui::DockBuilderDockWindow("Scene", scene_node_id);
            ImGui::DockBuilderDockWindow("Inspector Window", inspector_node_id);
            ImGui::DockBuilderDockWindow("Object Window", game_object_node_id);
            ImGui::DockBuilderDockWindow("Log Window", log_node_id);
            ImGui::DockBuilderDockWindow("Project Window", log_node_id);
            ImGui::DockBuilderFinish(dockspace_node_id->ID);

            ImGuiDockNode *toolbar_node = ImGui::DockBuilderGetNode(toolbar_node_id);
            toolbar_node->LocalFlags |= ImGuiDockNodeFlags_NoTabBar | ImGuiDockNodeFlags_NoSplit | ImGuiDockNodeFlags_NoResize;
        }

        if (ImGui::Begin("##toolbar", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_Tooltip | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize))
        {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 1));
            ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(0, 0));
            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
            auto &colors = ImGui::GetStyle().Colors;
            const auto &buttonHovered = colors[ImGuiCol_ButtonHovered];
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(buttonHovered.x, buttonHovered.y, buttonHovered.z, 0.5f));
            const auto &buttonActive = colors[ImGuiCol_ButtonActive];
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(buttonActive.x, buttonActive.y, buttonActive.z, 0.5f));
            ImVec4 tintColor = ImVec4(1, 1, 1, 1);
            static float size = ImGui::GetContentRegionAvail().y * 1.25;

            static opengl::render::OpenGLTexture hand_btn{"../icon/editor/hand.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)hand_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture drag_btn{"../icon/editor/drag.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)drag_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture rotate_btn{"../icon/editor/rotate.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)rotate_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();

            auto button_count = 5.8f;
            ImGui::SetCursorPosX((ImGui::GetMainViewport()->Size.x * 0.5f) - (size * button_count / 2.0f));
            static opengl::render::OpenGLTexture left_step{"../icon/editor/left_step.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)left_step.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture pause_btn{"../icon/editor/pause.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)pause_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture play_btn{"../icon/editor/play.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)play_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture stop_btn{"../icon/editor/stop.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)stop_btn.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }
            ImGui::SameLine();
            static opengl::render::OpenGLTexture right_step{"../icon/editor/right_step.png"};
            if (ImGui::ImageButton((ImTextureID)(uint64_t)right_step.meta.texture_id, ImVec2(size, size), ImVec2(0, 1), ImVec2(1, 0), 0, ImVec4(0.0f, 0.0f, 0.0f, 0.0f), tintColor))
            {
            }

            ImGui::PopStyleVar(2);
            ImGui::PopStyleColor(3);
        }
        ImGui::End();

        // Start the "Scene" window
        if (ImGui::Begin("Scene"))
        {
            const float window_width = ImGui::GetMainViewport()->Size.x; //  ImGui::GetContentRegionAvail() for current small window
            const float window_height = ImGui::GetMainViewport()->Size.y;

            fb->rescale_framebuffer(window_width, window_height);
            glViewport(0, 0, window_width, window_height);

            ImVec2 pos = ImGui::GetCursorScreenPos();
            ImGui::GetWindowDrawList()->AddImage(
                (void *)fb->texture.meta.texture_id,
                ImVec2(pos.x, pos.y),
                ImVec2(pos.x + window_width, pos.y + window_height),
                ImVec2(0, 1),
                ImVec2(1, 0));
        }
        ImGui::End();

        // Start the "Right Window"
        if (ImGui::Begin("Inspector Window"))
        {
            ImGui::Text("Inspector comes here!");
        }
        ImGui::End();

        if (ImGui::Begin("Object Window"))
        {
            ImGui::Text("Objects comes here!");
        }
        ImGui::End();

        if (ImGui::Begin("Project Window"))
        {
        }
        ImGui::End();

        if (ImGui::Begin("Log Window"))
        {
            // TODO: Move this to spdlog.
            ImGuiLogger::Draw();
        }
        ImGui::End();
    }

    uint32_t ImguiLayer_glfw_opengl_impl::create_dockspace()
    {
        uint32_t dockspace_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        return dockspace_id;
    }
    void ImguiLayer_glfw_opengl_impl::create_menu()
    {
        static float original_padding = ImGui::GetStyle().FramePadding.y;
        ImGui::GetStyle().FramePadding.y = 30;
        if (ImGui::BeginMainMenuBar())
        {
            create_menu_icon();
            create_menu_file();
            create_menu_edit();
            create_menu_window();
            create_menu_tools();
            create_menu_build();
            create_menu_select();
            create_menu_actor();
            create_menu_help();
            ImGui::EndMainMenuBar();
        }
        ImGui::GetStyle().FramePadding.y = original_padding;
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_icon()
    {
        static opengl::render::OpenGLTexture icon{"../icon/icon.png"};
        static ImVec2 imageSize(82, 82);
        ImGui::Image((void *)icon.meta.texture_id, imageSize, ImVec2(0, 1), ImVec2(1, 0));
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_file()
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::SeparatorText("Open");
            if (ImGui::MenuItem("New Level", "CTRL+N", false))
            {
            }
            if (ImGui::MenuItem("Open Level", "CTRL+O", false))
            {
            }
            if (ImGui::MenuItem("Open Asset", "CTRL+P", false))
            {
            }

            ImGui::SeparatorText("Save");
            if (ImGui::MenuItem("Save Current Level", "CTRL+S", false))
            {
            }
            if (ImGui::MenuItem("Save Current Level As...", "CTRL+ALT+S", false))
            {
            }
            if (ImGui::MenuItem("Save All", "CTRL+SHIFT+S", false))
            {
            }

            ImGui::SeparatorText("Import/Export");
            if (ImGui::MenuItem("Import Into Level", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Export All...", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Export Selected", nullptr, false))
            {
            }

            ImGui::SeparatorText("Project");
            if (ImGui::MenuItem("New Project", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Open Project...", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Zip Project", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Recent Projects", nullptr, false))
            {
            }

            ImGui::SeparatorText("Exit");
            if (ImGui::MenuItem("Exit", nullptr, false))
            {
                exit(0);
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_edit()
    {
        if (ImGui::BeginMenu("Edit"))
        {
            ImGui::SeparatorText("History");
            if (ImGui::MenuItem("Undo", "CTRL+Z", false))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+SHIFT+Z", false))
            {
            }

            ImGui::SeparatorText("Edit");
            if (ImGui::MenuItem("Cut", "CTRL+X", false))
            {
            }
            if (ImGui::MenuItem("Copy", "CTRL+C", false))
            {
            }
            if (ImGui::MenuItem("Paste", "CTRL+V", false))
            {
            }
            if (ImGui::MenuItem("Duplicate", "CTRL+D", false))
            {
            }
            if (ImGui::MenuItem("Delete", "DELETE", false))
            {
            }

            ImGui::SeparatorText("Configuration");
            if (ImGui::MenuItem("Editor Preferences", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Project Settings", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Plugins", nullptr, false))
            {
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_window()
    {
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::SeparatorText("History");
            if (ImGui::MenuItem("Undo", "CTRL+Z", false))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+SHIFT+Z", false))
            {
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_tools()
    {
        if (ImGui::BeginMenu("Tools"))
        {
            ImGui::SeparatorText("PROGRAMMING");
            if (ImGui::MenuItem("New C++ Class...", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Refresh VSCode Project", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Open VSCode", nullptr, false))
            {
            }

            ImGui::SeparatorText("TOOLS");
            if (ImGui::MenuItem("Cache Statistics", nullptr, false))
            {
            }
            if (ImGui::MenuItem("CSV to SVG", nullptr, false))
            {
            }

            ImGui::SeparatorText("INSTRUMENTATION");
            if (ImGui::BeginMenu("Debug"))
            {
                if (ImGui::MenuItem("Debug", nullptr, false))
                {
                }

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Profile"))
            {
                if (ImGui::MenuItem("Debug", nullptr, false))
                {
                }

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Audit"))
            {
                if (ImGui::MenuItem("Debug", nullptr, false))
                {
                }

                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Platforms"))
            {
                if (ImGui::MenuItem("Device Manager", nullptr, false))
                {
                }
                if (ImGui::MenuItem("Device Profiles", nullptr, false))
                {
                }
                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_build()
    {
        if (ImGui::BeginMenu("Build"))
        {
            ImGui::SeparatorText("History");
            if (ImGui::MenuItem("Undo", "CTRL+Z", false))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+SHIFT+Z", false))
            {
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_select()
    {
        if (ImGui::BeginMenu("Select"))
        {
            ImGui::SeparatorText("History");
            if (ImGui::MenuItem("Undo", "CTRL+Z", false))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+SHIFT+Z", false))
            {
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_actor()
    {
        if (ImGui::BeginMenu("Actor"))
        {
            ImGui::SeparatorText("Asset Options");
            if (ImGui::MenuItem("Browse To Asset", "CTRL+B", false))
            {
            }
            if (ImGui::MenuItem("Edit", "CTRL+E", false))
            {
            }

            if (ImGui::BeginMenu("Asset Tools"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Copy Selected Actor(s) File Path", nullptr, false))
            {
            }
            if (ImGui::MenuItem("Save Selected Actor(s)", nullptr, false))
            {
            }
            if (ImGui::BeginMenu("Place Actor"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Replace Selected Actor(s) with"))
            {
                ImGui::EndMenu();
            }

            ImGui::SeparatorText("Actor Options");
            if (ImGui::BeginMenu("Edit"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Visibility"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Transform"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Snapping"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Pivot"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Group"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Attach To"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Detach"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Add Event"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Jump To Event"))
            {
                ImGui::EndMenu();
            }

            ImGui::SeparatorText("UE TOOLS");
            if (ImGui::BeginMenu("Merge Actors"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Chaos"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Level"))
            {
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("UV Editor"))
            {
                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
    }

    void ImguiLayer_glfw_opengl_impl::create_menu_help()
    {
        if (ImGui::BeginMenu("Help"))
        {
            ImGui::SeparatorText("Search");
            if (ImGui::MenuItem("SearchBar", "CTRL+SPACE", false))
            {
            }

            ImGui::SeparatorText("Documentation");
            if (ImGui::MenuItem("Programmer", "F1", false))
            {
            }
            ImGui::EndMenu();
        }
    }

}
