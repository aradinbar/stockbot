#include <iostream> 
#include <iostream>
#include <vector>  
#include "my_system.h"
#include <curses.h>
using namespace std; 

namespace ncruses_display {



	//namespace functions 

	void Display(my_system & system, int n);
	void DisplayStocks(std::vector<stock> processes, WINDOW* window, int n);


}