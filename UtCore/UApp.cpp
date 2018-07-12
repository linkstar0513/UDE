//
// Created by link on 18年7月1日.
//

#include <SDL.h>
#include <SDL_syswm.h>
#include <glad.h>
#include <iostream>

#include "UApp.h"

//init sdl2
int UApp::init() {



    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0){
    SDL_Log("Unable to initialize SDL: %s",SDL_GetError());
        return -1;
    }
    //初始化video模式wayland;
    if(SDL_VideoInit("wayland")!=0){
        if(SDL_VideoInit(nullptr)!=0){
        SDL_Log("Unable to initialize wSDL: %s",SDL_GetError());
            return -1;
        }
    }
    //gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress);
   //std::cout<< gladLoadGL()<<std::endl;
    //glClearColor(1.0f,1.0f,1.0f,1.0f);

    //SDL_GL_LoadLibrary(nullptr);

   // quit();
}
//destory sdl2
void UApp::quit() {
    SDL_Quit();

}
//处理事件循环

int UApp::exec() {
    while (is_quit){

        std::cout<<"App is running"<<std::endl;
    }
    return 0;
}

int UApp::testVer() {
    std::vector<Vertex> vertices;
    for(int j=0;j<10000;j++){
        Vertex vertex;//={glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1.0f,1.0f,1.0f),
        //glm::vec2(1.0f,1.0f)};
        glm::vec3 vectorTemp;
        vectorTemp=glm::vec3(1.0f,1.0f,1.0f);
        vertex.position=vectorTemp;
        vertex.normal=vectorTemp;

        glm::vec2 vec2temp;
        vec2temp=glm::vec2(0.0f,0.0f);
        vertex.texcorrds=vec2temp;

        vertices.push_back(vertex);
        std::cout<<"vector大小"<<vertices.size()<<std::endl;
    }
    std::cout<<"程序终了"<<std::endl;
    return 0;
}
