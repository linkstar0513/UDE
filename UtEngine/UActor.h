//
// Created by link on 18年7月1日.
//

#ifndef UT_SDL2_UACTOR_H
#define UT_SDL2_UACTOR_H

#include "UShader.h"
class UActor {
public:


    glm::mat4 model,view,projection;

    uint32_t vertex_array_id,vertex_buffer_id,EBO;
    UActor();
    ~UActor();
    UShader* shader;


    //该物体的着色器
    int setShader(UShader *shader);
    int setVertics();

    int init();
    //绑定数据模型
    int bindVertexArray();
    //设置VAO
    int setVertexArray();
    int unBindVertexArray();

    int use();
    //写到缓存中
    int draw();
};


#endif //UT_SDL2_UACTOR_H
