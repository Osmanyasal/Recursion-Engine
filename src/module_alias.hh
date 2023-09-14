#ifndef RECURSION_ENGINE__SRC__CORE__ALIAS_HH
#define RECURSION_ENGINE__SRC__CORE__ALIAS_HH

#include <app_config.hh>
#include <core_modules.hh>
#include <platform_impl.hh>
 
#if defined(RENDER_API) && RENDER_API == 1 // opengl @see linux_config.hh

    using shapes = platforms::opengl::scene::OpenGLShapes;
    
#endif

#endif