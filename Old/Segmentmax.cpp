#include <iostream>
//Sorry for the mess
using namespace std;
//length try 2n-1
//Look into segment trees /segmentree to optimize
void stemtreemaker(int *numbers, int begin, int end, int node, int*  nodes, int length)
{



			int B = numbers[begin];

			for (int i=begin; i < end+1; i++)
		{
		//			cout << end <<"II ran" << begin <<endl;
			if (B < numbers[i])	
			{
				B = numbers[i];
			}


				}
	
			
//cout << B << endl;
			nodes[node]=B;


		nodes[(length*12)+node] = begin;
				
		nodes[(length*16)+node] = end;

		if ((end-begin)<1)
		{ return; 
		}
		else{
			stemtreemaker(numbers, begin, (begin+((end-begin)/2)), 2*node, nodes, length);

			stemtreemaker(numbers, (begin+((end-begin)/2))+1, end, (2*node)+1, nodes, length);
		}
	

}

int solver(int begin, int end, int node,  int length, int* nodes )
{

//	cout << "Begin is " << begin << endl << "End is" << end << endl;
	//cout << "Node end is" << 	nodes[(length*16)+node]+1 << "Node begin is " << nodes[(length*12)+node]+1 << "Node is " << node << endl;
	
	//cout << "testD" << endl;

	if ( end >= nodes[(length*16)+node]+1 && begin <= nodes[(length*12)+node]+1)
	{
		//cout << "NextReturned " << nodes[node] << endl;
		//	cout << "testA" << endl;
		return nodes[node];
		
	}
	else if ( begin > nodes[(length*16)+node]+1 || end < nodes[(length*12)+node]+1)
	{	
//cout << "NextOutside" << endl;
		return -2147483648;//find a way to make this insert something that always fails the max test;
		//	cout << "testC" << endl;
	}
	else
	{
		//cout << "testB" << node << endl;
//cout << "NextSum" << endl;
return max(solver(begin, end, 2*node, length, nodes) , solver(begin, end, (2*node)+1, length, nodes));

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
	int length;
	cin >> length;
	int numbers[length];
	for (int i=0; i < length; i++)
	{
		cin >> numbers[i];  
			}
	int problemsnum;
		cin >> problemsnum;

	int problems [problemsnum * 2];
   	for (int i = 0; i <problemsnum*2; i++)
	{
		cin >> problems[i];
		

	}


		int nodes[length*20];


	
		stemtreemaker(numbers,0, length-1, 1, nodes, length);	
		
	for (int i = 0; i<problemsnum; i++)
	{
	
		
			cout << solver(problems[2*i], problems[2*i+1], 1, length, nodes) << endl;

	}
		

		/*	
while (true)
{
	int begin;
	int end;


	cin >> begin;
	cin >> end;

//	cout << nodes[(length*12) + begin] << " " << nodes[(length*16)+begin] << " " <<  nodes[begin] << endl;
	
//cout << nodes[begin] << endl;
	cout << solver(begin,end,1,length,nodes) << endl;
}
	
*/	


}
