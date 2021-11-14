#ifndef ParsePrintOrder
#define ParsePrintOrder

#include "OrderParser.hpp"
#include "Utils.hpp"
#include "InvalidInputException.hpp"

class PrintOrderParser: public OrderParser {

  public:

    void parseDetails( const std::vector<std::string>& actionVal, OrderDetails& details );


};

#endif