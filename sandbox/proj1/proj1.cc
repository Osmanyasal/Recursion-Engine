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
        sh.bind(); // bind shader !

        data = new float[3 * 6]{
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
        };
        unsigned int *index = new unsigned int[3 * 2]{0, 2, 1, 0, 3, 2};

        VAO.bind_vertex_buffer({data, sizeof(float) * 3 * 6})
            .add_layout({"color",
                         0,
                         render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .bind_index_buffer({index, sizeof(unsigned int) * 3 * 2})
            .build();

        data2 = new float[3 * 6]{
            // positions         // colors
            -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
            -1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom left
            0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f   // top
        };

        VAO2.bind_vertex_buffer({data2, sizeof(float) * 3 * 6})
            .add_layout({"color",
                         0,
                         render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .add_layout({"color",
                         1,
                         render::Quantity::Float3,
                         render::Type::Float,
                         render::Normalized::FALSE})
            .build(); 
}
Proj1::~Proj1()
{
        delete[] data;
        delete[] data2;
}
void Proj1::application()
{
        VAO.bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);


        // VAO2.bind();
        // glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);

        // glBindVertexArray(vertex_array2);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
}