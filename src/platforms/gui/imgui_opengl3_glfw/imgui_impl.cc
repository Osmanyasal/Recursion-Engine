
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
        ImGui::ShowDemoWindow();
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
        // TODO: apply white theme colors
    }

    void ImguiLayer_glfw_opengl_impl::create_default_layout(uint32_t layout_id)
    {
        uint32_t dockspace_id = create_dockspace();
        create_menu();
        
        // Retrieve the dockspace's node ID
        ImGuiDockNode *dockspace_node_id = ImGui::DockBuilderGetCentralNode(dockspace_id);
        if (dockspace_node_id->ID)
        {
            // Dock a new window within the dockspace
            ImGui::DockBuilderDockWindow("Scene", dockspace_node_id->ID);
        }
        // Begin your window
        if (ImGui::Begin("Scene"))
        {

            const float window_width = ImGui::GetContentRegionAvail().x;
            const float window_height = ImGui::GetContentRegionAvail().y;

            fb->rescale_framebuffer(window_width, window_height);
            glViewport(0, 0, window_width, window_height);

            ImVec2 pos = ImGui::GetCursorScreenPos();
            ImGui::GetWindowDrawList()->AddImage(
                (void *)fb->texture.meta.texture_id,
                ImVec2(pos.x, pos.y),
                ImVec2(pos.x + window_width, pos.y + window_height),
                ImVec2(0, 1),
                ImVec2(1, 0));

            ImGui::End();
        }
    }
    uint32_t ImguiLayer_glfw_opengl_impl::create_dockspace()
    {
        uint32_t dockspace_id = ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        return dockspace_id;
    }
    void ImguiLayer_glfw_opengl_impl::create_menu()
    {
        if (ImGui::BeginMainMenuBar())
        {
            create_menu_file();
            create_menu_edit();
            create_menu_window();
            create_menu_tools();
            create_menu_build();
            create_menu_select();
            create_menu_actor();
            create_menu_help();
            create_submenu();
            create_log_window();

            ImGui::EndMainMenuBar();
        }
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

    void ImguiLayer_glfw_opengl_impl::create_submenu()
    {
    }

    void ImguiLayer_glfw_opengl_impl::create_log_window()
    {
    }

    void ImguiLayer_glfw_opengl_impl::create_env_window()
    {
    }
}
