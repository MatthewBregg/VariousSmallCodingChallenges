#include <iostream>

using namespace std;
//length try 2n-1
//Look into segment trees /segmentree to optimize
void stemtreemaker(string brackets, int begin, int end, int node, int*  nodes)
{
	//Initilize 4 row array, first row will be the matching brackets count, second row is left over brackets, third row is beggining, 4th is end.
int bracketamount = brackets.length();
	int A = 0;
			int C = 0;
			int B = 0;

			for (int i=begin; i < end+1; i++)
		{
		//			cout << end <<"II ran" << begin <<endl;
			int n = brackets[i] - '0';
			B = B+n; 

				}
	
			
cout << B << endl;
			nodes[node]=B;


		nodes[(bracketamount*12)+node] = begin;
				
		nodes[(bracketamount*16)+node] = end;

		if ((end-begin)<1)
		{ return; 
		}
		else{
			stemtreemaker(brackets, begin, (begin+((end-begin)/2)), 2*node, nodes);

		stemtreemaker(brackets, (begin+((end-begin)/2))+1, end, (2*node)+1, nodes);
		}
	

}

int solver(int begin, int end, int node,  int length, int* nodes )
{

//	cout << "Begin is " << begin << endl << "End is" << end << endl;
	cout << "Node end is" << 	nodes[(length*16)+node]+1 << "Node begin is " << nodes[(length*12)+node]+1 << "Node is " << node << endl;
	
	//cout << "testD" << endl;

	if ( end >= nodes[(length*16)+node]+1 && begin <= nodes[(length*12)+node]+1)
	{
		cout << "NextReturned " << nodes[node] << endl;
		//	cout << "testA" << endl;
		return nodes[node];
		
	}
	else if ( begin > nodes[(length*16)+node]+1 || end < nodes[(length*12)+node]+1)
	{	
cout << "NextOutside" << endl;
	return 0;
		//	cout << "testC" << endl;
	}
	else
	{
		//cout << "testB" << node << endl;
cout << "NextSum" << endl;
return (solver(begin, end, 2*node, length, nodes) + solver(begin, end, (2*node)+1, length, nodes));

			// while ( A>0 && nodes[(length*8)+i] < 0)
		// {
		// 	score++;
		// 	A--;
		// 	nodes[(length*8)+i]++;
		
		//}



		
	}
	


}

int main()
{
	string brackets;
	
   
	cin >> brackets;

		int nodes[brackets.length()*20];


	int length = brackets.length();
stemtreemaker(brackets,0, brackets.length()-1, 1, nodes);	
while (true)
{
	int begin;
	int end;


	cin >> begin;
	cin >> end;

	cout << nodes[(length*12) + begin] << " " << nodes[(length*16)+begin] << " " <<  nodes[begin] << endl;
	
//cout << nodes[begin] << endl;
	cout << solver(begin,end,1,length,nodes) << endl;
}
	


}
