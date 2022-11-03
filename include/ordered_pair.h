#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H

#include <algorithm>      // std::min, std::max

// @brief Avoid naming collisions
namespace orca::utils
{
  /// @brief Class enabling using sorted pairs of nodes in hashable maps
  class ordered_pair
  {
  private:

    // type alias for readibility
    using self_type = ordered_pair;

    // Nodes: defined as private because the order has to be controlled by the constructor
    int _first;
    int _second;

  public:

    /// @brief Constructor that sorts the values
    ordered_pair(int a, int b): _first( std::min(a,b) ), _second( std::max(a,b) ){}

    int first()const {return this->_first;}
    int second()const {return this->_second;}
    /// @brief Comparison operator
    /// @note Required for hash
    bool operator<(const self_type &other) const
    {
      if (this->first() == other.first())
      return this->second() < other.second();
      else
      return this->first() < other.first();
    }

    /// @brief Equality Comparable
    /// @note Required for hash
    bool operator==(const self_type &other) const
    {
      return this->first() == other.first() && this->second() == other.second();
    }

    /// @brief Hashable and usable in hashmaps
    struct hash
    {
      size_t operator()(const ordered_pair &x) const
      {
        return (x._first << 8) ^ (x._second << 0);
      }
    }; // end class hash

  }; // end class key_pair

} // end namespace orca::utils


#endif
