#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <string>

using namespace std;

class fizzBuzz
{
public:
	fizzBuzz(int n);
	~fizzBuzz();

	int getResultInt();
	string getResultString();

private:
	int in;
	string str;
};

#endif // !FIZZBUZZ_H

