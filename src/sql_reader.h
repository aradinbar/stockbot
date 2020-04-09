#include <iostream> 
#include <iostream>
#include <vector>  
#include "stock.h"
using namespace std; 

namespace sql_reader {


	//consts
	const string callback_func{"CALLBACK FUNCTION"};
	const string sql_select{"SELECT * FROM stock"};
	const string db_open_error{"Error open DB "};
	const string db_open_success{"Opened Database Successfully!"};
	const string select_error{"Error SELECT"};
	const string sql_operation_success{"Operation OK!"};


	//namespace functions 
	static int callback(void* data, int argc, char** argv, char** azColName);
	vector<stock> get_stocks_from_db(char * db_file_name );


}