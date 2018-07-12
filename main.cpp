#include <iostream>
#include <UtCore/UApp.h>
#include <UtGui/UWidget.h>
#include <UtEngine/UActor.h>



#include <vector>
#include <array>
#include <glm/glm.hpp>







int main() {


    UApp uApp;

    uApp.init();

    UWidget uWidget;

    uWidget.createWidget();



    uWidget.show();


    uApp.quit();
    return uApp.exec();
}
