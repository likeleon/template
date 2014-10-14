#include "stdafx.h"

namespace stack7_decl {

// ���ø� ���ø� �Ķ������ ���
template <typename T,
          template <typename ELEM,
                    typename = std::allocator<ELEM>>  // std::deque�� �Ҵ��� ���ڿ� �����ؾ� �Ѵ�. ���ø� ���ø� ������ �Ķ���Ͱ� ġȯ�� �װͰ� ��Ȯ�� ��ġ�ؾ� ��.
                    class CONT = std::deque>
class Stack {
public:
  template <typename T2,
            template <typename ELEM2,
                      typename = std::allocator<ELEM2>>
                      class CONT2>
  Stack<T, CONT>& operator = (const Stack<T2, CONT2>& other) {
    if ((void*)this == (void*)&other) {
      return *this;
    }

    Stack<T2, CONT2> tmp(other);

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
  CONT<T> elems_;
};

TEST(Basic, Stack7Decl) {
  Stack<int, std::vector> int_stack;
  int_stack.Push(1);
  int_stack.Push(2);
  EXPECT_EQ(2, int_stack.Top());

  Stack<float, std::deque> float_stack;
  float_stack = int_stack;
  EXPECT_EQ(2.0f, float_stack.Top());
}

} // namespace stack7_decl