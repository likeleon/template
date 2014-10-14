#include "stdafx.h"

namespace ref_nonref {

template <typename T>
const char* Ref(const T& x) {
  return typeid(x).name();
}

template <typename T>
const char* NonRef(T x) {
  return typeid(x).name();
}

TEST(Basic, ZeroInit) {
  // 배열-포인터 변환(데이터형 decay)는 파라미터가 참조자가 아닐 경우에만 일어난다.
  EXPECT_STREQ("char const [6]", Ref("hello"));
  EXPECT_STREQ("char const *", NonRef("hello"));
}

} // namespace ref_nonref