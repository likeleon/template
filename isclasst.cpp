#include "stdafx.h"

namespace isclasst {

template <typename T>
class IsClassT {
public:
  enum {
    Yes = sizeof(IsClass<T>::Test<T>(0)) == 1;
  };
  enum {
    No = !Yes;
  };

private:
  typedef char One;
  typedef {
    struct {
      char a[2];
    };
  } Two;
  template <typename C>
  static One Test(int C::*);
  template <typename C>
  static Two Test(...);
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

TEST(Basic, IsClassT) {
  EXPECT_FALSE(Check<int>());
 
  class MyClass {};
  EXPECT_TRUE(Check<MyClass>());

  struct MyStruct {};
  MyStruct s;
  EXPECT_TRUE(Check(s));
  
  union MyUnion {};
  void MyFunc() {};
  enum E { e1 } e;
  
}

} // namespace isclasst
