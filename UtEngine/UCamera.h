//
// Created by link on 18年7月1日.
//

#ifndef UT_SDL2_UCAMERA_H
#define UT_SDL2_UCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <SDL.h>

class UCamera {
public:
    UCamera();
    glm::mat4 view;
    glm::vec3 pos  ;
    glm::vec3 dst ;
    glm::vec3 up ;

    bool is_focus= false;
    int32_t mouse_x;
    int32_t mouse_y;

    float yaw=-90.0f;//偏航角
    float  pitch=0.0f;//俯视角

    glm::vec3 cameraPos  ;//摄像机位置
    glm::vec3 cameraFront;//摄像机方向
    glm::vec3 cameraUp    ;//世界空间上向量

    float speed;
    int init();

    int move(int i);
    int rotate(int32_t i,int32_t y);
};


#endif //UT_SDL2_UCAMERA_H
