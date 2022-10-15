
#define BOOST_TEST_MODULE TestORCA

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( assert_not_throws )

BOOST_AUTO_TEST_CASE( test_command_line_interface )
{
  BOOST_CHECK_EQUAL(1,1);
  BOOST_CHECK_EQUAL(1,2);
}

BOOST_AUTO_TEST_SUITE_END()
