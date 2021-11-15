#ifndef PlaceOrder
#define PlaceOrder

#include "OrderExecuterBase.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

/*Place order executer implements the executeActions interface to be able to execute
the order placement. 

There are two choices possible: 
  1. The order can be placed on the buy side by executeSell method. 
  2. The order can be placed on the sell side by executeBuy method.
  
The executeSell method then places the order by finding if there is a matching 
order preexisting on the buy side. 

If there is a matching order which has a higher price on the buy side, the order 
is implemented until the order is complete or there are no more orders on the buy 
side which have higher price than the sell side. The opposite functionality is 
implemented on the buy side.

*/

class PlaceOrderExecuter : public OrderExecuterBase
{

  std::string createOutput(const OrderDetails &details);

  results_t executeSell(BuyMultiset &buySet, BuyMap &buyMap, OrderDetails &orderDetails);
  results_t executeBuy(SellMultiset &sellSet, SellMap &sellMap, OrderDetails &orderDetails);

public:
  virtual results_t executeActions(BuyMultiset &buySet, SellMultiset &sellSet, BuyMap &buyMap, SellMap &sellMap, OrderDetails &orderDetails) override;
};

#endif