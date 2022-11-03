#ifndef ORCA_IO_H
#define ORCA_IO_H

#include <iostream>
#include <parser.h>

///
/// @brief Stream operator
///
std::ostream& operator <<(std::ostream& stream, orca::UndirectedGraphParser const& p)
{
  stream << "Number of nodes: " << p._n << std::endl;
  stream << "Number of edges: " << p._m << std::endl;
  return stream;
}

#endif
