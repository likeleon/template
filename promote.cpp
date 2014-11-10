#include "stdafx.h"

namespace promote {

template <bool C, typename Ta, typename Tb>
class IfThenElse;

template <typename Ta, typename Tb>
class IfThenElse < true, Ta, Tb > {
public:
  typedef Ta ResultT;
};

template <typename Ta, typename Tb>
class IfThenElse < false, Ta, Tb > {
public:
  typedef Tb ResultT;
};

template <typename T1, typename T2>
class Promotion {
public:
  /*typedef typename
    IfThenElse<(sizeof(T1) > sizeof(T2)),
               T1,
               typename IfThenElse<(sizeof(T1) < sizeof(T2)),
                                   T2,
                                   void
                                  > ::ResultT
               > ::ResultT ResultT;*/
  typedef typename
    IfThenElse<(sizeof(T1) > sizeof(T2)),
               T1,
               T2
               > ::ResultT ResultT;
};

template <typename T1, typename T2>
static typename Promotion<T1, T2>::ResultT operator+(const T1& t1, const T2& t2) {
  return typename Promotion<T1, T2>::ResultT(t1.val + t2.val);
}

template <class T>
struct Foo {
  T val;

  Foo(T _val)
    : val(_val) {
  }
};

TEST(Traits, Promote) {
  EXPECT_EQ(3.3, (Foo<int>(1) + Foo<double>(2.3)).val);
  EXPECT_EQ(3.2, (Foo<double>(1.2) + Foo<int>(2)).val);
}

} // namespace promote
