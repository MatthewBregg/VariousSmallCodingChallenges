#include<iostream>

int knapSack(int* weight, int* value, int itemN, int capacity)
{
    int* prev = new int[capacity+1];
    int* curr = new int[capacity+1];
    for(int i = 0; i <= capacity; ++i)
    {
	prev[i] = 0;
	curr[i] = 0;
    }
    for(int item = 1; item <= itemN; ++item)
    {
	int* temp = prev;
	prev = curr;
	curr = temp;
	//for(int i =0; i < capacity; ++i) {curr[i] = 0;}
	for (int slot = 1; slot <= capacity; ++slot)
	{
	    int itemVal = 0;
	    if (slot >= weight[item-1]) {itemVal = value[item-1];}

	    int temp = slot-weight[item-1];
	    if (temp < 0) {temp = 0;}
	    else {temp = prev[temp];}
	
	    if (temp+itemVal > prev[slot]) {curr[slot] = temp+itemVal;}
	    else{curr[slot] = prev[slot];}
	}
    }
    return curr[capacity];	
    
}
int main()
{
    int capacity, itemN;
    std::cin >> capacity >> itemN;
    int* weight = new int[itemN];
    int* value = new int[itemN];
    for(int i = 0; i != itemN; ++i)
    {
	std::cin >> value[i] >> weight[i];
    }
    std::cout << knapSack(weight,value,itemN,capacity) << std::endl;
    //Output
    //Test case 1: 11
    //ACed T: 1.92, M:18M
    // http://www.spoj.com/problems/LKS/
    //Trying to do this with a 2d array is 4 GB!

    

}
