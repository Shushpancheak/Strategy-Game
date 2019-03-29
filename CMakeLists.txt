cmake_minimum_required (VERSION 3.8)
project(Strategy-Game)

file(GLOB_RECURSE MAIN_SOURCES	*.cpp *.h *.hpp)
message("MESSAGE: " ${MAIN_SOURCES})

set(SFML_DIR "D:/!Edu/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

include_directories("Core" "Constants" "Core/GraphicComponent")

# Добавьте источник в исполняемый файл этого проекта.
add_executable(Strategy-Game ${MAIN_SOURCES})

target_link_libraries(Strategy-Game sfml-graphics sfml-audio sfml-window)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
