//
// Created by link on 18年7月2日.
//
#include <iostream>
//#include <dlfcn.h>

#include <SDL.h>
//#include <SDL_opengl.h>
//#include <SDL_opengl_glext.h>
//#include <glad/glad.h>
#include <glad.c>




//void (*sdl_init)(int a);
int main(){
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0){
        SDL_Log("Unable to initialize SDL: %s",SDL_GetError());
        return -1;
    }
    
    SDL_Window *window=SDL_CreateWindow(
            "SDL Window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            800,
            800,
            SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
    );
    if(window== nullptr){
        printf("Could not create window:%s\n",SDL_GetError());
    }

    SDL_GLContext gl_context=SDL_GL_CreateContext(window);
    int major,minor;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,&major);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,&minor);
    std::cout<<major<<"."<<minor<<std::endl;
    gladLoadGL();

    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    SDL_Delay(1000);

    SDL_DestroyWindow(window);
    return 0;

    SDL_Quit();
}

