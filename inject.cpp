#include "stdafx.h"

namespace inject {

int C;

class C {
public:
  static int F() {
    return sizeof(C);
  }

private:
  int i[2];
};

int F() {
  return sizeof(C);
}

TEST(Basic, Inject) {
  EXPECT_EQ(sizeof(int) * 2, C::F());
  EXPECT_EQ(sizeof(int), inject::F());
}

template <template<typename> class TT> class X {
};

template <typename T>
class D {
  D* a;
  D<void> b;
  //X<D> c;
  X<inject::D> e;
};

} // namespace inject
