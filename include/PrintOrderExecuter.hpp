#ifndef PrintOrderExecution
#define PrintOrderExecution

#include "OrderExecuterBase.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

class PrintOrderExecuter: public OrderExecuterBase {

    std::string createOutput( const OrderDetails& details );

  public:

    virtual results_t executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) override;
    
};

#endif