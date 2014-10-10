#include "stdafx.h"

GTEST_API_ int main(int argc, char** argv) {
  std::cout << "Running main() from engine_test.cpp" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
