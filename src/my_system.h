#include <iostream> 
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include "sql_reader.h"
using namespace std; 


class my_system 
{

public:

	//consts

	const char * db_path{"../database/mydatabase.db"};

	//Constructors
   
    my_system();

    //Public functions
	
	void run();

	//Getters

	vector<stock> get_vector_of_stocks();


private:

	//Private functions
	
	void  set_calculations(int i);
	float calc_benjamin_graham(stock temp_stock);
	
	//Priavte members

	vector<stock> vector_of_stocks ;
	vector<future<void>> futures ;
	mutex _mutex;
};