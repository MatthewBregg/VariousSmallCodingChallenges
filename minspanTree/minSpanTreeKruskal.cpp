#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<list>
int Nodes;
struct quickTree{
    //std::vector<std::vector<int > > edges;
    std::vector<bool> inTree;
    int sum;
    quickTree()
    {
	int n = Nodes;
	//edges = std::vector<std::vector<int > > (n+1,std::vector<int>(n+1,0));
	inTree = std::vector<bool>(n+1,false);
	sum = 0;
	
    };
    void combine(quickTree& in)
    {
	sum += in.sum;
	for (int i = 1; i < inTree.size(); ++i)
	    {
		this->inTree.at(i) =  (in.inTree.at(i) || this->inTree.at(i));
	    }
	/*
	  for (int i = 1; i < edges.size(); ++i)
	  {
	  for (int j = 1; j < edges.size(); ++j)
	  {
	  int temp = in.edges.at(i).at(j);
	  if (this->edges.at(i).at(j) == 0 || (temp < this->edges.at(i).at(j) && temp != 0))
	  {
	  this->edges.at(i).at(j) = temp;
	  }
	  }
	  }
	*/

    }

};
struct Node{
    int a, b, c;
    Node( int aa, int bb, int cc):a(aa),b(bb),c(cc){};
};
struct compare{
    bool operator()(Node& a, Node& b)
    {
	return a.c > b.c;
    }
};

	
int main()
{
    int tests;
    std::cin >> tests;
    for (int jkj = 0; jkj < tests; ++jkj)
	{
	    int p;
	    int edges;
	    std::cin >> p >> Nodes >> edges;
	    std::priority_queue<Node, std::vector<Node>,compare > edgesQueue;
	    for (int i = 0; i != edges; ++i) {
		int a,b,c;
		std::cin >> a >> b >> c;
		edgesQueue.push(Node(a,b,c));
		edgesQueue.push(Node(b,a,c));
	
	
	    }

	    std::vector<quickTree> forest(Nodes+1);
	    for (int i = 1; i <forest.size(); ++i)
		{
		    forest.at(i) = quickTree();
		    forest.at(i).inTree.at(i) = true;
		}
	    //std::cout << "nodes " << Nodes << std::endl;
	    while(!edgesQueue.empty())
		{
		    quickTree* A;
		    quickTree* B;
		    int Ai, Bi;
		    Node s = edgesQueue.top();
		    edgesQueue.pop();


		    for (int i = 1; i < forest.size(); ++i)
			{
			    if (forest.at(i).inTree.at(s.a))
				{
				    A = &forest.at(i);
				    Ai = i;
				}

			    if (forest.at(i).inTree.at(s.b))
				{
				    B = &forest.at(i);
				    Bi = i;
				}


			}
		    if (Ai == Bi)
			{
			    continue;
			}
		    if (!A || !B)
			{
			    continue;
			    std::cout << "ERR" << std::endl;
			}
		    //std::cout << "gattaied" << s.c << std::endl;
		    //A->edges.at(s.a).at(s.b) = s.c;
		    A->sum+=s.c;
		    A->combine(*B);
		    forest.erase(forest.begin()+Bi);
		    // std::cout << "A " << s.a << " B " << s.b << std::endl;
		    // std::cout << A->edges.at(s.a).at(s.b) << std::endl;
		    // std::cout << "size " << A->edges.size() << " " << A->edges.at(5).size() << std::endl;



		    //std::cout << "fin" << std::endl;
	 
		}

	    //int sum = 0;
 
	    // for (int i = 1; i <= Nodes; ++i) {
	    // 	for (int j = 1; j <= Nodes; ++j) {
	    // 		sum+=forest.at(1).edges.at(i).at(j); 
	    // 	}
	    // }
	    // std::cout << sum*p << std::endl;
	    std::cout << forest.at(1).sum*p << std::endl;
	}
}
