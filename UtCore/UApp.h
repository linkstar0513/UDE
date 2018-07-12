//
// Created by link on 18年7月1日.
//

#ifndef UT_SDL2_UAPP_H
#define UT_SDL2_UAPP_H

#include <UtEngine/UMesh.h>


class UApp {
public:
    bool is_quit= false;
    int init();
    void quit();
    int exec();

    int testVer();

};


#endif //UT_SDL2_UAPP_H