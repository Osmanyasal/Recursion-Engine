#ifndef RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_FACTORY_HH
#define RECURSION_ENGINE__SRC__CORE__EVENTS__INPUT_FACTORY_HH

#include <Input.hh>
#include <logger.hh>
#include <glfw_opengl_Input.hh>
#include <render_api.hh>

namespace Recursion::core::input
{
    class InputFactory
    {
    public:
        inline static BaseInput &create(core::render::RenderAPI render_api, void *window)
        {
            switch (render_api)
            {
            case core::render::RenderAPI::OPENGL:
                REC_CORE_INFO("Input for GLFW/OpenGL context created!");
                static platforms::imgui::window::Glfw_OpenGL_Input glfw_opengl_input{(GLFWwindow *)window};
                return glfw_opengl_input;
                break;
            case core::render::RenderAPI::VULKAN:
                REC_CORE_INFO("Input for GLFW/Vulkan context created!");
                static platforms::imgui::window::Glfw_OpenGL_Input glfw_vulkan_input{(GLFWwindow *)window};
                return glfw_vulkan_input;
                break;
            case core::render::RenderAPI::D3D:
                REC_CORE_INFO("Input for ???????? context created!");
                static platforms::imgui::window::Glfw_OpenGL_Input glfw_d3d_input{(GLFWwindow *)window};
                return glfw_d3d_input;
                break;

            default:
                return glfw_opengl_input;
                break;
            }
        }

    private:
        InputFactory();
        ~InputFactory();
    };
} // namespace Recursion::core::input

#endif