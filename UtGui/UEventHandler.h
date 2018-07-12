//
// Created by link on 18年7月6日.
//

#ifndef UT_SDL2_UEVENTHANDLER_H
#define UT_SDL2_UEVENTHANDLER_H

#include <SDL.h>

#include <iostream>
//#include "UWidget.h"

class UEventHandler {
public:

   // UWidget *widget;
    void handEvent();

    void handEvent(SDL_Event &event);
};


#endif //UT_SDL2_UEVENTHANDLER_H
