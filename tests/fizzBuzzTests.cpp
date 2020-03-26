#define BOOST_TEST_MODULE fizzBuzz tests
#include <boost/test/included/unit_test.hpp>
namespace utf = boost::unit_test;

#include "fizzBuzz.h"
#include "fizzBuzzProxy.h"

using namespace std;

// Filtering tests to be executed, with a test suite (named "returning_int")
// Ex cmd line :
//		> fizzBuzz.exe --run_test=returning_int --log_level=test_suite
BOOST_AUTO_TEST_SUITE(returning_int)

BOOST_AUTO_TEST_CASE(supplyIntegerZero__getIntegerZero)
{
	fizzBuzz fizBuzPlay(0);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	BOOST_REQUIRE_EQUAL(0, res);
}

BOOST_AUTO_TEST_CASE(supplyIntegerOne__getIntegerOne)
{
	fizzBuzz fizBuzPlay(1);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	BOOST_REQUIRE_EQUAL(1, res);
}

BOOST_AUTO_TEST_CASE(supplyInteger2__getInteger2)
{
	fizzBuzz fizBuzPlay(2);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	BOOST_REQUIRE_EQUAL(2, res);
}

BOOST_AUTO_TEST_CASE(supplyInteger4__get4)
{
	fizzBuzz fizBuzPlay(4);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	BOOST_REQUIRE_EQUAL(4, res);
}

// Filters tests to be executed, with a decorator (named "input_is_more_than_5").
// Ex cmd line :
//		> fizzBuzz.exe --run_test=@input_is_more_than_5
BOOST_AUTO_TEST_CASE(supplyInteger7__get7, *utf::label("input_is_more_than_5"))
{
	fizzBuzz fizBuzPlay(7);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	BOOST_REQUIRE_EQUAL(7, res);
}

BOOST_AUTO_TEST_SUITE_END()


// Test suite "returning_string"
BOOST_AUTO_TEST_SUITE(returning_string)

BOOST_AUTO_TEST_CASE(supplyInteger3__getFizz)
{
	fizzBuzz fizBuzPlay(3);
	fizzBuzzProxy proxy(&fizBuzPlay);
	string res = proxy;
	BOOST_REQUIRE_EQUAL("Fizz", res);
}
BOOST_AUTO_TEST_CASE(supplyInteger5__getBuzz)
{
	fizzBuzz fizBuzPlay(5);
	fizzBuzzProxy proxy(&fizBuzPlay);
	string res = proxy;
	BOOST_REQUIRE_EQUAL("Buzz", res);
}

BOOST_AUTO_TEST_CASE(supplyInteger15__getFizzBuzz)
{
	fizzBuzz fizBuzPlay(15);
	fizzBuzzProxy proxy(&fizBuzPlay);
	string res = proxy;
	BOOST_REQUIRE_EQUAL("FizzBuzz", res);
}

BOOST_AUTO_TEST_SUITE_END()