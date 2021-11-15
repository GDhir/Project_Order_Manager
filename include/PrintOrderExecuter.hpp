#ifndef PrintOrderExecution
#define PrintOrderExecution

#include "OrderExecuterBase.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

/*The print order executer iterates over the multisets corresponding to
the buy side and the sell side to populate the output. The multisets contain
the order in price-time priority. 

As a result, the output is also visible in price-time (FIFO) priority */

class PrintOrderExecuter : public OrderExecuterBase
{

  std::string createOutput(const OrderDetails &details);

public:
  virtual results_t executeActions(BuyMultiset &buySet, SellMultiset &sellSet, BuyMap &buyMap, SellMap &sellMap, OrderDetails &orderDetails) override;
};

#endif