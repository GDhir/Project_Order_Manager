#ifndef ExecuteOrder
#define ExecuteOrder

#include "Utils.hpp"
#include <memory>

class OrderExecuterBase {

  public:

    OrderExecuterBase() = default;

    virtual ~OrderExecuterBase(){};

    virtual results_t executeActions( BuyMultiset& buySet, SellMultiset& sellSet, BuyMap& buyMap, SellMap& sellMap, OrderDetails& orderDetails ) = 0;

};

#endif