//
// Created by link on 18年7月1日.
//

//#include <GL/glew.h>




#include "UWidget.h"

#include <SDL_syswm.h>

#include <UtEngine/UUserInterface.h>

int UWidget::createWidget() {
    //设置gl的版本属性，必须在第一个窗口之前设置
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetSwapInterval(2);
   // std::cout<<"current _video driver"<<SDL_GetCurrentVideoDriver()<<std::endl;
    
    window=SDL_CreateWindow(
            "SDL Window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1600,
            900,
            SDL_WINDOW_ALLOW_HIGHDPI
            |SDL_WINDOW_RESIZABLE
            |SDL_WINDOW_OPENGL
            //|SDL_WINDOW_FULLSCREEN_DESKTOP
            //|SDL_WINDOW_VULKAN
            );

    if(window== nullptr){
        printf("Could not create window:%s\n",SDL_GetError());
    }

    //设置gl的上下文，初始化gl，加载gl函数//可以使用SDL替代
    SDL_GLContext gl_context=SDL_GL_CreateContext(window);

    gladLoadGL();
    //获取交换模式
    SDL_GL_SetSwapInterval(-1);




    //设置world的view与投影方式。

    //渲染循环

    model=glm::mat4(1.0f);

   // model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));

    view=glm::mat4(1.0f);
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));


    //初始化模型，渲染方式
    actor.init();
    //设置摄像机的位置方位矩阵
    camera.init();

    UButton button;

    //UShader myshader("/home/link/CLionProjects/UT_SDL2/resource/model_loading.vs", "/home/link/CLionProjects/UT_SDL2/resource/model_loading.fs");
    UShader myshader("/home/link/CLionProjects/UT_SDL2/resource/vertexShader.vert",
                     "/home/link/CLionProjects/UT_SDL2/resource/fragmentShader.frag");
    std::string filepath="/home/link/CLionProjects/UT_SDL2/resource/nanosuit/nanosuit.obj";
    //std::string filepath="/home/link/CLionProjects/UT_SDL2/resource/FBX/Sunrise Rooster Monk.fbx";
    //std::string filepath="/home/link/CLionProjects/UT_SDL2/resource/Hestia/Hestia 3D Figure.FBX";
    //std::string filepath="/home/link/CLionProjects/UT_SDL2/resource/zup.obj";
    //加载模型
    UModel models(filepath.data());



    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
    std::vector<Texture> textures;
    //Vertex vertextemp={glm::vec3(-0.5f, -0.5f, -0.5),glm::vec3(-0.5f, -0.5f, -0.5),glm::vec2(-0.5f, -0.5f)};

//长方形，标题拦
    vertices.push_back({glm::vec3(-1.0f, -0.8f, -1.0),glm::vec3(0.4f, 0.1f, 0.1f),glm::vec2(0.0f, 0.0f)});
    vertices.push_back({glm::vec3(-1.0f, 1.0f, -1.0),glm::vec3(0.2f, 0.9f, 0.2f),glm::vec2(0.0f, 1.0f)});
    vertices.push_back({glm::vec3(1.0f, -0.8f, -1.0),glm::vec3(0.9f, 0.2f, 0.2f),glm::vec2(1.0f, 0.0f)});
    vertices.push_back({glm::vec3(1.0f, 1.0f, -1.0),glm::vec3(0.3f, 0.3f, 0.3f),glm::vec2(1.0f, 1.0f)});

    //立方体
    //vertices.push_back({glm::vec3(-1.0f, -1.0f, -1.0),glm::vec3(0.4f, 0.1f, 0.1f),glm::vec2(0.0f, 0.0f)});
    //vertices.push_back({glm::vec3(-1.0f, 1.0f, -1.0),glm::vec3(0.2f, 0.9f, 0.2f),glm::vec2(0.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, -1.0f, -1.0),glm::vec3(0.9f, 0.2f, 0.2f),glm::vec2(0.5f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, 1.0f, -1.0),glm::vec3(0.3f, 0.3f, 0.3f),glm::vec2(1.0f, 0.0f)});

    //vertices.push_back({glm::vec3(-1.0f, -1.0f, 1.0),glm::vec3(0.1f, 0.4f, 0.9f),glm::vec2(0.0f, 0.0f)});
    //vertices.push_back({glm::vec3(-1.0f, 1.0f, 1.0),glm::vec3(0.3f, 0.5f, 0.8f),glm::vec2(0.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, -1.0f, 1.0),glm::vec3(0.2f, 0.9f, 0.5f),glm::vec2(1.0f, 1.0f)});
    //vertices.push_back({glm::vec3(1.0f, 1.0f, 1.0),glm::vec3(0.6f, 0.1f, 0.8f),glm::vec2(1.0f, 0.0f)});

    indices.push_back(0);indices.push_back(1);indices.push_back(2);indices.push_back(1);indices.push_back(2);indices.push_back(3);
    //indices.push_back(2);indices.push_back(3);indices.push_back(6);indices.push_back(3);indices.push_back(6);indices.push_back(7);
    //indices.push_back(6);indices.push_back(7);indices.push_back(4);indices.push_back(7);indices.push_back(4);indices.push_back(5);
    //indices.push_back(4);indices.push_back(5);indices.push_back(0);indices.push_back(5);indices.push_back(0);indices.push_back(1);
    //indices.push_back(5);indices.push_back(1);indices.push_back(7);indices.push_back(1);indices.push_back(4);indices.push_back(3);
    //indices.push_back(0);indices.push_back(2);indices.push_back(4);indices.push_back(2);indices.push_back(7);indices.push_back(6);

    Texture texture1;
    texture1.id=TextureFromFile("05.jpg","/home/link/CLionProjects/UT_SDL2/resource");
    texture1.path="05.jpg";
    texture1.type="texture_diffuse";
    textures.push_back(texture1);

    //this->vetices=vertices;this->indices=indices;
    //建立单独的模型

    UShader uishader("/home/link/CLionProjects/UT_SDL2/resource/uivert.vert",
                     "/home/link/CLionProjects/UT_SDL2/resource/uifrag.frag");


    std::string uifilepath="/home/link/CLionProjects/UT_SDL2/resource/ui.obj";
    UModel ui(uifilepath.data());


    UMesh uimesh1(vertices,indices,textures);

    UUserInterface userInterface;
    userInterface.meshes.push_back(uimesh1);

    UButton button1;


    model_vecotrs.push_back(userInterface);
    model_vecotrs.push_back(button1);


    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
      //                       "Missing file",
        //                     "File is missing. Please reinstall the program.",
          //                   NULL);





    //开启深度缓冲使得像素按照深度绘制
    glEnable(GL_DEPTH_TEST);

    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    while (!is_quit) {

        //事件处理
        handleEvents();


        //渲染



        if (is_render) {
            //获取窗口的宽高
            SDL_GL_GetDrawableSize(window,&width,&height);

            glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
            glViewport(0, 0, width, height);
/* Render here */
            glClearColor(1.0, 1.0, 1.0, 1.0);


            //view= glm::lookAt(glm::vec3(0.0f, 0.0f,  -20.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f,  0.0f));

            //摄像机的视角
            view = glm::lookAt(camera.cameraPos, camera.cameraPos+camera.cameraFront, camera.cameraUp);

            projection = glm::perspective(glm::radians(45.0f), float(width)/height, 0.1f, 100.0f);


            //projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,-10.0f,100.0f);
            //actor.view=view;
            //actor.model=model;
            //actor.projection=projection;

            //actor.draw();

            userInterface.model=model;
            userInterface.view=view;
            userInterface.projection=glm::ortho(-1.0f*float(width)/height,1.0f*float(width)/height,-1.0f,1.0f,-10.0f,100.0f);
            //uishader.setInt("texture_diffuse1",0);
            //userInterface.draw(&uishader);
           //button1.draw(&uishader);
           //ui.draw(&uishader);
            //使用着色器，并设置对应的转换矩阵

            render();


            models.model=model;
            models.view=view;
            models.projection=projection;


           // models.draw(&myshader);

           // uishader.setMat4("projection",projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,-10.0f,100.0f));



            //view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
            //actor.view=view;
            //button.view=glm::translate(view, glm::vec3(0.0f, 0.0f, -20.0f));
          //  actor.model=glm::translate(model,glm::vec3(2.0f,-2.0f,-0.1f));
           // actor.projection=projection;
           // actor.draw();
           // SDL_Delay(200);

            SDL_GL_SwapWindow(window);
        }
    }

return 0;
}

int UWidget::render() {
    UShader uishader("/home/link/CLionProjects/UT_SDL2/resource/uivert.vert",
                     "/home/link/CLionProjects/UT_SDL2/resource/uifrag.frag");
    for(uint32_t i=0;i<model_vecotrs.size();i++){
        model_vecotrs[i].draw(&uishader);
    }
    return 0;
}

int UWidget::show() {


   // SDL_Delay(10000);
    SDL_ShowWindow(window);

    return 0;
}

int UWidget::setActor(UActor uActor) {
    actor=uActor;
    return 0;
}

UWidget::UWidget() {

}

void UWidget::handleEvents() {



    //事件处理
    while (SDL_PollEvent(&event)) {
        switch (event.type){
            case SDL_QUIT:{
                is_quit=true;
            }

            //键盘事件
                //按下事件
            case SDL_KEYDOWN:{
                switch (event.key.keysym.scancode){
                    case SDL_SCANCODE_A:{
                        camera.move(4);
                        break;
                    }
                    case SDL_SCANCODE_D:{
                        camera.move(6);
                        break;
                    }
                    case SDL_SCANCODE_W:{
                        camera.move(8);
                        break;
                    }
                    case SDL_SCANCODE_S:{
                        camera.move(2);
                        break;
                    }
                    case SDL_SCANCODE_ESCAPE:{
                        //处于焦点模式时按esc退出焦点
                        if(camera.is_focus){
                            camera.is_focus= false;
                            SDL_SetRelativeMouseMode(SDL_FALSE);
                        }
                        break;
                    }
                }
                break;

            }

            //松开事件

            case SDL_KEYUP:{
                switch (event.key.keysym.scancode){

                }
                std::cout<<event.key.keysym.scancode<<std::endl;
                break;
            }
                //鼠标事件
                //按下
            case SDL_MOUSEBUTTONDOWN:{
                //判断鼠标的位置决定发生的事件。
                switch (event.button.button){
                    case SDL_BUTTON_LEFT:
                        if(camera.is_focus){
                            if(event.button.clicks==1){
                                    camera.is_focus= false;
                                    SDL_SetRelativeMouseMode(SDL_FALSE);
                                     }
                        } else {
                                camera.is_focus = true;
                                //当鼠标处于相对模式时，光标将被隐藏，驱动程序将尝试在当前窗口中报告连续运动。 只传递相对运动事件，鼠标位置不会改变。
                                SDL_SetRelativeMouseMode(SDL_TRUE);
                        }
                        break;
                }
            }
            //移动鼠标过程中，状态以及鼠标处理
            case SDL_MOUSEMOTION:{
                    if(camera.is_focus){
                    //点击鼠标会使得偏移量异常
                        if(SDL_GetMouseState(nullptr, nullptr)){

                        }else {
                            camera.rotate(event.motion.xrel, event.motion.yrel);
                        }
                    } else{

                    }


                break;
            }
                //进入窗口时，清除上一次的坐标值来计算偏移量
            case SDL_WINDOWEVENT:{

                switch (event.window.event) {
                    case SDL_WINDOWEVENT_ENTER:
                        //camera.is_focus = true;
                        // std::cout << "camera----------------------------------------------------------"
                        //        << camera.first_mouse << std::endl;
                                //SDL_ShowCursor(SDL_FALSE);
                               // SDL_CaptureMouse(SDL_TRUE);//屏幕外依然能获取到鼠标位置，但其他程序获取不到
                        break;
                }
            }

        }

    }

}
