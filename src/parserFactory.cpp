#include "parserFactory.hpp"

std::unique_ptr<OrderParser> parserFactory(char type)
{
  if (type == 'P')
  {
    return std::make_unique<PrintOrderParser>();
  }
  else if (type == 'X')
  {

    return std::make_unique<CancelOrderParser>();
  }
  else if (type == 'O')
  {

    return std::make_unique<PlaceOrderParser>();
  }
  else
  {

    throw "Invalid Input in parser factory";
  }
}