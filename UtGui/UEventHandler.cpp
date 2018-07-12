//
// Created by link on 18年7月6日.
//

#include "UEventHandler.h"

void UEventHandler::handEvent() {


}

void UEventHandler::handEvent(SDL_Event &event) {
    switch (event.type){
        case SDL_KEYDOWN:{
            std::cout<<"EVENT HANDLE IS KEY DOWN";
        }
    }

}

