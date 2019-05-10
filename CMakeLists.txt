cmake_minimum_required (VERSION 3.8)
project(Strategy-Game)

file(GLOB_RECURSE MAIN_SOURCES	*.cpp *.h *.hpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

if (TRUE)
	set(SFML_DIR "F:/!Edu/Programming_Technology/SFML2/SFML-2.5.1-windows-vc15-64-bit (1)/SFML-2.5.1/lib/cmake/SFML")
	set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

include_directories("Core" "Constants" "Core/GraphicComponent" "Core/Managers")

add_executable(Strategy-Game ${MAIN_SOURCES})

target_link_libraries(Strategy-Game sfml-graphics sfml-audio sfml-window)
