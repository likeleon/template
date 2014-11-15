#include "stdafx.h"

namespace rparam {

template <typename T>
class IsClassT {
private:
  typedef char One;
  typedef struct {
    char a[2];
  } Two;
  
  template <typename C>
  static One Test(int C::*);
  template <typename C>
  static Two Test(...);

public:
  enum {
    Yes = sizeof(Test<T>(0)) == 1
  };
  enum {
    No = !Yes
  };
};

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

template <typename T>
class RParam {
public:
  typedef typename IfThenElse<IsClassT<T>::Yes,
                              const T&,
                              T>::ResultT Type;
};

class MyClass1 {
public:
  static int s_copy_constructor_called;

  MyClass1() {
  }

  MyClass1(const MyClass1&) {
    ++s_copy_constructor_called;
  }
};

int MyClass1::s_copy_constructor_called = 0;

struct MyClass2 {
  static int s_copy_constructor_called;

  MyClass2() {
  }

  MyClass2(const MyClass2&) {
    ++s_copy_constructor_called;
  }
};

template <>
class RParam<MyClass2> {
public:
  typedef MyClass2 Type;
};

int MyClass2::s_copy_constructor_called = 0;

template <typename T1, typename T2>
static void FooCore(typename RParam<T1>::Type /*t1*/, typename RParam<T2>::Type /*t2*/) {
}

template <typename T1, typename T2>
static void Foo(const T1& t1, const T2& t2) {
  FooCore<T1, T2>(t1, t2);
}

TEST(Basic, RParam) {
  MyClass1 mc1;
  MyClass2 mc2;
  Foo(mc1, mc2);
  EXPECT_EQ(0, MyClass1::s_copy_constructor_called);
  EXPECT_EQ(1, MyClass2::s_copy_constructor_called);
}

} // namespace rparam