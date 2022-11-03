#ifndef KEY_TRIPLE_H
#define KEY_TRIPLE_H

#include <algorithm>      // std::min, std::max

/// @brief Class that enables using triplet of nodes in hashable maps
class key_triple
{
private:
  // type alias
  using self_type = key_triple;
  // data members
  int a;
  int b;
  int c;
public:

  /// @brief Constructor using initialization list
  key_triple(int a0, int b0, int c0): a(a0), b(b0), c(c0)
  {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
  }

  /// @brief Comparison operator
  bool operator<(const self_type &other) const
  {
    if (this->a == other.a)
    {
      if (this->b == other.b)
      return this->c < other.c;
      else
      return this->b < other.b;
    } else {
      return this->a < other.a;
    }
  }

  /// @brief EqualityComparable
  bool operator==(const self_type &other) const
  {
    return this->a == other.a && this->b == other.b && this->c == other.c;
  }

  /// @brief Hashable and usable in hashmaps
  struct hash
  {
    size_t operator()(const key_triple &x) const
    {
      return (x.a << 16) ^ (x.b << 8) ^ (x.c << 0);
    }
  };
}; // end class key_triple

#endif
