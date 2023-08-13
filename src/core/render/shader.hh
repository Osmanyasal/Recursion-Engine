#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__SHADER_HH

#include <utils.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <bindable.hh>
#include <unordered_map>

namespace Recursion::core::render
{
    class Shader : public Bindable
    {
    public:
        Shader() {}
        virtual ~Shader() {}

    protected:
        uint32_t program_id;
        mutable std::unordered_map<std::string,int32_t> uniform_cache;

    protected:
        virtual void read_and_bind_shader(uint32_t &shader, std::string location) = 0;

        // UNIFORM SETTERS
        virtual void set_uniform1f(const std::string& name, float v0) const = 0;
        virtual void set_uniform2f(const std::string& name, float v0, float v1) const = 0;
        virtual void set_uniform3f(const std::string& name, float v0, float v1, float v2) const = 0;
        virtual void set_uniform4f(const std::string& name, float v0, float v1, float v2, float v3) const = 0;
        virtual void set_uniform1i(const std::string& name, int32_t v0) const = 0;
        virtual void set_uniform2i(const std::string& name, int32_t v0, int32_t v1) const = 0;
        virtual void set_uniform3i(const std::string& name, int32_t v0, int32_t v1, int32_t v2) const = 0;
        virtual void set_uniform4i(const std::string& name, int32_t v0, int32_t v1, int32_t v2, int32_t v3) const = 0;
        virtual void set_uniform1ui(const std::string& name, uint32_t v0) const = 0;
        virtual void set_uniform2ui(const std::string& name, uint32_t v0, uint32_t v1) const = 0;
        virtual void set_uniform3ui(const std::string& name, uint32_t v0, uint32_t v1, uint32_t v2) const = 0;
        virtual void set_uniform4ui(const std::string& name, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) const = 0;
        virtual void set_uniform1fv(const std::string& name, uint32_t count, const float *value) const = 0;
        virtual void set_uniform2fv(const std::string& name, uint32_t count, const float *value) const = 0;
        virtual void set_uniform3fv(const std::string& name, uint32_t count, const float *value) const = 0;
        virtual void set_uniform4fv(const std::string& name, uint32_t count, const float *value) const = 0;
        virtual void set_uniform1iv(const std::string& name, uint32_t count, const int32_t *value) const = 0;
        virtual void set_uniform2iv(const std::string& name, uint32_t count, const int32_t *value) const = 0;
        virtual void set_uniform3iv(const std::string& name, uint32_t count, const int32_t *value) const = 0;
        virtual void set_uniform4iv(const std::string& name, uint32_t count, const int32_t *value) const = 0;
        virtual void set_uniform1uiv(const std::string& name, uint32_t count, const uint32_t *value) const = 0;
        virtual void set_uniform2uiv(const std::string& name, uint32_t count, const uint32_t *value) const = 0;
        virtual void set_uniform3uiv(const std::string& name, uint32_t count, const uint32_t *value) const = 0;
        virtual void set_uniform4uiv(const std::string& name, uint32_t count, const uint32_t *value) const = 0;
        virtual void set_uniformMatrix2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix2x3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix3x2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix2x4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix4x2fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix3x4fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
        virtual void set_uniformMatrix4x3fv(const std::string& name, uint32_t count, GLboolean transpose, const float *value) const = 0;
    };

} // namespace Recursion::core::render

#endif