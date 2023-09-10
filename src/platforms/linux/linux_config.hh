#ifndef RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_CONFIG_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__LINUX__LINUX_CONFIG_HH


// DETECT PLATFORM AND CREATE A WINDOW BASED ON IT
#if defined(_WIN32)
#define CONF__OS_NAME "Windows"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME)
#elif defined(__linux__)
#define CONF__OS_NAME "Linux"
#define CREATE_WINDOW()                                  \
    Recursion::core::window::WindowProps default_props;  \
    default_props.engine_callback_func = &core_on_event; \
    window = new Recursion::platforms::linux::window::LinuxWindow{new Recursion::platforms::opengl::render::OpenGLRenderContext{default_props}};
#elif defined(__APPLE__) && defined(__MACH__)
#define CONF__OS_NAME "macOS"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME) 
#else
#define CONF__OS_NAME "Unknown"
#define CREATE_WINDOW() REC_CORE_ERROR("NO WINDOW DEFINED FOR {}", CONF__OS_NAME)
#endif

 
#endif