#include "sql_reader.h"
#include <iostream> 
#include <sqlite3.h> 
#include <iostream>
#include <vector>
#include <stdlib.h>    
using namespace std; 
using namespace sql_reader; 


static int sql_reader::callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    std::vector<stock> * vector_of_stocks = static_cast<std::vector<stock>*>(data);
    if (argc==9)
    { 
        stock temp_stock(argv[1],atol(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]),atof(argv[6]),atof(argv[7]),atof(argv[8]));
        vector_of_stocks->push_back(std::move(temp_stock));
    }
    return 0; 
} 
  


vector<stock> sql_reader::get_stocks_from_db(char * db_file_name )
{
    auto vector_of_stocks = std::make_shared<vector<stock>>();
    sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open(db_file_name, &DB); 
    string data(callback_func); 
    string sql(sql_select); 
    
    if (exit) { 
        std::cerr << db_open_error << sqlite3_errmsg(DB) << std::endl; 
        abort();
    } 
  
    auto rc = sqlite3_exec(DB, sql.c_str(), callback,vector_of_stocks.get() , NULL); 
  
    if (rc != SQLITE_OK) 
        cerr << select_error << endl; 
    else { 
        cout << sql_operation_success << endl; 
    } 

    sqlite3_close(DB); 
    return *vector_of_stocks;
}




