#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__BUFFER_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__BUFFER_HH

#include <bindable.hh>
#include <iostream>

namespace Recursion::core::render
{
    class Buffer : public Bindable
    {
    public:
        Buffer() {}
        virtual ~Buffer() {}
    };


    // MUST BE EXTENDED TO OTHER PLATFORMS
    class BufferLayout
    {
    public:
        BufferLayout() {}
        virtual ~BufferLayout() {}
    };

} // namespace Recursion::core::render

#endif