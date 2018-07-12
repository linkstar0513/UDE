
#添加lib
set(UtEngine_SRCS
        glad.h glad.c
        UWorld.cpp UWorld.h
        UActor.cpp UActor.cpp
        UCamera.h UCamera.cpp
        UShader.h UShader.cpp
        UMesh.cpp UMesh.h UModel.cpp UModel.h UUserInterface.cpp UUserInterface.h)

add_library(UtEngine SHARED ${UtEngine_SRCS})

link_libraries(UtEngine
        assimp
        )
#        GL
 #       glfw3)