#include "fizzBuzzProxy.h"

fizzBuzzProxy::operator int() const
{
	return myOwner->getResultInt();
}

fizzBuzzProxy::operator string() const
{
	return myOwner->getResultString();
}