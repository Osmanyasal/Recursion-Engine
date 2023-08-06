#include <proj1.hh>

Proj1::Proj1()
{
        /*
                in this settings

                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);

                By default, based on my expierments
                it starts drawing + to -
                in collision it draws the last one on top of it
                here, sinde 0.2 is drawn later, it gets on top of it.
        */
        data = new float[3 * 3]{
            -1.0f,
            0.0f,
            -0.2f,

            -1.0f,
            1.0f,
            -0.2f,

            1.0f,
            0.0f,
            -0.2f,
        };
        glGenVertexArrays(1, &vertex_array);
        glBindVertexArray(vertex_array);

        VB = new render::VertexBuffer{data, sizeof(float) * 9}; 

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

        data2 = new float[3 * 3]{
            -1.0f,
            -1.0f,
            -0.8f,

            1.0f,
            -1.0f,
            -0.8f,

            0.0f,
            1.0f,
            -0.8f,
        };

        glGenVertexArrays(1, &vertex_array2);
        glBindVertexArray(vertex_array2);

        glGenBuffers(1, &vertex_buffer2);
        glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer2);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, data2, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

        sh.bind(); // bind shader !
}
Proj1::~Proj1()
{
        delete[] data;
        delete[] data2;
}
void Proj1::application()
{ 
        glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(vertex_array2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
}