//
// Created by link on 18年7月1日.
//

#ifndef UT_SDL2_UWIDGET_H
#define UT_SDL2_UWIDGET_H

#include <SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <UtEngine/UWorld.h>
#include <UtEngine/UActor.h>
#include <UtEngine/UCamera.h>

#include <UtGui/UButton.h>
#include <UtGui/UEventHandler.h>

#include <UtEngine/UModel.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>


class UWidget {
public:

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    SDL_Surface *surface;
    SDL_Texture *texture;

    bool is_quit= false;
    bool is_render= true;

    bool is_moving= false;


    //摄像机
    UCamera camera;

    //事件处理

    int32_t width;
    int32_t height;



    glm::mat4 model;
    int contrall;
    glm::mat4 view;
    //变换矩阵通过对模型的变换变换到viwport上
    glm::mat4 projection;
    UWidget();



    UWorld world;
    UActor actor;
    int createWidget();
    int setActor(UActor uActor);
    int render();
    void handleEvents();

    int show();

};


#endif //UT_SDL2_UWIDGET_H
