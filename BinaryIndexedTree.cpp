#include<vector>
#include<iostream>
//Binary indexed trees
//Going to extensively comment this while I understand what I'm doing.
int getLeastSignificantBit(int i)//Returns the int with only the least significant bit on. AKA, the first 1 in the binary sequence. EX, for 3, 00000110, that's 00000010, which just leave 2^1. For 1, that's 00000001, or 2^0, 1. For 8, that's 000001000 to 000001000, or 8, and for 9, 000011000 to 000001000, 8 again. Essentially, in the sequence of power of twos that are used to build the number, 2^n..., returns the smallest 2^n that is turned on.
{
    int compI = ~i;
    ++compI;
    return i&compI;
}
//Now to explain the tree a bit.
//It's stored in an array, so each node N is simply tree[n] (1 indexed). Each tree[n] stores the sum from itself to it's parent. To get to the parent, to to tree(n), and subtract from n it's leastsigbit, so tree[n-getLeastSignificantBit(n)]. to get the child of a node, do the opposite, add the LSB, so tree[n+getLeastSignificantBit(n)]. A node can have multiple children, but they do are not important to keep track of, we only care about the child we get from the above process. The others are handled automatically with the update method.


//To update a tree, simply ge the change in value, and starting at the tree[n], update that stored sum of the range, which includes n. Then get it's child by adding the LSB, and update the child, which also includes it in it's range, and so on, until we hit the end of the tree.
void updateTree(std::vector<int>& tree, std::vector<int>& nums, int newVal, int i)
{
    int sumDiff = newVal-nums.at(i);
    nums.at(i) = newVal;
    for (; i < tree.size(); i+=getLeastSignificantBit(i))
	{
	    tree.at(i) += sumDiff;
	}
    //Note that this is the only time we need the originally array, if we didn't want to store the original array, say memory was tight, before updating, we could do queryTree(i)-queryTree(i-1), and replace the nums.at(i) with that. This adds +2log_2(n) to the update time, so it's still O(logn)
}
//To query the Tree,  or get the sum from 1 to i, we start at the node i, add that to a sum variable, and continue for each of it's parents, getting the parent by subtracting the LSB, until we hit the beggining of the array, 0.
int queryTree(int i, std::vector<int>& tree)
{
    int sum = 0;
    while(i!=0)
	{
	    sum+= tree.at(i);
	    i-=getLeastSignificantBit(i);
	}
    return sum;
	    
}
//This is simply getting the sum from a certain range, same as a nonupdatable array of total sums would, aka, we get the sum of the array up to that point j, and subtract from it the sum up to point i-1, via 2 queries. 
int queryTreeRange(int i, int j,std::vector<int>& tree)
{
    --i;
    return queryTree(j,tree)-queryTree(i,tree);
}
int main()
{
    int n, q;
    std::cin >> n;
    ++n;//1 index arrays
    std::vector<int> nums(n,0);
    std::vector<int> tree(n,0);
    for (int i = 1; i != n; ++i) {
	int temp;
	std::cin >> temp;
	updateTree(tree,nums,temp,i); //Lastly to build the tree, all that's nessecary is assume the array is all 0s. Thus, every node has sum 0. Then, for each element in the array, update the tree for that element with the value in the array, as if we had changed that value from 0 to whatever it is. Update = O(logn)*n times, so O(nlogn)
	nums.at(i) = temp;
    }
    //And that's all, the rest is querying code

    
    // for (int i = 1; i < tree.size(); ++i)
    // 	{
    // 	    std::cout << tree.at(i) << std::endl;
    // 	}
    // while(true)
    // 	{
    // 	    std::cin >> i >> j;
    // 	    std::cout <<    queryTreeRange(i,j,tree) << std::endl;
    // 	}
    std::cin >> q;
    for (int k = 0; k < q; ++k)
	{
	    int i,j;
	    std::cin >> i >> j;
	    ++i;
	    ++j;
	    std::cout << queryTreeRange(i,j,tree) << std::endl;

	}


}
