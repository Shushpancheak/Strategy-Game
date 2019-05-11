#include "gtest/gtest.h"
#include "Map.hpp"
#include <chrono>

/**
 * Series of tests dedicated to time taken by Map to create itself
 * with different sizes.
 */

TEST(Stress_Tests, Map_test_1) {
  auto start = std::chrono::steady_clock::now;

  Map map = Map(nullptr, nullptr, 10, 10);

  auto end = std::chrono::steady_clock::now;

  EXPECT_LE(chrono::duration_cast<double>(end - start).count(), 10);
}

TEST(Stress_Tests, Map_test_2) {
  auto start = std::chrono::steady_clock::now;

  Map map = Map(nullptr, nullptr, 50, 50);

  auto end = std::chrono::steady_clock::now;

  EXPECT_LE(chrono::duration_cast<double>(end - start).count(), 10);
}

TEST(Stress_Tests, Map_test_3) {
  auto start = std::chrono::steady_clock::now;

  Map map = Map(nullptr, nullptr, 100, 100);

  auto end = std::chrono::steady_clock::now;

  EXPECT_LE(chrono::duration_cast<double>(end - start).count(), 10);
}

TEST(Stress_Tests, Map_test_4) {
  auto start = std::chrono::steady_clock::now;

  Map map = Map(nullptr, nullptr, 1000, 1000);

  auto end = std::chrono::steady_clock::now;

  EXPECT_LE(chrono::duration_cast<double>(end - start).count(), 100);
}