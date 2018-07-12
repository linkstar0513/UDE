//
// Created by link on 18年7月1日.
//

#include "UActor.h"

int UActor::setShader(UShader *uShader) {
    this->shader=uShader;
    //shader=new UShader("/home/link/CLionProjects/UT/resource/vertexShader.vs",
     //                  "/home/link/CLionProjects/UT/resource/fragmentShader.fs");
    return 0;
}

int UActor::init() {
    //设置着色器，数据模型
    UShader* uShader=new UShader("/home/link/CLionProjects/UT_SDL2/resource/vertexShader.vert",
                                 "/home/link/CLionProjects/UT_SDL2/resource/fragmentShader.frag");
    setShader(uShader);

    //绑定数据
    setVertics();

    //vbo绑定vao
    bindVertexArray();

    //vao绑定属性
    setVertexArray();

    //解绑vao
    unBindVertexArray();



    return 0;
}

UActor::UActor()
        //:model(glm::mat4(1.0f)), view(glm::mat4(1.0f)), projection(glm::ortho(-5.0f,5.0f,-5.0f,5.0f,-5.0f,5.0f))
{

}

int UActor::setVertics() {




    float vertics1[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,0.1f ,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.1f ,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,0.1f ,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.1f ,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.1f ,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,0.1f ,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,0.1f ,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.1f ,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.1f ,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.1f ,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.1f ,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.1f ,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,0.1f ,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.1f ,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.1f ,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,0.1f ,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,0.1f
    };




    float vertics3[]= {
            -0.5f, -0.5f, -0.5,0.1f, 0.1f, 0.1f ,//0
            -0.5f, 0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//1
            0.5f, -0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//2
            -0.5f, 0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//1
            0.5f, -0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//2
            0.5f, 0.5f, -0.5, 0.3f, 0.3f, 0.3f ,//3

            0.5f, -0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//2
            0.5f, 0.5f, -0.5, 0.3f, 0.3f, 0.3f ,//3
            0.5f, -0.5f, 0.5, 0.6f, 0.6f, 0.6f ,//6
            0.5f, 0.5f, -0.5, 0.3f, 0.3f, 0.3f ,//3
            0.5f, -0.5f, 0.5, 0.6f, 0.6f, 0.6f ,//6
            0.5f, 0.5f, 0.5, 0.7f, 0.7f, 0.7f,//7

            0.5f, -0.5f, 0.5, 0.6f, 0.6f, 0.6f ,//6
            0.5f, 0.5f, 0.5, 0.7f, 0.7f, 0.7f,//7
            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//4
            0.5f, 0.5f, 0.5, 0.7f, 0.7f, 0.7f,//7
            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//4
            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//5

            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//4
            -0.5f, 0.5f, 0.5, 0.5f, 0.5f, 0.5f ,//5
            -0.5f, -0.5f, -0.5,0.1f, 0.1f, 0.1f ,//0
            -0.5f, 0.5f, 0.5, 0.5f, 0.5f, 0.5f ,//5
            -0.5f, -0.5f, -0.5,0.1f, 0.1f, 0.1f ,//0
            -0.5f, 0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//1


            -0.5f, 0.5f, 0.5, 0.5f, 0.5f, 0.5f ,//5
            -0.5f, 0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//1
            0.5f, 0.5f, 0.5, 0.7f, 0.7f, 0.7f,//7
            -0.5f, 0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//1
            0.5f, 0.5f, 0.5, 0.7f, 0.7f, 0.7f,//7
            0.5f, 0.5f, -0.5, 0.3f, 0.3f, 0.3f ,//3


            -0.5f, -0.5f, -0.5,0.1f, 0.1f, 0.1f ,//0
            0.5f, -0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//2
            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//4
            0.5f, -0.5f, -0.5, 0.2f, 0.2f, 0.2f ,//2
            -0.5f, -0.5f, 0.5, 0.4f, 0.4f, 0.4f ,//4
            0.5f, -0.5f, 0.5, 0.6f, 0.6f, 0.6f ,//6

    };


    float  vertexevo[]={
            -0.5f, -0.5f, -0.5,0.4f, 0.1f, 0.1f ,//0
            -0.5f, 0.5f, -0.5, 0.2f, 0.5f, 0.2f ,//1
            0.5f, -0.5f, -0.5, 0.5f, 0.2f, 0.2f ,//2
            0.5f, 0.5f, -0.5, 0.3f, 0.9f, 0.3f ,//3
            -0.5f, -0.5f, 0.5, 0.9f, 0.1f, 0.4f ,//4
            -0.5f, 0.5f, 0.5, 0.5f, 0.1f, 0.9f ,//5
            0.5f, -0.5f, 0.5, 0.6f, 0.1f, 0.3f ,//6
            0.5f, 0.5f, 0.5, 0.7f, 0.1f, 0.9f,//7



    };


    uint32_t indecis1[]={
           // 0,1,2,1,2,3,
           // 2,3,6,3,6,7,
           // 6,7,4,7,4,5,
           // 4,5,0,5,0,1,
           // 5,1,7,1,7,3,
            0,2,4,2,4,6

    };

    return 0;
}

int UActor::bindVertexArray() {

    float  vertexevo[]={
            -0.5f, -0.5f, -0.5,0.4f, 0.1f, 0.1f ,//0
            -0.5f, 0.5f, -0.5, 0.2f, 0.9f, 0.2f ,//1
            0.5f, -0.5f, -0.5, 0.9f, 0.2f, 0.2f ,//2
            0.5f, 0.5f, -0.5, 0.3f, 0.3f, 0.3f ,//3
            -0.5f, -0.5f, 0.5, 0.1f, 0.4f, 0.9f ,//4
            -0.5f, 0.5f, 0.5, 0.3f, 0.5f, 0.8f ,//5
            0.5f, -0.5f, 0.5, 0.2f, 0.9f, 0.5f ,//6
            0.5f, 0.5f, 0.5, 0.6f, 0.1f, 0.8f,//7



    };

    uint32_t indecis1[]={
            0,1,2,1,2,3,
            2,3,6,3,6,7,
            6,7,4,7,4,5,
            4,5,0,5,0,1,
            5,1,7,1,7,3,
            0,2,4,2,4,6

    };


    glGenVertexArrays(1,&vertex_array_id);
    glGenBuffers(1,&vertex_buffer_id);
    glGenBuffers(1,&EBO);

    glBindVertexArray(vertex_array_id);

    glBindBuffer(GL_ARRAY_BUFFER,vertex_buffer_id);


    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertics),vertics,GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexevo),vertexevo,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
   // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indecis1),indecis1,GL_STATIC_DRAW);




    return 0;
}

int UActor::setVertexArray() {

    //设置顶点属性并启用
    //指定解析顶点数据熟悉的方式(属性的位置(location)，顶点属性的值数量大小vec3为3，数据类型，是否标准化，步长（整个顶点属性字节的大小），偏移量应该是偏移位置×大小)
    glVertexAttribPointer(0,3,GL_FLOAT,GL_TRUE, sizeof(float)*6,(void *)0);
//启用顶点属性
    glEnableVertexAttribArray(0);



    //指定颜色属性数据的获取方式并启用
    glVertexAttribPointer(1,3,GL_FLOAT,GL_TRUE, sizeof(float)*6,(void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);
    return 0;
}

int UActor::unBindVertexArray() {
    //vao会存储ebo的解绑调用，所以确保在VAO解绑之前ebo的解绑不会发生
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    return 0;
}

int UActor::use() {
    glBindVertexArray(vertex_array_id);
    return 0;
}

int UActor::draw() {


    //查询uniform地址不要求你之前使用过着色器程序，但是更新一个uniform之前你必须先使用程序（调用glUseProgram)，因为它是在当前激活的着色器程序中设置uniform的。
    shader->use();
   // shader->setMat4("model",model);
    //view=glm::translate(view, glm::vec3(0.0f, 0.0f, 0.5f));
    shader->setMat4("model",model);
    shader->setMat4("view",view);
    shader->setMat4("projection",projection);

    use();

    //std::cout<<"Uactor is drawing"<<std::endl;
    //图元属性，顶点数量，顶点ebo的索引值，0，遗留问题。

    //glDrawArrays(GL_TRIANGLES,0,36);
    glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
    return 0;
}

UActor::~UActor() {

    //析构时删除对应的资源
    glDeleteVertexArrays(1,&vertex_array_id);
    glDeleteBuffers(1,&vertex_buffer_id);
    glDeleteBuffers(1,&EBO);

}


