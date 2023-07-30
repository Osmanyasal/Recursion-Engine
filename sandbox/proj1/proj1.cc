#include <recursion.hh>
#include <proj1.hh>
#include <utils.hh>
#include <Input.hh>
#include <shader.hh>

Proj1::Proj1(){
        data = new float[3 * 3]{
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f,
        };

        glGenVertexArrays(1,&vertex_array);
        glBindVertexArray(vertex_array);

        glGenBuffers(1,&vertex_buffer);
        glBindBuffer(GL_ARRAY_BUFFER,vertex_buffer);
        glBufferData(GL_ARRAY_BUFFER,sizeof(float) * 9 ,data,GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float) * 3,nullptr);


        Recursion::core::render::Shader sh{};
        sh.bind();

} 
Proj1::~Proj1(){
        delete[] data;
}
void Proj1::application()
{
        glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES,0,3);
}