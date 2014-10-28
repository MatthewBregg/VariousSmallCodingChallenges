//http://saicheems.wordpress.com/2013/10/22/uva-543-goldbachs-conjecture/
#include<iostream>
#include "Sieve.h"
using namespace std;

int main()
{
	int length;
	cin >> length;
	Sieve* a=new Sieve(length);
	int b;	
	while(true)
	{
		cin >> b;
		string output;
		if (a->isprime(b))
		{
			output = "true";
		}
		else
		{
			output = "false";
		}
		cout <<  output << endl;
	}
}
