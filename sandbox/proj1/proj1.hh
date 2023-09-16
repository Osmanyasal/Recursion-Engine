#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>

using Recursion::core::render::Renderer2D;
class Proj1 : public Recursion::core::Application
{
public:
    Proj1();
    ~Proj1();
    virtual void application(float delta_time) override;
    virtual void application_event(core::events::Event &event) override;

private:
    GameObject container;
    GameObject container_specular;
    GameObject tile_map;

private:
    int8_t press_right_count = 0;
    int8_t press_left_count = 0;
};

#endif