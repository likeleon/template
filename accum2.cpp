#include "stdafx.h"

namespace accum2 {

template <typename T>
class AccumulationTraits;

template<>
class AccumulationTraits<char> {
public:
  typedef int AccT;
};

template <typename T>
typename AccumulationTraits<T>::AccT Accum(const T* beg, const T* end) {
  typedef typename AccumulationTraits<T>::AccT AccT;
  AccT total = AccT();
  while (beg != end) {
    total += *beg;
    ++beg;
  }
  return total;
}

TEST(Traits, Accum2) {
  char name[] = "templates";
  EXPECT_EQ(975, Accum(&name[0], &name[sizeof(name) - 1]));
}

} // namespace accum2
