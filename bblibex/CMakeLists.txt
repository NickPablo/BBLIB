project(bblibex)
cmake_minimum_required(VERSION 2.8)
add_executable(bblibex test.cpp)
target_link_libraries(bblibex bblib)

INSTALL(FILES bbdrive.hpp DigitalPin.hpp Driveable.hpp Ping.hpp PWM.hpp Serial.hpp
        DESTINATION "../include"
        )
        


