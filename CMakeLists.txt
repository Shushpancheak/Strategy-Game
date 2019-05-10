cmake_minimum_required (VERSION 3.8)
project(Strategy-Game)

file(GLOB_RECURSE MAIN_SOURCES	*.cpp *.h *.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#set(SFML_DIR "D:/!Edu/SFML-2.5.1/lib/cmake/SFML")
#set(SFML_DIR "F:/!Edu/Programming_Technology/SFML2/SFML-2.5.1-windows-vc15-64-bit (1)/SFML-2.5.1/lib/cmake/SFML")
#set(SFML_DIR "/home/travis/build/Shushpancheak/Strategy-Game/SFML/SFML-2.5.1/lib/cmake/SFML")
#list(APPEND CMAKE_PREFIX_PATH /home/travis/build/Shushpancheak/Strategy-Game/SFML/SFML-2.5.1/lib/cmake/SFML)
#message(STATUS "{$CMAKE_CURRENT_SOURCE_DIR}")
#set(SFML_DIR "F:/!Edu/Programming_Technology/SFML2/SFML-2.5.1/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

include_directories("Core" "Constants" "Core/GraphicComponent" "Core/Managers")

add_executable(Strategy-Game ${MAIN_SOURCES})

target_link_libraries(Strategy-Game sfml-graphics sfml-audio sfml-window)
