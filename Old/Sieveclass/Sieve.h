#ifndef __Sieve_H_INCLUDED__   // if x.h hasn't been included yet...
#define __Seive_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include<iostream>
#include<string>
#include <math.h>
using namespace std;
class Sieve{

public:
	bool isprime(int n);
	Sieve(int n);
private:
	int length;
	int* primes;
	bool* nums;
	bool primecheckinorder(int a);
	int primetotal;

};
#endif
