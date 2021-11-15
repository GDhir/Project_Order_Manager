#include "OrderParser.hpp"

void OrderParser::parseOrderID(const std::string &orderID, OrderDetails &details)
{
  if (isInteger(orderID))
  {
    details.orderID = std::stoi(orderID);
  }
  else
  {
    throw InvalidInputException("InvalidOrderID");
  }
}

void OrderParser::parseAction(const std::string &action, OrderDetails &details)
{
  if (action.size() != 1)
  {

    throw InvalidInputException("InvalidAction");
  }

  auto flag = (action[0] == 'P' || action[0] == 'X' || action[0] == 'O');

  if (flag)
  {
    details.action = action[0];
  }
  else
  {

    throw InvalidInputException("InvalidAction");
  }
}