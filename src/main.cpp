#include "ncruses_display.h"
#include <iostream> 
#include <thread>
#include <vector>


// g++ sql_reader.cpp stock.cpp my_system.cpp ncruses_display.cpp main.cpp -pthread  -lsqlite3 -std=c++11 -lncurses


int main(int argc, char** argv) 
{ 
	my_system system1;
	system1.run();
	ncruses_display::Display(system1, 10) ; 
    return 1;

} 