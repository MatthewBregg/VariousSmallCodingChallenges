#include<iostream>
#include<vector>

int main()
{
    int tests;
    std::cin >> tests;
    for (int aasd = 0; aasd != tests; ++aasd)
	{
	    int p;
	    int nodes;
	    int edges;
	    std::cin >> p >> nodes >> edges;
	    std::vector<bool> treed(nodes+1,false);
	    std::vector<std::vector<int> > graph(nodes+1, std::vector<int> (nodes+1, 0));
	    std::vector<std::vector<int> > tree(nodes+1, std::vector<int> (nodes+1, 0));

	    for (int i = 0; i != edges; ++i) {
		int a,b,c;
		std::cin >> a >> b >> c;
		graph.at(a).at(b) = c;
		graph.at(b).at(a) = c;
	
	    }
	    treed.at(1) = true; 
	    while(true)
		{
		    int path = -1;
		    int ii, kk;
		    ii = -1;
		    kk = -1;
		    for (int i = 1; i <= nodes; ++i) {
			if (!treed.at(i))
			    {continue;}
			for (int j = 1; j <= nodes; ++j)
			    {
				int temp = graph.at(i).at(j);
				if (!treed.at(j) && temp != 0)
				    {
					if (path == -1 || path > temp)
					    {
						path = temp;
						ii = i;
						kk = j;

					    }
				    }
			    }
		
		    }
		    if (path == -1)
			{
			    break;
			}
		    if (ii == -1 || kk == -1)
			{
			    //std::cout << "ERR" << std::endl;
			}
		    tree.at(ii).at(kk) = path;
		    treed.at(kk) = true; 

		}
	    int sum = 0;
	    for (int i = 1; i <= nodes; ++i) {
		if (treed.at(i))
		    {continue;}
		//std::cout << "ERRRR" << std::endl;
	    }

	    for (int i = 1; i <= nodes; ++i) {
		for (int j = 1; j <= nodes; ++j) {
		    if (tree.at(i).at(j) != 0)
			//   std::cout << " I " << i << " J " << j << std::endl;
			sum+=tree.at(i).at(j); 
		}
	    }
	    std::cout << sum*p << std::endl;
	}


    
}
