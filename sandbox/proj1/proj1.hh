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
    core::render::AtlasReader atlas{"../sandbox/texture.json"}; // core::render::SubTexture{2048, 548, 32, 1628, 0}

private:
    int8_t speed = 0;
    bool is_repeat = false;
};

#endif