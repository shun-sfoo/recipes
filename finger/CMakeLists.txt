add_executable(finger01 finger01.cpp)
target_link_libraries(finger01 muduo_net)

add_executable(finger02 finger02.cpp)
target_link_libraries(finger02 muduo_net)

add_executable(finger03 finger03.cpp)
target_link_libraries(finger03 muduo_net)

add_executable(finger04 finger04.cpp)
target_link_libraries(finger04 muduo_net muduo_base)

add_executable(finger05 finger05.cpp)
target_link_libraries(finger05 muduo_net muduo_base)

add_executable(finger06 finger06.cpp)
target_link_libraries(finger06 muduo_net muduo_base)

add_executable(finger07 finger07.cpp)
target_link_libraries(finger07 muduo_net muduo_base)
