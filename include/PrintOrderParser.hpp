#ifndef ParsePrintOrder
#define ParsePrintOrder

#include "OrderParser.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

/*The print order parser parses the individual tokens when the order string
asks to print the order details */

class PrintOrderParser : public OrderParser
{

public:
  void parseDetails(const std::vector<std::string> &actionVal, OrderDetails &details);
};

#endif