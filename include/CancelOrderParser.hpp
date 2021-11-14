#ifndef CancelParser
#define CancelParser

#include "OrderParser.hpp"
#include "InvalidInputException.hpp"
#include <vector>
#include <string>
#include "Utils.hpp"

class CancelOrderParser: public OrderParser {

  public:

    void parseDetails( const std::vector<std::string>& actionVal, OrderDetails& details ) override;

};

#endif