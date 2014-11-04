#include "stdafx.h"

namespace isclasst {

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

template <typename T>
bool Check() {
  if (IsClassT<T>::Yes) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
bool CheckT(T) {
  return Check<T>();
}

void MyFunc() {
}

TEST(Basic, IsClassT) {
  EXPECT_FALSE(Check<int>());

  class MyClass {};
  EXPECT_TRUE(Check<MyClass>());

  struct MyStruct {};
  MyStruct s;
  EXPECT_TRUE(CheckT(s));

  union MyUnion {};
  EXPECT_FALSE(Check<MyUnion>());

  EXPECT_FALSE(CheckT(MyFunc));

  enum E {
    e1
  } e = e1;
  EXPECT_FALSE(CheckT(e));
}

} // namespace isclasst
