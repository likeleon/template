#include "stdafx.h"

static int Max(int a, int b) {  // A
  return (a > b) ? a : b;
}

template <typename T>
static T Max(const T& a, const T& b) {  // B
  return (a > b) ? a : b;
}

TEST(Basic, Max2) {
  EXPECT_EQ('b', Max('a' , 'b'));
  EXPECT_EQ(2, Max(1, 2)) << "A, 완벽히 맞는 일반 함수가 템플릿보다 우선";
  EXPECT_EQ(2, Max<>(1, 2)) << "B";
  EXPECT_EQ(2, Max<double>(1, 2));
  EXPECT_EQ('a', Max('a', 42)) << "A, 템플릿은 데이터형을 변환 하지 않음";
}