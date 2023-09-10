#ifndef RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_BUFFER_LAYOUT_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_BUFFER_LAYOUT_HH

#include <buffer.hh>

namespace Recursion::platforms::opengl::render
{
    class OpenGLBufferLayout : public core::render::BufferLayout
    {
    public:
        enum class Type
        {
            Float = GL_FLOAT,
            Mat = GL_FLOAT,
            Int = GL_INT,
            Bool = GL_BOOL,
        };

        inline static int32_t get_type_size(Type type)
        {
            switch (type)
            {
            case Type::Float:
                return sizeof(float);
                break;
            case Type::Int:
                return sizeof(int32_t);
                break;
            case Type::Bool:
                return sizeof(bool);
                break;
            default:
                return 0;
                break;
            }
        }

        enum class Quantity
        {
            Float = 1,
            Float2 = 2,
            Float3 = 3,
            Float4 = 4,
            Mat3 = 1,
            Mat4 = 1,
            Int = 1,
            Int2 = 2,
            Int3 = 3,
            Int4 = 4,
            Bool = 1,
        };

        enum class Normalized
        {
            TRUE = GL_TRUE,
            FALSE = GL_FALSE
        };

        struct BufferInfo
        {
            std::string name;
            int32_t attrib_array;
            Type type;
            Quantity quantity;
            int32_t repeat;
            Normalized normalized;
        };

        OpenGLBufferLayout(const BufferInfo &buffer_info)
            : buffer_info(buffer_info) {}

        OpenGLBufferLayout(std::string name,
                           int32_t attrib_array,
                           Quantity quantity,
                           int32_t repeat,
                           Type type,
                           Normalized normalized)
            : buffer_info({name, attrib_array, type, quantity,repeat, normalized}) {}

        virtual ~OpenGLBufferLayout() {}

    public:
        const BufferInfo buffer_info;
    };

    using Type = OpenGLBufferLayout::Type;
    using Quantity = OpenGLBufferLayout::Quantity;
    using Normalized = OpenGLBufferLayout::Normalized;

} // namespace Recursion::opengl::render

#endif