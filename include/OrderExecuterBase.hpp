#ifndef ExecuteOrder
#define ExecuteOrder

#include "Utils.hpp"
#include <memory>

/*The order executer base class is an abstract interface to be extended
  by derived classes which implement individual actions.
  
  The derived classes implement executeActions interface which specifies 
  how to execute individual orders

*/

class OrderExecuterBase
{

public:
  OrderExecuterBase() = default;

  virtual ~OrderExecuterBase(){};

  virtual results_t executeActions(BuyMultiset &buySet, SellMultiset &sellSet, BuyMap &buyMap, SellMap &sellMap, OrderDetails &orderDetails) = 0;
};

#endif