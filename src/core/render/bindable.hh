#ifndef RECURSION_ENGINE__SRC__CORE__RENDER__BINDABLE_HH
#define RECURSION_ENGINE__SRC__CORE__RENDER__BINDABLE_HH

namespace Recursion::core
{
    class Bindable
    {
    public:
        Bindable(){}
        virtual ~Bindable(){}
        
        virtual void bind() = 0;
        virtual void unbind() = 0;
    };

} // namespace Recursion::core

#endif