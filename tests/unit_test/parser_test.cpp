
#define BOOST_TEST_MODULE TestOrderedPair

#include <boost/test/unit_test.hpp>

#include <string>
#include <sstream> // std::stringstream
#include "parser.h"

BOOST_AUTO_TEST_SUITE( orca_components )

BOOST_AUTO_TEST_CASE( cycle_3 )
{
  std::string cycle_3 = "3 3\n0 1\n1 2\n2 0";
  std::stringstream ss;
  ss << cycle_3;
  orca::UndirectedGraphParser p;
  p.parse(ss);

  BOOST_CHECK_EQUAL(p.nb_nodes_declared(), 3);
  BOOST_CHECK_EQUAL(p.nb_edges_declared(), 3);

}

BOOST_AUTO_TEST_SUITE_END()
