#ifndef RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH
#define RECURSION_ENGINE__SANDBOX__PROJ1__PROJ1_HH

#include <recursion.hh>

class Proj1 : public Recursion::core::Engine{

    public:
        Proj1();
        ~Proj1();
        virtual void application() override;

    private:
        unsigned int vertex_array;
        unsigned int vertex_buffer;
        unsigned int index_buffer;
        float* data;
    
};

#endif