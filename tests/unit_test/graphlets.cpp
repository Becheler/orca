
#define BOOST_TEST_MODULE TestORCA

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( assert_not_throws )

BOOST_AUTO_TEST_CASE( dummy1 )
{
  // Some graphlet tests
  BOOST_CHECK_EQUAL(1,1);
}

BOOST_AUTO_TEST_CASE( dummy2 )
{
  // others graphlet tests
  BOOST_CHECK_EQUAL(1,2);
}

BOOST_AUTO_TEST_SUITE_END()
