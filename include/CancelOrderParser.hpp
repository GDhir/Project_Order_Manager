#ifndef CancelParser
#define CancelParser

#include "OrderParser.hpp"
#include "InvalidInputException.hpp"
#include <vector>
#include <string>
#include "Utils.hpp"

/*The CancelOrderParser implements the parseDetails interface to parse the order tokens
when an order is cancelled. */

class CancelOrderParser : public OrderParser
{

public:
  void parseDetails(const std::vector<std::string> &actionVal, OrderDetails &details) override;
};

#endif