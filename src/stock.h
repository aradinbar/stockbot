#include <iostream> 
using namespace std; 

class stock
{

public:
	//Constructors
    
    stock();
    stock(string name,long total_revenue, float current_ratio, float p_e, float graham_multiplier,float eps_growth
    	, float return_on_equity, float return_on_invested_capital);
    
    //Destructor

	~stock();

	//Copy consturctor.

	stock(const stock & other);

	//Copy assignment operator

	stock& operator=(const stock& other);

	//Move consturctor   

	stock(stock && other);

	//Move assignment operator

	stock& operator=(stock && other);    


    //Getters

    string get_name();
    long get_total_revenue();
    float get_current_ratio();
    float get_p_e();
    float get_graham_multiplier();
    float get_eps_growth();
    float get_return_on_equity();
    float get_return_on_invested_capital();
    float get_benjamin_graham_result();
    
    //Setters
    
    void set_name(string name);
    void set_total_revenue(float total_revenue);
    void set_p_e(float p_e);
    void set_graham_multiplier(float graham_multiplier);
    void set_eps_growth(float eps_growth);
    void set_return_on_equity(float return_on_equity);
    void set_return_on_invested_capital(float return_on_invested_capital);
    void set_benjamin_graham_result(float benjamin_graham_result);

    //Public functions
    bool operator<(stock const& other) const; 
    void print_stock_fields();


private:
	string name;
	long total_revenue ;
	float current_ratio ;
	float p_e ;
	float graham_multiplier ;
	float eps_growth ;
	float return_on_equity ;
	float return_on_invested_capital ;
	float benjamin_graham_result;

};


 
