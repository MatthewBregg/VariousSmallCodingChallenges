#include <iostream>
#include <math.h>
using namespace std;

int BinarySearch (int begin, int end,   int other, int volume)	
	 {

 
		 int midpoint=begin+((end-begin)/2);
		 //cout << "I was run" << begin << " " << end << " " << midpoint << " " << other << " " << endl;
		 if ( /*checker(Price, payment, loanterm, midpoint)*/ midpoint + other == volume ){
			 
//			 cout << "I was run a" << begin << " " << end << " " << midpoint << " " << other << " " << endl;
			 return midpoint*other;

			 
		 }
		 else if ( begin >= end)
			 {
//			 cout << "Value not found" << endl;
			 return 0; }


		 else if (midpoint + other > volume ){
			 //	 cout << "I was run a" << endl;
			 return BinarySearch(begin, midpoint-1, other, volume);
		 }
		 else if (midpoint + other < volume ){
			 //cout << "I was run b" << begin << " " << end << " " << midpoint << " " << other << " " << endl;

			 return BinarySearch(midpoint+1, end, other, volume);
		 }
		 return 0;
			 }


	
int main()
{
	int length;
	cin >> length;
	int notes[length];
	int volume[length];
	long long joy = 0;
	for (int i =0; i < length; i++)
	{
		cin >> notes[i];
		
	}
		for (int i =0; i < length; i++)
	{
		cin >> volume[i];
		
	}
		for (int i = 0; i < length; i++)
		{



			double inna= notes[i];
			//	int tempjoy=0;
			double dima = (volume[i]-notes[i]);
			if ( ((volume[i]-2*notes[i])> 0) || volume[i] <= 1 )
			{
				joy--;
			}
		
			else {
				//cout << "ceil is " << ceil(((inna+dima)/2)) << "Floor is" << floor(((inna+dima)/2)) << endl;
			
				joy += ceil(((inna+dima)/2)) * floor(((inna+dima)/2));


			}
	
		}
		cout << joy << endl;

		
}
