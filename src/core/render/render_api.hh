#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_API_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__RENDERING_API_HH

namespace Recursion::core::render
{
    enum class RenderAPI
    {
        NONE,
        OPENGL,
        VULKAN,
        D3D
    };

} // namespace Recursion::core::render
#endif