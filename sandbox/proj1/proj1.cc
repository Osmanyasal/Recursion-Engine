#include <recursion.hh>
#include <proj1.hh>
#include <utils.hh>
#include <Input.hh>

#include <glm/vec3.hpp>                  // glm::vec3
#include <glm/vec4.hpp>                  // glm::vec4
#include <glm/mat4x4.hpp>                // glm::mat4
#include <glm/ext/matrix_transform.hpp>  // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp>  // glm::pi
#include <glm/gtx/string_cast.hpp>

glm::mat4 camera(float Translate, glm::vec2 const &Rotate)
{
    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
    glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
    View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
    return Projection * View * Model;
}

void Proj1::application()
{
    REC_INFO("hello from sandbox::proj1 ");
    if (Recursion::core::input::Input::is_key_pressed(REC_KEY_LEFT_CONTROL))
    {
        REC_CORE_ERROR("key CTRL is pressed !!");
    }
    if (Recursion::core::input::Input::is_mouse_button_pressed(REC_MOUSE_BUTTON_LEFT))
    {
        REC_CORE_ERROR("mouse button left is pressed !!");
    }
    REC_CORE_INFO("mat : {}",glm::to_string(glm::mat4(1.0f)));
    
    glm::mat4 cam = camera(5.0f,{.5f,.5f});
    REC_CORE_INFO("cam : {}",glm::to_string(cam));
}