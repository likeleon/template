#include "stdafx.h"

namespace accum5 {

template <typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
public:
  typedef int AccT;
  static AccT Zero() {
    return 0;
  }
};

template <typename T,
          typename AT = AccumulationTraits<T> >
class Accum {
public:
  static typename AT::AccT Accumulate(const T* beg, const T* end) {
    typename AT::AccT total = AT::Zero();
    while (beg != end) {
      total += *beg;
      ++beg;
    }
    return total;
  }
};

TEST(Traits, Accum5) {
  char name[] = "templates";
  EXPECT_EQ(975, Accum<char>::Accumulate(&name[0], &name[sizeof(name) - 1]));
}

} // namespace accum5
