
#define BOOST_TEST_MODULE TestORCA

#include <boost/test/unit_test.hpp>
#include "orca.h"

BOOST_AUTO_TEST_SUITE( assert_not_throws )

BOOST_AUTO_TEST_CASE( dummy1 )
{
  // Some graphlet tests
  BOOST_CHECK_EQUAL(1,1);
}

BOOST_AUTO_TEST_CASE( dummy2 )
{
  read_count_write_orca("tests/data/graphs/C2.txt");
}

BOOST_AUTO_TEST_SUITE_END()
