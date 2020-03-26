#include <../include/fizzBuzz.h>

fizzBuzz::fizzBuzz(int n) : in(n), str("") {}

fizzBuzz::~fizzBuzz() {}

int fizzBuzz::getResultInt()
{
	return in;
}

string fizzBuzz::getResultString()
{
	if (in % 3 == 0 && in % 5 == 0)
		return "FizzBuzz";
	if (in % 3 == 0)
		return "Fizz";
	if (in % 5 == 0)
		return "Buzz";
	return "";
}