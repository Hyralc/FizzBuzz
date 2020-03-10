#ifndef FIZZBUZZPROXY_H
#define FIZZBUZZPROXY_H

#include<fizzBuzz.h>

class fizzBuzzProxy
{
public:
	fizzBuzzProxy(fizzBuzz* owner) : myOwner(owner) {}
	operator int() const;
	operator string() const;

private:
	fizzBuzz* myOwner;
};

#endif