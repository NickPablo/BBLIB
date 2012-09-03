project(cbblib)
cmake_minimum_required(VERSION 2.8)

add_executable(cbblib main.cpp)
target_link_libraries(cbblib bblib)

INSTALL(FILES bbdrive.hpp DigitalPin.hpp Driveable.hpp Ping.hpp PWM.hpp Serial.hpp
        DESTINATION "../include"
        )
