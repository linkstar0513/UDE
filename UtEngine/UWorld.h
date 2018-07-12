//
// Created by link on 18年7月1日.
//

#ifndef UT_SDL2_UWORLD_H
#define UT_SDL2_UWORLD_H


#include "UCamera.h"
class UWorld {
public:
    UCamera camera;
    int allacotr;
    int setCamera();
    int addAcotr();

    int getArrays();
    int draw();

};


#endif //UT_SDL2_UWORLD_H
