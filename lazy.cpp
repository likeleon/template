#include "stdafx.h"

namespace lazy {

template <typename T>
class Safe {
};

template <int N>
class Danger {
public:
  typedef char Block[N];
};

template <typename T, int N>
class Tricky {
public:
  virtual ~Tricky() {
  }
  
  void NoBodyHere(Safe<T> = 3);
  
  void InClass() {
    Danger<N> no_boom_yet;
  }
  
  void Error() {
    Danger<0> boom;
    (void)boom;
  }
  
  void UnSafe(T(*p)[N]);
  
  T operator->();
  
  virtual Safe<T> Suspect() {
    return Safe<T>();
  }
  
  struct Nested {
    Danger<N> pfew;
  };
  
  union {
    int align;
    Safe<T> anonymouse;
  };
};

TEST(Basic, Lazy) {
  Tricky<int, 0> ok;
  ok.Error();
}

} // namespace inject
