#include <iostream>
  
  int main()
  {
	  //Set array of length, and then iterate it through it adding the numbers. 
	  int length;
	  
	  std::cin >> length;
	  if ( length > 1000000 || length <1 )
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
	  
	  if ( cardnum > 5000 || cardnum <1 )
	  {
		  std::cout << "Invalid Number entered";
			  return 0;

	  }
	  else;
	  numbers[i]=cardnum;
	  }
	

	  std::cout << numbers[2];

  }
