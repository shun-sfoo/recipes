file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_executable(test1 ${srcs} test1.cpp )
target_include_directories(test1 PUBLIC include)

add_executable(test2 ${srcs} test2.cpp )
target_include_directories(test2 PUBLIC include)

add_executable(test3 ${srcs} test3.cpp )
target_include_directories(test3 PUBLIC include)

target_link_libraries(test1 muduo_net)
target_link_libraries(test1 muduo_base)
target_link_libraries(test1 pthread rt)

target_link_libraries(test2 muduo_net)
target_link_libraries(test2 muduo_base)
target_link_libraries(test2 pthread rt)


target_link_libraries(test3 muduo_net)
target_link_libraries(test3 muduo_base)
target_link_libraries(test3 pthread rt)
