//
// Created by link on 18年7月5日.
//

#ifndef UT_SDL2_UBUTTON_H
#define UT_SDL2_UBUTTON_H

#include <UtEngine/UModel.h>
//#include <stb_image_config.h>
//继承UModel,可以绘制内部的mesh到表面
class UButton: public UModel {
public:
    //the witdh and heigth of button
    //需要知道viewport的宽高，所以要从外面传递viewport的宽高
    //根据viewport的宽高与目标的宽高对顶点做平移缩放变换
    uint32_t width,height;
    UButton();

    ~UButton();

};


#endif //UT_SDL2_UBUTTON_H
