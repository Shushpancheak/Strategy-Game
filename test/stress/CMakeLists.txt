add_executable(Stress_Tests_run
    stress.cpp
)

target_link_libraries(Stress_Tests_run gtest gtest_main sfml-graphics sfml-audio sfml-window)