#include "stdafx.h"

namespace adl {

namespace x {
  template<typename T>
  void F(T);
}

namespace n {
using namespace x;
enum E {
  e1
};
int F(E /*e*/) {
  return 0;
}
}

int F(int /*i*/) {
  return 1;
}

TEST(Basic, ADL) {
  EXPECT_EQ(1, adl::F(n::e1));
  EXPECT_EQ(0, F(n::e1));
}

} // namespace adl