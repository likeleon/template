#include "stdafx.h"

namespace accum1 {

template <typename T>
T Accum(const T* beg, const T* end) {
  T total = T();
  while (beg != end) {
    total += *beg;
    ++beg;
  }
  return total;
}

TEST(Traits, Accum1) {
  int num[] = { 1, 2, 3, 4, 5 };
  EXPECT_EQ(15, Accum(&num[0], &num[5]));

  char name[] = "templates";
  EXPECT_EQ((char)207, Accum(&name[0], &name[sizeof(name) - 1]));
}

} // namespace accum1
