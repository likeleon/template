#include "stdafx.h"

namespace zero_init {

template <typename T>
struct MyStruct {
  MyStruct()
    : val_(T()) {
  }

  T val_;
};

TEST(Basic, ZeroInit) {
  MyStruct<int> int_struct;
  EXPECT_EQ(0, int_struct.val_);
 
  MyStruct<float> float_struct;
  EXPECT_EQ(0.0f, float_struct.val_);

  MyStruct<nullptr_t> nullptr_struct;
  EXPECT_EQ(nullptr, nullptr_struct.val_);
}

} // namespace zero_init