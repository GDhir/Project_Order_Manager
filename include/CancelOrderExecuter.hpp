#ifndef CancelOrderExecuterDefine
#define CancelOrderExecuterDefine

#include "OrderExecuterBase.hpp"
#include "InvalidInputException.hpp"
#include "Utils.hpp"

class CancelOrderExecuter: public OrderExecuterBase {

  public:

    virtual results_t executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) override;
    
};

#endif