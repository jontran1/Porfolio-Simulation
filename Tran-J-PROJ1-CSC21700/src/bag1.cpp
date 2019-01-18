/*
 * bag1.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: W520
 */

#include "bag1.h"
#include <iostream>
#include <algorithm>
namespace JONTRAN{
const bag::size_type bag::DEFAULT_CAPACITY;

	bag::bag(size_type initial_capacity){
		data = new value_type[initial_capacity];
		capacity = initial_capacity;
		used = 0;
		account = 1000;
		stock = 100;
		shares = 0;
	}
	bag::~bag(){
		delete []data;
	}
	std::ostream& operator<<(std::ostream& out, const bag& b1){
		out<<"Account total: ";
		out<<b1.account<<std::endl;
		out<<"Stock price: ";
		out<<b1.stock<<std::endl;
		out<<"Number of shares ";
		out<<b1.shares<<std::endl;
 		return out;
	}

	void bag::reserve(size_type new_capacity){
		if(capacity == new_capacity){
			return;
		}
		if(new_capacity < used){
			new_capacity = used;
		}
		value_type *new_array;
		new_array = new value_type[new_capacity];
		std::copy(data, data+used,new_array);
		delete []data;
		data = new_array;
		capacity = new_capacity;
	}
	void bag::insert(const value_type target){
		const value_type interest = 1.005;
		if(used==capacity){
			reserve(used+1);
		}
  		data[used]=target;
		account*=interest;
		++used;
		check_stock(target);
 	}
	void bag::insert_v2(const value_type target){
		const value_type interest = 1.005;
		if(used==capacity){
			reserve(used+1);
		}
  		data[used]=target;
		account*=interest;
		++used;
		check_stock_v2(target);
 	}

	void bag::check_stock(const value_type& target){
		if(target<0.25){
 			stock*=0.95;
		}
		if(target>0.75){
			stock*=1.05;
		}
		if((account>0)&&(stock<95)){
			shares = account/stock;
			account = 0;
		}
		if((stock>110)&&(shares>0)){
			account=shares*stock;
			shares = 0;
		}

	}
	void bag::check_stock_v2(const value_type& target){
		if(target<0.25){
 			stock*=0.95;
		}
		if(target>0.75){
			stock*=1.05;
		}
		if((account>0)&&(stock<100)){
			shares = account/stock;
			account = 0;
		}
		if((stock>115)&&(shares>0)){
			account=shares*stock;
			shares = 0;
		}

	}
	void bag::left_over_shares (){
		if((shares > 0)){
			account = shares*stock;
			shares = 0;
		}
 	}



}


