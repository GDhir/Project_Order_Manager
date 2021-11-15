#include "PlaceOrderParser.hpp"

void PlaceOrderParser::parseDetails(const std::vector<std::string> &actionVal, OrderDetails &details)
{

  if (actionVal.size() == 6)
  {
    parseOrderID(actionVal[1], details);
    details.symbol = actionVal[2];

    if (actionVal[3] == std::string(1, 'B') || actionVal[3] == std::string(1, 'S'))
    {
      details.orderType = actionVal[3][0];
    }
    else
    {
      throw InvalidInputException("InvalidOrderType");
    }

    if (isInteger(actionVal[4]))
    {
      details.orderQty = stoi(actionVal[4]);
    }
    else
    {
      throw InvalidInputException("InvalidOrderQty");
    }

    if (isFloat(actionVal[5]))
    {
      details.orderValue = stof(actionVal[5]);
    }
    else
    {
      throw InvalidInputException("InvalidOrderPx");
    }
  }
  else
  {

    throw InvalidInputException("InvalidOrderAction");
  }
}