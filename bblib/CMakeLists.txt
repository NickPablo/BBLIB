project(bblib)
cmake_minimum_required(VERSION 2.8)

add_library(bblib STATIC
    bbio.c
    bbio.h
    bbmath.c
    bbmath.h
    gperf_pinMap.h)
    
INSTALL(TARGETS bblib
        DESTINATION "lib"
        )
INSTALL(FILES bbio.h bbmath.h gperf_pinMap.h
        DESTINATION "../include"
        )

