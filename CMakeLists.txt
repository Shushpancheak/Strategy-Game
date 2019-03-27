# CMakeList.txt: проект CMake для Strategy-Game; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
project(Strategy-Game)

set(SFML_DIR "F:/!Edu/Programming_Technology/SFML2/SFML-2.5.1-windows-vc15-64-bit (1)/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Strategy-Game "Strategy-Game.cpp" "Strategy-Game.h")

target_link_libraries(Strategy-Game sfml-graphics sfml-audio sfml-window)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
