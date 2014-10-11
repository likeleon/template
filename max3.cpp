#include "stdafx.h"

template <typename T>
static const T& Max(const T& a, const T& b) {
  return (a > b) ? a : b;
}

template <typename T>
static const T*& Max(const T*& a, const T*& b) {
  return (*a > *b) ? a : b;
}

static const char*& Max(const char*& a, const char*& b) {
  return std::strcmp(a, b) > 0 ? a : b;
}

TEST(Basic, Max3) {
  int a = 7;
  int b = 42;
  EXPECT_EQ(b, Max(a, b));
  
  std::string s = "hey";
  std::string t = "you";
  EXPECT_EQ(t, Max(s, t));

  const int* pa = &a;
  const int* pb = &b;
  EXPECT_EQ(pb, Max(pa, pb));

  const char* s1 = "David";
  const char* s2 = "Nico";
  EXPECT_EQ(s2, Max(s1, s2));
}