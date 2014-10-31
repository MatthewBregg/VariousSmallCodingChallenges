#include<iostream>
#include<sstream>

int knapSack(int* weight, int* value, int itemN, int capacity, std::string* names = 0, bool outputName = false)
{
    int** DP = new int*[itemN+1];
    for (int i = 0; i <= itemN; ++i)
    {
	DP[i] = new int[capacity+1];
	for (int j = 0; j <= capacity; ++j)
	{
	    DP[i][j] = 0;
	}
    }
    for(int item = 1; item <= itemN; ++item)
    {
	for (int slot = 1; slot <= capacity; ++slot)
	{
	    int itemVal = 0;
	    if (slot >= weight[item-1]) {itemVal = value[item-1];}

	    int temp = slot-weight[item-1];
	    if (temp < 0) {temp = 0;}
	    else {temp = DP[item-1][temp];}
	
	    if (temp+itemVal > DP[item-1][slot]) {DP[item][slot] = temp+itemVal;}
	    else{DP[item][slot] = DP[item-1][slot];}
	}
    }
    if(outputName){
    std::stringstream took;
    int slot = capacity;
    for(int item = itemN; item > 0; --item)
    {
	if(DP[item][slot] == DP[item-1][slot]){continue;}
	took << names[item-1] << " ";
	slot = slot-weight[item-1];
	if (slot <= 0) {break;}

    }
    std::cout << "Items taken: " << took.str() << std::endl;}
    
    return DP[itemN][capacity];	
    
}
int main()
{
    //Test case given in lecture
    /*
    int capacity = 10;
    int itemN =4;
    int* weight = new int[itemN];
    int* value = new int[itemN];
    std::string* names = new std::string[itemN];
    weight[0] = 3;
    weight[1] = 6;
    weight[2] = 4;
    weight[3] = 2;

    value[0] = 14;
    value[1] = 30;
    value[2] = 17;
    value[3] = 9;

    names[0] = "A";
    names[1] = "B";
    names[2] = "C";
    names[3] = "D";
    std::cout << knapSack(weight,value,itemN,capacity,names) << std::endl;

    Output : 
    Items taken: C B 
    47
    */
    int capacity, itemN;
    std::cin >> capacity >> itemN;
    int* weight = new int[itemN];
    int* value = new int[itemN];
    for(int i = 0; i != itemN; ++i)
    {
	std::cin >> value[i] >> weight[i];
    }
    std::cout << knapSack(weight,value,itemN,capacity) << std::endl;

    

}

