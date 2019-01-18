#include <cstdlib>
#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include "bag1.h"
using namespace std;
using namespace JONTRAN;
 	int main()
	{
 		//Below is the random number generator seed, It uses time.
		unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
		std::default_random_engine e(seed);
		std::default_random_engine generator;
		//This shorten the long float values. It can be commented out for more accurate results.
		std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
 		std::uniform_real_distribution<float> distribution(0.0,1.0);

 		//The variables used for this simulation.
 		const float interest_savings = 1348.85;
 		const float Monte_carlo = 16577;
 		const int total_months = 60;
 		float success_rate = 0;
 		float average = 0;
 		float average_squared = 0;
  		float variance = 0;
		//I will be using a bag data structure. It will contain all the randomly generated
 		//values. With each value inserted with the insert function it will be
  		//counted as one month. There is another function within the insert function.
 		//This function is call check_stock. It will check each randomly generated number and
 		//based on that it will manipulate the stock price, number of shares, and account.
 		//The last function is left_over_shares. This function will sell all shares
 		//regardless of the stock price on the last month.
 		//Function pre and post conditions are in header file.
  		//Below is the first strategy.
 		for(int i = 0 ; i < Monte_carlo; i++){
			bag bag1;

				for(int j = 0 ; j < total_months; j++ ){
 					bag1.insert(distribution(e));
				}
			bag1.left_over_shares();

   			if(bag1.account_size()>interest_savings){
				++success_rate;
			}
 			average+=bag1.account_size();
 			average_squared+=(bag1.account_size()*bag1.account_size());

 		}
 		//Calculations for the averages, variances and standard deviation.
 		cout<<"This is the first strategy. "<<endl;
		success_rate/=Monte_carlo;
		average/=(Monte_carlo);
		variance=(average_squared/(Monte_carlo-1))-(average*average);
  		cout<<"The variance is "<<variance<<endl;
		cout<<"The stand deviation is "<<pow (variance, 0.5)<<endl;
		cout<<"Average(Expected Value): "<<average<<endl;
 		cout<<"Success rate is: "<<success_rate<<endl;

 		//This section of code is for the second strategy.
		success_rate = 0;
		average = 0;
		average_squared = 0;

 		for(int i = 0 ; i < Monte_carlo; i++){
			bag bag1;

				for(int j = 0 ; j < total_months; j++ ){
 					bag1.insert_v2(distribution(e));
				}
				bag1.left_over_shares();

			if(bag1.account_size()>interest_savings){
				++success_rate;
			}

  			average+=bag1.account_size();
  			average_squared+=(bag1.account_size()*bag1.account_size());
 		}

 		cout<<"\nThis is the second strategy. "<<endl;
		success_rate/=Monte_carlo;
		average/=(Monte_carlo);
		variance=(average_squared/(Monte_carlo-1))-(average*average);
  		cout<<"The variance is "<<variance<<endl;
		cout<<"The stand deviation is "<<pow (variance, 0.5)<<endl;
		cout<<"Average(Expected Value): "<<average<<endl;
 		cout<<"Success rate is: "<<success_rate<<endl;


}







