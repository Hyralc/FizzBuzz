#include <fizzBuzz.h>
#include <fizzBuzzProxy.h>
#include<iostream>

using namespace std;

int main()
{
	fizzBuzz fizBuzPlay(1);
	fizzBuzzProxy proxy(&fizBuzPlay);
	int res = proxy;
	cout << "res : " << res << endl;
}