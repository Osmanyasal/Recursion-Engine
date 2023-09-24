#ifndef RECURSION_ENGINE__SRC__CORE__CORE_MODULES_HH
#define RECURSION_ENGINE__SRC__CORE__CORE_MODULES_HH

#include <core_events.hh>
#include <core_layers.hh>
#include <core_render.hh>
#include <core_scene.hh>
#include <window.hh>

namespace core = Recursion::core;
namespace events = core::events;

using core::scene::Camera;
using core::scene::CameraController;
using core::scene::OrthographicCamera;
using core::scene::PerspectiveCamera;

using core::scene::Component;
using core::scene::GameObject;
using core::scene::TransformComponent;

using core::input::Input;
 

#endif
