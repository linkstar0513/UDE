set(UtMath_SRCS
        USum.h USum.cpp
        )

add_library(UtMath SHARED ${UtMath_SRCS})

target_link_libraries(UtMath)