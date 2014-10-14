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
  // �迭-������ ��ȯ(�������� decay)�� �Ķ���Ͱ� �����ڰ� �ƴ� ��쿡�� �Ͼ��.
  EXPECT_STREQ("char const [6]", Ref("hello"));
  EXPECT_STREQ("char const *", NonRef("hello"));
}

} // namespace ref_nonref