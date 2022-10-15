
#define BOOST_TEST_MODULE TestHybridLambda

#include <boost/test/unit_test.hpp>

#include <hybrid_lambda_lib/hybridLambda.hpp>
#include "hybrid_lambda_lib/sim_gt.hpp"

BOOST_AUTO_TEST_SUITE( assert_not_throws )

BOOST_AUTO_TEST_CASE( test_command_line_interface )
{
  BOOST_ASSERT_EQUAL(1,1);
  BOOST_ASSERT_EQUAL(1,2);
}

BOOST_AUTO_TEST_SUITE_END()
