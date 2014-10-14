#include "stdafx.h"

namespace shallow_check {

template <typename T>
inline void Ignore(const T&) {
}

template <typename T>
typename T::Index Shell(const T& env) {
  class ShallowChecks {
    void DeRef(T::Index ptr) {
      Ignore(*ptr);
    }
  };

  typename T::Index i = T::Index();
  return i;
}

template <typename T>
class Client {
public:
  typedef T Index;
};

TEST(Basic, ShallowCheck) {
  Client<int *> ptr_client;
  EXPECT_EQ(0, Shell(ptr_client));

  //Client<int> int_client;
  //EXPECT_EQ(0, Shell(int_client));  // ShallowChecks에 의해 컴파일 되지 않는다.
}

} // namespace shallow_check