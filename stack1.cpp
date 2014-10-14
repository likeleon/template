#include "stdafx.h"

namespace stack1 {

template <typename T>
class Stack {
public:
  void Push(const T& t);
  void Pop();
  T Top() const;
  bool Empty() const {
    return elems_.empty();
  }

private:
  std::vector<T> elems_;
};

template <typename T>
void Stack<T>::Push(const T& elem) {
  elems_.push_back(elem);
}

template <typename T>
void Stack<T>::Pop() {
  if (elems_.empty()) {
    throw std::out_of_range("Stack<>::Pop(): empty stack");
  }
  elems_.pop_back();
}

template <typename T>
T Stack<T>::Top() const {
  if (elems_.empty()) {
    throw std::out_of_range("Stack<>::Rop(): empty stack");
  }
  return elems_.back();
}

template <>
class Stack < std::string > {
public:
  void Push(const std::string& elem) {
    elems_.push_back(elem);
  }

  void Pop() {
    if (elems_.empty()) {
      throw std::out_of_range("Stack<std::string>::Pop(): empty stack");
    }
    elems_.pop_back();
  }

  std::string Top() const;
  bool Empty() const {
    return elems_.empty();
  }

private:
  std::deque<std::string> elems_;
};

TEST(Basic, Stack1) {
  Stack<int> int_stack;
  int_stack.Push(7);
  EXPECT_EQ(7, int_stack.Top()) << "Top()은 int에 대해서만 인스턴스화";

  Stack<std::string> string_stack;
  string_stack.Push("Hello");
  string_stack.Pop();
}

} // namespace stack1