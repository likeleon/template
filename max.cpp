#include "stdafx.h"

template <typename T>
static const T& Max(const T& a, const T& b) {
  return (a > b) ? a : b;
}

TEST(Basic, Max) {
  EXPECT_EQ(2, Max(1, 2));
  EXPECT_EQ("ab", Max<std::string>("ab", "a"));
}