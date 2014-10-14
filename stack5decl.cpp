#include "stdafx.h"

namespace stack5_decl {

template <typename T>
class Stack {
public:
  template <typename T2>
  Stack<T>& operator = (const Stack<T2>& other) {
    if ((void*)this == (void*)&other) {
      return *this;
    }

    Stack<T2> tmp(other);
    
    elems_.clear();
    while (!tmp.Empty()) {
      elems_.push_front(static_cast<T>(tmp.Top()));
      tmp.Pop();
    }

    return *this;
  }

  void Push(const T& elem) {
    elems_.push_back(elem);
  }

  void Pop() {
    if (elems_.empty()) {
      throw std::out_of_range("Stack<>::Pop(): empty stack");
    }
    elems_.pop_back();
  }

  T Top() const {
    if (elems_.empty()) {
      throw std::out_of_range("Stack<>::Rop(): empty stack");
    }
    return elems_.back();
  }

  bool Empty() const {
    return elems_.empty();
  }

private:
  std::deque<T> elems_;
};

TEST(Basic, Stack5Decl) {
  Stack<int> int_stack;
  int_stack.Push(1);
  int_stack.Push(2);

  Stack<float> float_stack;
  float_stack.Push(100);
  float_stack.Push(200);

  float_stack = int_stack;
  EXPECT_EQ(2.0f, float_stack.Top());
  float_stack.Pop();
  EXPECT_EQ(1.0f, float_stack.Top());
  float_stack.Pop();
  EXPECT_TRUE(float_stack.Empty());
}

} // namespace stack5_decl