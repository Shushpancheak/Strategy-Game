add_executable(Usability_Tests_run
    usability.cpp
)

target_link_libraries(Usability_Tests_run gtest gtest_main sfml-graphics sfml-audio sfml-window)