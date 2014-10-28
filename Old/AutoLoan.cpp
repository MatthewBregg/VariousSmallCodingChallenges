#include <iostream>
using namespace std;


double checker(double Price, double payment, double loanterm,  double interest){
	double remaining = Price;
	for (int i = 0; i < loanterm; i++)	
	{
		remaining= (remaining+(remaining*(interest/100)))-payment;
			}
	return remaining;
}


double BinarySearch (double begin, double end, double precision, double Price, double payment, double loanterm)	
	 {

		 double midpoint=begin+((end-begin)/2);

		 if ( /*checker(Price, payment, loanterm, midpoint)*/ end-begin < precision ){
			 return 12*midpoint;
			 //cout << "I was run" << endl;
		 }
		 else if ( checker(Price, payment, loanterm, midpoint) > 0  ){
			 //cout << "I was run a" << endl;
			 return BinarySearch(begin, midpoint-precision, precision, Price, payment, loanterm);
		 }
		 else if ( checker(Price, payment, loanterm, midpoint) < 0 ){
			 // cout << "I was run b" << endl;
			 // cout <<  checker(Price, payment, loanterm, midpoint) << endl;
			  return BinarySearch(midpoint+precision, end,  precision, Price, payment, loanterm);
		 }

		 else {
			 cout << "Value not found" << endl;
			 return 0; }

	 }

	double InterestRate (double Price, double payment, double loanterm)

	{

		return BinarySearch(0,100, .000000000001, Price, payment, loanterm);	
			

	}
	
int main (){

	 int price;
	 int Mpayment;
	 int loanterm;
	  cin >> price;
	 cin >> Mpayment;
	 cin >> loanterm;

	 double result = InterestRate(price, Mpayment, loanterm);
	 cout << result << endl;


	return 0;

}
