#include "Sieve.h"

bool Sieve::primecheckinorder(int a)
{
	if ( a%2 == 0 || nums[a] == false)
	{ return false;}
	
	double sqr = sqrt (a);
	cout << sqr << endl;	
	for ( int i = 2; primes[i] <= sqr; i++)
	{
		
		if ( a%primes[i]==0) 
		{
			return false;
		}
	}
	return true;
		
	
}
Sieve::Sieve(int n)
{
	length = n;
	primes = new int[length+1];
	nums = new bool[length+1];
for (int i = 0; i < length+1; i++)
	{
		
		nums[i]=true;	
	}
	primes[0]=0;
	primes[1]=1;
	primes[2]=2;

	primetotal=3;
	for (int i = 3; i < length+1; i++)
	{
		
		if (primecheckinorder(i)	)
		{

			primes[primetotal]=i;

			primetotal++;
			for (int m = 2; (m*i) <=length; m++)
			{
				nums[m*i]=false;
			}
		}
		else
		{
			nums[i]=false;
		}
	}


	
}
bool Sieve::isprime(int p)
{
	return nums[p];
	
}

