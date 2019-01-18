/*
 * bag1.h
 *
 *  Created on: Nov 8, 2017
 *      Author: W520
 */
#include <cstdlib>
#include <iostream>

#ifndef BAG1_H_
#define BAG1_H_

namespace JONTRAN{
	class bag{

	public:

		friend std::ostream& operator<<(std::ostream&, const bag&);
		typedef float value_type;
		//bag::value_type is the data type of the items contained in the bag.
		typedef std::size_t size_type;
		//bag::size_type is the data type to keep track of the size of the bag.
		static const size_type DEFAULT_CAPACITY = 60;
		//The total capacity of the bag. however it can increased. but that is not needed.
		//The simulation only calls for 60 months.
		//CONSTRUCTOR
		bag(size_type initial_capacity = DEFAULT_CAPACITY);
		//bag is initialized as empty
		//DECONSTRUCTOR
		~bag();
		//Returns data to heap.
		void insert(const value_type entry);
		//Postcondition: An item is inserted into the array. USED is incremented by 1.
		//Account will be increased by 5 percent with each newly inserted entry.
		void insert_v2(const value_type entry);
		//Postcondition: An item is inserted into the array. USED is incremented by 1.
		//This function is used for the 2nd strategy.
		//Account will be increased by 5 percent with each newly inserted entry.
		void check_stock(const value_type& entry);
		//Postcondition:
		//If entry < 25. The stock will be decreased 5 percent. If entry > 75, then stock will be
		//increased 5 percent. If entry is >= 25 and <= 75, the stock will not be affected.
		//If stock is below 95 and Account is > 0. Then Shares = Account/Stock and Account = 0.
		//If stock is above 110 and Shares is > 0. Then Account = Shares*stock. and Shares = 0.
		void check_stock_v2(const value_type& entry);
		//Postcondition: If entry < 25. The stock will be decreased 5 percent. If entry > 75, then stock will be
		//increased 5 percent. If entry is >= 25 and <= 75, the stock will not be affected.
		//If stock is below 100 and Account is > 0. Then Shares = Account/Stock and Account = 0.
		//If stock is above 115 and Shares is > 0. Then Account = Shares*stock. and Shares = 0.
		void reserve(size_type new_capacity);
		//Postcondition: A new array will be created with size of new_capacity. data will copy array contents
		//to new array. Data will return to heap. and the new array will equal data.
  		void left_over_shares ();
  		//Postcondition: If shares > 0. Then Account = shares * stock. and Shares = 0.
  		//This function is only for the last month to insure we sell all stocks.
		size_type size()const{
			return used;
		}
		size_type account_size()const{
			return account;
		}
		value_type stock_price()const{
			return stock;
		}
		size_type total_shares()const{
			return shares;
		}


	private:
		value_type *data;
		value_type stock;
		value_type account;
		value_type shares;
 		size_type used;
		size_type capacity;
	};
}





#endif /* BAG1_H_ */
