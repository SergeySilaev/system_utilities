#include "test_registrator.h"

#include <boost/test/unit_test.hpp>
using boost::unit_test_framework::test_suite;
using boost::unit_test_framework::test_case;

test_suite* init_unit_test_suite( int argc, char* argv[] )
{
    test_suite* ts1 = BOOST_TEST_SUITE( "ts_logger tests" );
	boost::unit_test::unit_test_log.set_threshold_level( boost::unit_test::log_messages );

	using namespace system_utilities::tests_::common;
	ts1->add( BOOST_TEST_CASE( &ts_logger_constructor_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_write_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_flush_tests ) );
	//
	ts1->add( BOOST_TEST_CASE( &ts_logger_note_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_warn_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_error_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_debug_tests ) );
	ts1->add( BOOST_TEST_CASE( &ts_logger_fatal_tests ) );
	//
	if ( RUN_PERFORMANCE_TESTS )
	{
		ts1->add( BOOST_TEST_CASE( &ts_logger_write_performance_tests ) );
	}

	return ts1;
}
