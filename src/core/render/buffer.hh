#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__BUFFER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__BUFFER_HH

#include <bindable.hh>

namespace Recursion::core::render
{
    class Buffer : public Bindable
    {
    public:
        Buffer() {}
        virtual ~Buffer() {}
    };

    class BufferLayout
    {
    public:
        BufferLayout() {}
        virtual ~BufferLayout() {}
    };

} // namespace Recursion::core::render

#endif