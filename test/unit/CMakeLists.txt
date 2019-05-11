add_executable(Unit_Tests_run
    unit.cpp
)

target_link_libraries(Unit_Tests_run gtest gtest_main sfml-graphics sfml-audio sfml-window)