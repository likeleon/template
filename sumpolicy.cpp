#include "stdafx.h"

namespace sumpolicy {

template <typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<int> {
public:
  typedef int AccT;
  static AccT Zero() {
    return 0;
  }
};

class SumPolicy {
public:
  template <typename T1, typename T2>
  static void Accum(T1& total, const T2& value) {
    total += value;
  }
};

template <typename T,
  typename Policy = SumPolicy,
  typename AT = AccumulationTraits<T> >
class Accum {
public:
  static typename AT::AccT Accumulate(const T* beg, const T* end) {
    typename AT::AccT total = AT::Zero();
    while (beg != end) {
      Policy::Accum(total, *beg);
      ++beg;
    }
    return total;
  }
};

TEST(Basic, SumPolicy) {
  int num[] = { 1, 2, 3, 4, 5 };
  EXPECT_EQ(15, Accum<int>::Accumulate(&num[0], &num[5]));
}

} // namespace sumpolicy
