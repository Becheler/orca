
#define BOOST_TEST_MODULE TestOrderedPair

#include <boost/test/unit_test.hpp>

#include "ordered_pair.h"

BOOST_AUTO_TEST_SUITE( orca_components )

BOOST_AUTO_TEST_CASE( ordered_pair )
{
  orca::utils::ordered_pair x(3,4);
  BOOST_CHECK_EQUAL(x.first(), 3);
  BOOST_CHECK_EQUAL(x.second(),4);

  orca::utils::ordered_pair y(4,3);
  BOOST_CHECK_EQUAL(y.first(), 3);
  BOOST_CHECK_EQUAL(y.second(),4);

  orca::utils::ordered_pair z(10,-10);
  BOOST_CHECK_EQUAL(z.first(), -10);
  BOOST_CHECK_EQUAL(z.second(),10);
}

BOOST_AUTO_TEST_SUITE_END()
