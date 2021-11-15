#ifndef CancelOrderExecuterDefine
#define CancelOrderExecuterDefine

#include "OrderExecuterBase.hpp"
#include "InvalidInputException.hpp"
#include "Utils.hpp"

/*The CancelOrderExecuter implements the executeActions interface to 
execute the cancellation of the order. It finds if there is an order corresponding to the 
OrderID in the buyMap or sellMap hash tables and cancels the corresponding orders if they exist. 

If the orders do not exist, an exception is thrown to the user. */

class CancelOrderExecuter: public OrderExecuterBase {

  public:

    virtual results_t executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) override;
    
};

#endif