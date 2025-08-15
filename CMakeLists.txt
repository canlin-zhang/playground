# Set C++17 
cmake_minimum_required(VERSION 3.10)
project(BadExamples CXX)
set(CMAKE_CXX_STANDARD 17)

## Bad references
# file(GLOB BAD_REF_SOURCES src/bad_reference/*.cpp)

# foreach(src ${BAD_REF_SOURCES})
#     get_filename_component(name ${src} NAME_WE)
#     add_executable(${name} ${src})
#     # Allow compilation to fail without stopping the build
#     add_custom_command(
#         TARGET ${name} POST_BUILD
#         COMMAND ""
#     )
# endforeach()

# Good references
file(GLOB GOOD_REF_SOURCES src/good_reference/*.cpp)
foreach(src ${GOOD_REF_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
    # Allow compilation to fail without stopping the build
    add_custom_command(
        TARGET ${name} POST_BUILD
        COMMAND ""
    )
endforeach()