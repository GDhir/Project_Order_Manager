#ifndef ParseOrder
#define ParseOrder

#include <string>
#include "Utils.hpp"
#include <memory>
#include "InvalidInputException.hpp"

class OrderParser
{

  protected:

    void parseOrderID( const std::string& orderID, OrderDetails& details );

  public:

    virtual void parseDetails( const std::vector<std::string>& actionVal, OrderDetails& details ) = 0;

    void parseAction( const std::string& action, OrderDetails& details );

    OrderParser() = default;

    virtual ~OrderParser(){};

};

# endif