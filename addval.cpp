#include "stdafx.h"

using ::testing::ElementsAre;

template <typename T, int VAL>
T AddValue(const T& x) {
  return x + VAL;
}

TEST(Basic, AddVal) {
  std::vector<int> source = { 1, 2, 3 };
  std::vector<int> dest(source.size());
  std::transform(source.begin(), source.end(), dest.begin(), AddValue<int, 3>);
  EXPECT_THAT(dest, ElementsAre(4, 5, 6));
}

template <const char* NAME>
class MyClass {
public:
  const char* name() { return NAME; }
};

extern const char s[] = "hello";

TEST(Basic, AddVal2) {
  MyClass<s> x;
  EXPECT_STREQ("hello", x.name());
}