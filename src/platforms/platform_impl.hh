#ifndef RECURSION_ENGINE__SRC__PLATFORMS__PLATOFORM_IMPL_HH
#define RECURSION_ENGINE__SRC__PLATFORMS__PLATOFORM_IMPL_HH

#include <platforms_gui.hh>
#include <platforms_linux.hh>
#include <platforms_opengl.hh>

namespace platforms = Recursion::platforms;
using platforms::opengl::render::OpenGLFrameBuffer;

#if defined(__render_api__) && __render_api__ == 1 // opengl @see linux_config.hh
using shapes = Recursion::platforms::opengl::scene::OpenGLShapes;
using shader = Recursion::platforms::opengl::render::OpenGLShader;
#endif

#endif