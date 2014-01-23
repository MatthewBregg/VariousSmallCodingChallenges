#include <iostream>
  
  int main()
  {
	  //Set arraw of length, and then iterate it through it adding the numbers. 
	  int length;
	  
	  std::cin >> length;
	  if ( length > 1000 || length <1 )
	  {
		  std::cout << "Invalid Number entered";
			  return 0;

	  }
	  else;
	  int numbers [length];
	  for (int i = 0; i <length; i++)
	  {
		  int cardnum;
	  
	  std::cin >> cardnum;
	  
	  if ( cardnum > 1000 || cardnum <1 )
	  {
		  std::cout << "Invalid Number entered";
			  return 0;

	  }
	  else;
	  numbers[i]=cardnum;
	  }
	 
	  //Plays the game
	  int sereja = 0;
	  int dima = 0;
	  int end = length-1;
	  int begin = 0;

	  std::string test = "0";
	  for (int j = 0; j<length; j++)
	  {
		 		  if ( j % 2 == 0 )
		  {
			  if (  numbers[begin] > numbers[end] )
			  {
				  sereja = sereja + numbers[begin];
				  begin++;
				  
			  }
			  else
			  {
				    sereja = sereja + numbers[end];
				  end--;
			  }
			  

			  
		  }
		  else
		  {
			 
			  if (  numbers[begin] > numbers[end] )
			  {
				  dima = dima + numbers[begin];
				  begin++;
				  
			  }
			  else
			  {
				    dima = dima + numbers[end];
				  end--;
			  }
			  
		  }


		  
	  }
	  
	  // std::cout << numbers[1] << std::endl;
	  

	  std::cout << sereja;
	  std::cout << " ";
	  std::cout << dima << std::endl;
    
  }
