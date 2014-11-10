#include "stdafx.h"

namespace typeop {

template <typename T>
void Apply(T& arg, void(*func)(T)) {
  func(arg);
}

static void Incr(int& a) {
  ++a;
}

static void Print(int a) {
  std::cout << a << std::endl;
}

TEST(Basic, Apply) {
  int x = 7;
  Apply(x, Print);
  //Apply(x, Incr);
}

template <typename T>
class TypeOp {
public:
  typedef T         ArgT;
  typedef T         BareT;
  typedef const T   ConstT;
  typedef T&        RefT;
  typedef T&        RefBareT;
  typedef const T&  RefConstT;
};

template <typename T>
void Apply2(typename TypeOp<T>::RefT arg, void(*func)(T)) {
  func(arg);
}

TEST(Traits, Apply2) {
  int x = 7;
  Apply2(x, Print);
  Apply2(x, Incr);
}

} // namespace isclasst
