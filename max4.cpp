#include "stdafx.h"

template <typename T>
static const T& Max(const T& a, const T& b) {
  return (a > b) ? a : b;
}

template <typename T>
static const T& Max(const T& a, const T& b, const T& c) {
  return Max(Max(a, b), c);
}

static const int& Max(const int& a, const int &b) {
  return (a > b) ? a : b;
}

TEST(Basic, Max4) {
  EXPECT_EQ(4, Max(1, 2, 4)) << "int 버전 대신 템플릿 버전이 호출된다라고 하는데 vs2013 기준으로 int 버전이 사용됨";
}