#include <iostream> 
#include "stock.h" 

using namespace std; 

//Constructors

stock::stock(){

	this->total_revenue = 0 ;
	this->current_ratio = 0 ;
	this->p_e = 0 ;
	this->graham_multiplier = 0 ;
	this->eps_growth = 0 ;
	this->return_on_equity = 0 ;
	this->return_on_invested_capital = 0 ;
	this->benjamin_graham_result = -1 ;

};

//g++ sql_reader.cpp stock.cpp -lsqlite3 -std=c++11



stock::stock(string name,long total_revenue, float current_ratio, float p_e, float graham_multiplier,float eps_growth
    	, float return_on_equity, float return_on_invested_capital){

	this->name = name ;
	this->total_revenue = total_revenue ;
	this->current_ratio = current_ratio ;
	this->p_e = p_e ;
	this->graham_multiplier = graham_multiplier ;
	this->eps_growth = eps_growth ;
	this->return_on_equity = return_on_equity ;
	this->return_on_invested_capital = return_on_invested_capital ;
	this->benjamin_graham_result = -1;

}

//Destructor

stock::~stock()
{
}

//Copy consturctor.

stock::stock(const stock & other){

	this->name = other.name ;
	this->total_revenue = other.total_revenue ;
	this->current_ratio = other.current_ratio ;
	this->p_e = other.p_e ;
	this->graham_multiplier = other.graham_multiplier ;
	this->eps_growth = other.eps_growth ;
	this->return_on_equity = other.return_on_equity ;
	this->return_on_invested_capital = other.return_on_invested_capital ;
	this->benjamin_graham_result = other.benjamin_graham_result ;
}

//Copy assignment operator

stock& stock::operator=(const stock& other){
	
	if (this==&other)
    	return *this;
	
	this->name = other.name ;
	this->total_revenue = other.total_revenue ;
	this->current_ratio = other.current_ratio ;
	this->p_e = other.p_e ;
	this->graham_multiplier = other.graham_multiplier ;
	this->eps_growth = other.eps_growth ;
	this->return_on_equity = other.return_on_equity ;
	this->return_on_invested_capital = other.return_on_invested_capital ;	
	this->benjamin_graham_result = other.benjamin_graham_result ;
	return *this;
}  

//Move consturctor   

stock::stock(stock && other){

	this->name = other.name ;
	this->total_revenue = other.total_revenue ;
	this->current_ratio = other.current_ratio ;
	this->p_e = other.p_e ;
	this->graham_multiplier = other.graham_multiplier ;
	this->eps_growth = other.eps_growth ;
	this->return_on_equity = other.return_on_equity ;
	this->return_on_invested_capital = other.return_on_invested_capital ;	
	this->benjamin_graham_result = other.benjamin_graham_result ;

	other.name = "" ;
	other.total_revenue = 0 ;
	other.current_ratio = 0 ;
	other.p_e = 0 ;
	other.graham_multiplier = 0 ;
	other.eps_growth = 0 ;
	other.return_on_equity = 0 ;
	other.return_on_invested_capital = 0 ;	
	other.benjamin_graham_result = 0;
    
}

//Move assignment operator

stock& stock::operator=(stock && other){

  	if (this != &other) { 
		this->name = other.name ;
		this->total_revenue = other.total_revenue ;
		this->current_ratio = other.current_ratio ;
		this->p_e = other.p_e ;
		this->graham_multiplier = other.graham_multiplier ;
		this->eps_growth = other.eps_growth ;
		this->return_on_equity = other.return_on_equity ;
		this->return_on_invested_capital = other.return_on_invested_capital ;	
		this->benjamin_graham_result = other.benjamin_graham_result ;

		other.name = "" ;
		other.total_revenue = 0 ;
		other.current_ratio = 0 ;
		other.p_e = 0 ;
		other.graham_multiplier = 0 ;
		other.eps_growth = 0 ;
		other.return_on_equity = 0 ;
		other.return_on_invested_capital = 0 ;
		other.benjamin_graham_result = 0 ;
    };
    
    return *this;  
}  

//Getters

string stock::get_name(){
	return this->name;
}

long stock::get_total_revenue(){
	return this->total_revenue;
}

float stock::get_current_ratio(){
	return this->current_ratio;
}
    
float stock::get_p_e(){
	return this->p_e;
}
    
float stock::get_graham_multiplier(){
	return this->graham_multiplier;
}
    
float stock::get_eps_growth(){
	return this->eps_growth;
}

float stock::get_return_on_equity(){
	return this->return_on_equity;
}

float stock::get_return_on_invested_capital(){
	return this->return_on_invested_capital;
}

float stock::get_benjamin_graham_result(){
	return this->benjamin_graham_result;
}




//Setters

void stock::set_name(string name){
	this->name = name;
}

void stock::set_total_revenue(float total_revenue){
	this->total_revenue= total_revenue;
}

void stock::set_p_e(float p_e){
	this->p_e = p_e;
}

void stock::set_graham_multiplier(float graham_multiplier){
	this->graham_multiplier = graham_multiplier ;
}

void stock::set_eps_growth(float eps_growth){
	this->eps_growth = eps_growth;
}
    
void stock::set_return_on_equity(float return_on_equity){
	this->return_on_equity = return_on_equity;
}

void stock::set_return_on_invested_capital(float return_on_invested_capital){
	this->return_on_invested_capital = return_on_invested_capital;
}

void stock::set_benjamin_graham_result(float benjamin_graham_result){
	this->benjamin_graham_result = benjamin_graham_result;
}

//Public functions

bool stock::operator<(stock const& other) const  {
  return ( benjamin_graham_result > other.benjamin_graham_result);
}

void stock::print_stock_fields(){
	cout<< "name of the stock: " << this->get_name() <<endl;
	cout<< "total_revenue: " << this->get_total_revenue() <<endl;;
    cout<< "current ratio: " << this->get_current_ratio() <<endl;
    cout<< "p/e: "<< this->get_p_e()<<endl;
    cout<< "graham_multiplier: "<< this->get_graham_multiplier()<<endl;;
    cout<< "eps_growth: "<< this->get_eps_growth()<<endl;
    cout<< "return_on_equity(): " << this->get_return_on_equity() <<endl;
    cout<< "return_on_invested_capial: " << this->get_return_on_invested_capital()<<endl;
    cout<< "benjamin_graham_result: " << this->get_benjamin_graham_result()<<endl;
}




