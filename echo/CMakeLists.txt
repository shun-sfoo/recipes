file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_executable(echo ${srcs})

target_include_directories(echo PUBLIC include)

target_link_libraries(echo muduo_net)
target_link_libraries(echo muduo_base)
target_link_libraries(echo pthread rt)
