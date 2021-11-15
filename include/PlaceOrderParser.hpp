#ifndef ParsePlaceOrder
#define ParsePlaceOrder

#include "OrderParser.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

/*The place order parser parses the individual order details. 

When the order string contains an "O", the order is placed and the
PlaceOrderParser is used. The interface parses individual details to 
find if there is an issue. 

If no exception is thrown, the struct OrderDetails is successfully populated
with the details of the order. */

class PlaceOrderParser : public OrderParser
{

public:
  void parseDetails(const std::vector<std::string> &actionVal, OrderDetails &details);
};

#endif