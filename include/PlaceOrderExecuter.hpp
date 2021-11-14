#ifndef PlaceOrder
#define PlaceOrder

#include "OrderExecuterBase.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

class PlaceOrderExecuter: public OrderExecuterBase {

  std::string createOutput( const OrderDetails& details );

  results_t executeSell(  BuyMultiset& buySet, BuyMap& buyMap, OrderDetails& orderDetails );
  results_t executeBuy( SellMultiset& sellSet, SellMap& sellMap, OrderDetails& orderDetails );
  
  public:

    virtual results_t executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) override;
    
};

#endif