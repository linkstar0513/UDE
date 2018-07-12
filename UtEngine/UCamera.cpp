//
// Created by link on 18年7月1日.
//

#include "UCamera.h"



int UCamera::init() {
    return 0;
}

UCamera::UCamera() {
    //初始化lookat矩阵定义摄像机的初始位置。
    //GLM已经提供了这些支持。我们要做的只是定义一个摄像机位置，一个目标位置和一个表示世界空间中的上向量的向量（我们计算右向量使用的那个上向量）。
    // 接着GLM就会创建一个LookAt矩阵，我们可以把它当作我们的观察矩阵：

    glm::vec3 pos   = glm::vec3(0.0f, 0.0f,  -20.0f);
    glm::vec3 dst = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 up    = glm::vec3(0.0f, 0.0f,  1.0f);

    cameraPos   = glm::vec3(0.0f, 0.0f,  50.0f);//摄像机位置
     //cameraFront = glm::vec3(1.0f, 0.0f, 0.0f);//摄像机方向
    cameraFront = glm::vec3(cos(glm::radians(yaw))*cos(glm::radians(pitch)),
                            sin(glm::radians(pitch)),
                            sin(glm::radians(yaw))*cos(glm::radians(pitch)));//摄像机方向

    //cameraFront = glm::normalize(glm::vec3(-cameraPos.x,-cameraPos.y,-cameraPos.z));//摄像机方向
     cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);//世界空间上向量

             speed=0.1f;

    std::cout <<"x" <<cameraFront.x
              <<"y"<<cameraFront.y
              <<"z"<<cameraFront.z<<std::endl;
}

//摄像机位置移动
int UCamera::move(int i) {
    if(i==8){
        cameraPos+=cameraFront* speed;
        //std::cout<<"the a is pressdown"<<std::endl;

    } else if(i==2){
        cameraPos-=cameraFront* speed;

    } else if(i==4){
        cameraPos-=glm::normalize(glm::cross(cameraFront,cameraUp))* speed;
    } else if(i==6){
        cameraPos+=glm::normalize(glm::cross(cameraFront,cameraUp)) * speed;
    }
    return 0;
}

int UCamera::rotate(int32_t x,int32_t y) {
    if(!is_focus){

    } else {
        float x_offset = x;
        //y轴是向上的
        float y_offset = -y;




        //灵敏度
        float sensitivity = 0.01;
        x_offset *= sensitivity;
        y_offset *= sensitivity;

        yaw += x_offset;//根据鼠标水平改变偏航角
        pitch += y_offset;//根据鼠标垂直移动改变俯视角



        if (pitch >= 89.0f) {
            pitch = 89.0f;
        } else if (pitch < -89.0f) {
            pitch = -89.0f;

        }


        glm::vec3 front;//计算方向向量
        //front.x=cos(glm::radians(yaw))*cos(glm::radians(pitch));
        //front.y=sin(glm::radians(pitch));
        //front.z=sin(glm::radians(yaw))*cos(glm::radians(pitch));

        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));

        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        //计算单位方向向量
        cameraFront = glm::normalize(front);
        //std::cout<<"x"<<cameraFront.x<<"y"<<cameraFront.y<<"z"<<cameraFront.z<<std::endl;


    }

    return 0;
}

