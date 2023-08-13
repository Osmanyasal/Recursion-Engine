#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_SHADER_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_SHADER_HH

#include <window.hh>
#include <render_context.hh>
#include <shader.hh>
#include <algorithm>
namespace Recursion::opengl::render
{
    class OpenGLShader : core::render::Shader
    {
    public:
        OpenGLShader();
        OpenGLShader(std::string vs_location, std::string fs_location);
        virtual ~OpenGLShader();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;
        virtual void read_and_bind_shader(uint32_t &shader, std::string location) override;

        virtual void set_uniform1f(const std::string& name, float v0) const override;
        virtual void set_uniform2f(const std::string& name, float v0, float v1) const override;
        virtual void set_uniform3f(const std::string& name, float v0, float v1, float v2) const override;
        virtual void set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3) const override;
        virtual void set_uniform1i(const std::string& name, int32_t v0) const override;
        virtual void set_uniform2i(const std::string& name, int32_t v0, int32_t v1) const override;
        virtual void set_uniform3i(const std::string& name, int32_t v0, int32_t v1, int32_t v2) const override;
        virtual void set_uniform4i(const std::string& name, int32_t v0, int32_t v1, int32_t v2, int32_t v3) const override;
        virtual void set_uniform1ui(const std::string& name, uint32_t v0) const override;
        virtual void set_uniform2ui(const std::string& name, uint32_t v0, uint32_t v1) const override;
        virtual void set_uniform3ui(const std::string& name, uint32_t v0, uint32_t v1, uint32_t v2) const override;
        virtual void set_uniform4ui(const std::string& name, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) const override;
        virtual void set_uniform1fv(const std::string& name, uint32_t count, const float *value) const override;
        virtual void set_uniform2fv(const std::string& name, uint32_t count, const float *value) const override;
        virtual void set_uniform3fv(const std::string& name, uint32_t count, const float *value) const override;
        virtual void set_uniform4fv(const std::string& name, uint32_t count, const float *value) const override;
        virtual void set_uniform1iv(const std::string& name, uint32_t count, const int32_t *value) const override;
        virtual void set_uniform2iv(const std::string& name, uint32_t count, const int32_t *value) const override;
        virtual void set_uniform3iv(const std::string& name, uint32_t count, const int32_t *value) const override;
        virtual void set_uniform4iv(const std::string& name, uint32_t count, const int32_t *value) const override;
        virtual void set_uniform1uiv(const std::string& name, uint32_t count, const uint32_t *value) const override;
        virtual void set_uniform2uiv(const std::string& name, uint32_t count, const uint32_t *value) const override;
        virtual void set_uniform3uiv(const std::string& name, uint32_t count, const uint32_t *value) const override;
        virtual void set_uniform4uiv(const std::string& name, uint32_t count, const uint32_t *value) const override;
        virtual void set_uniformMatrix2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix2x3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix3x2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix2x4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix4x2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix3x4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        virtual void set_uniformMatrix4x3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const override;
        int32_t projection_loc;
    };

} // namespace Recursion::core::render

#endif