#include <iostream>
using namespace std;

int main()
{
	string brackets;
	int  problemsnum;

	cin >> brackets;
	cin >> problemsnum;
	int problems [problemsnum * 2];
	int solutions [problemsnum];
	for (int i = 0; i <problemsnum*2; i++)
	{
		cin >> problems[i];


	}

	for (int i = 0; i <problemsnum; i++)
	{
		int begin;
		int end;
		begin=problems[2*i];
		end=problems[(2*i)+1];
		int A=0;
		int B=0;

		for (; begin < end+1; begin++)
		{
			//cout << end<<"II ran" << endl;

			if (brackets[begin-1] == '(')
			{
				A++;
				//cout << "I was ran" << endl;
			}
			else
			{

				if ( A > 0)
				{ B++;
					A--; }
			}
			solutions[i]=B*2;
		}

	}



	/*for (int i = 0; i <problemsnum; i++) {
	  cout << problems[2*i] << "and" ;
	  cout << problems[(2*i)+1] << endl;

	  }*/
	for (int i = 0; i < problemsnum; i++){
		cout << solutions[i] << endl;
	}




























	/*


	  int bracketcount = 0;
	  bool bracketinput = true;
	  string brackets[1000000];
	  string test;


	  while(bracketinput == true)
	  {


	  cin >> test;
	  if ( (test == ")" ) || (test == "(" ) )
	  {

	  cout << "Test passed" << endl;
	  brackets[bracketcount]=test;
	  bracketcount++;
	  }
	  else
	  {
	  cout << "Test failed" << endl;
	  bracketinput = false;
	  }
	  test = "";
	  }

	  cout << brackets[0] << endl;
	  //cout << brackets[bracketinput] << endl;
	  */











}
