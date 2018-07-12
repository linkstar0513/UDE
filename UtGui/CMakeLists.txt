
#添加lib
set(UtGui_SRCS
        UWidget.h UWidget.cpp
        UButton.h UButton.cpp
        UEventHandler.h UEventHandler.cpp
        )

add_library(UtGui SHARED ${UtGui_SRCS})

target_link_libraries(UtGui
        GL)