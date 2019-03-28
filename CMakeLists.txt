cmake_minimum_required (VERSION 3.8)
project(Strategy-Game)

set(MAIN_SOURCES "Strategy-Game.cpp" "Strategy-Game.h" "Core/Game.cpp" "Core/Game.hpp" "Core/GraphicComponent/GraphicComponent.cpp" "Core/GraphicComponent/GraphicComponent.hpp" "Core/GraphicComponent/DrawVariant.hpp" "Constants/Strings.hpp")

set(SFML_DIR "F:/!Edu/Programming_Technology/SFML2/SFML-2.5.1-windows-vc15-64-bit (1)/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

include_directories("Core" "Core/GraphicComponent" "Constants")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Strategy-Game ${MAIN_SOURCES})

target_link_libraries(Strategy-Game sfml-graphics sfml-audio sfml-window)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
