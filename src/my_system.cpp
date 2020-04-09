#include <iostream> 
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include "my_system.h"
using namespace std; 

//Constructors 

my_system::my_system(){

};


//Getters

vector<stock> my_system::get_vector_of_stocks(){
	return this -> vector_of_stocks;
}


//Public functions

void my_system::run(){

	vector_of_stocks = sql_reader::get_stocks_from_db((char *)db_path);
    for (int i = 0; i < vector_of_stocks.size(); i++)
        futures.emplace_back(async(std::launch::async, &my_system::set_calculations,this, i));
    for_each(futures.begin(), futures.end(), [](future<void> &ftr) {
        ftr.wait();});
    std::sort(vector_of_stocks.begin(), vector_of_stocks.end());
};



//Private functions


float my_system::calc_benjamin_graham(stock temp_stock){
	
	float benjamin_graham_param = 0 ;

	if ( temp_stock.get_total_revenue()  > 350000000 ) 
		benjamin_graham_param ++ ; 
   
    if ( temp_stock.get_current_ratio()  > 2 )
		benjamin_graham_param ++ ; 
    
    if ( ( temp_stock.get_p_e()  > 5 ) && ( temp_stock.get_p_e()  < 15 ) )
    	benjamin_graham_param ++ ; 
      
    if ( temp_stock.get_graham_multiplier()  < 22 )
 		benjamin_graham_param ++ ; 
        
    if ( temp_stock.get_eps_growth() > 0.3 )
    	benjamin_graham_param ++ ; 
        
    if ( temp_stock.get_return_on_equity()  > 15 )
		benjamin_graham_param ++ ; 

    if ( temp_stock.get_return_on_invested_capital()  > 15 ) 
		benjamin_graham_param ++ ; 

	return benjamin_graham_param ; 

}

void my_system::set_calculations(int i)
{
	float benjamin_graham_param = my_system::calc_benjamin_graham(vector_of_stocks[i]);
	//locking access to stock vector
	std::unique_lock<std::mutex> uLock(_mutex);
	vector_of_stocks[i].set_benjamin_graham_result(benjamin_graham_param) ;
	uLock.unlock();

};



